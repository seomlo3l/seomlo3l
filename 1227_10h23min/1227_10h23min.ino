#include <Bounce2.h>
#include <MsTimer2.h>

int butR = 2;
int butL = 3;
int ledR = 9;
int ledL = 10;

Bounce debouncerR = Bounce();
Bounce debouncerL = Bounce();

bool ledstate = LOW;

int butR_state=HIGH;
int butL_state=HIGH;


void setup() {
  pinMode(butR, INPUT_PULLUP);
  pinMode(butL, INPUT_PULLUP);
  
  debouncerR.attach(butR);
  debouncerR.interval(5);
  debouncerL.attach(butL);
  debouncerL.interval(5);

  MsTimer2::set(10,aa);
  MsTimer2::start();

  Serial.begin(9600);
}


void loop() {
  debouncerR.update();
  debouncerL.update();

  if(debouncerR.fell()){
    digitalWrite(ledR, HIGH);
  }
  else if (debouncerL.fell()){
    digitalWrite(ledL, HIGH);
  }
  if(debouncerR.rose()){
    digitalWrite(ledR, LOW);
  }
  else if (debouncerL.rose()){
    digitalWrite(ledL, LOW);
  }  
}

void aa(){
  if (digitalRead(butR)==0){
    Serial.println("RIGHT_ON");
  }
  else if (digitalRead(butL)==0){
    Serial.println("LEFT_ON");
  }
}
