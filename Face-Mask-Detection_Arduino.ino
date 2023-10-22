#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

LiquidCrystal lcd(4, 5, 6, 7, 8,9);

const int buzzer_Pin = 11;
const int green_led = 12;
const int red_led = 13;
// const int temp_pin = A0;
//float temperature;
char face_status = 0;
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);  
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  pinMode(buzzer_Pin, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  
  lcd.begin(16, 2);
  lcd.print("Face Mask");
  lcd.setCursor(0,2);
  lcd.print(" Detection");
  delay(2000); 
  myservo.write(30);
  delay(2000);
}
void loop() {
  digitalWrite(red_led, LOW); 
  digitalWrite(buzzer_Pin, LOW);
  digitalWrite(green_led, LOW); 
  lcd.clear();
  lcd.print("Scan Your face");
  delay(100);
  while (Serial.available() > 0) 
  {
    face_status = Serial.read();
    // if(face_status == 'a')
    // { 
    //   lcd.clear();
    //   delay(100);
    //    lcd.print("Masked Detected");
    // //   lcd.setCursor(0,2);
    //   lcd.print("Read Temperature");
    //   delay(1000);
  
    //  temperature = analogRead(temp_pin);
  //    temperature= ( temperature/1024.0)*5000; 
  //    temperature = temperature/10;
  //    Serial.print("Temperature value = ");
  //    Serial.println(temperature);
  //    lcd.clear();
  //    delay(100);
  //    lcd.print("Temperature = ");
  //    lcd.setCursor(0,2);
  //    lcd.print(temperature);
  //    delay(1000);
  //    if(temperature > 40)
  //    {
  //      lcd.clear();
  //      delay(100);
  //      lcd.print("Body Temperature High");
  //      lcd.setCursor(0,2);
  //      lcd.print("Gate Closed");   
  //      delay(1000);
  //      digitalWrite(buzzer_Pin, HIGH);
  //      digitalWrite(red_led, HIGH); 
  //      digitalWrite(green_led, LOW);
  //      delay(1000);
  //      digitalWrite(buzzer_Pin, LOW);
  //   }
  //   else
  //   {
  //     lcd.clear();
  //     delay(100);
  //     lcd.print("Gate Open"); 
  //     delay(1000);
  //     digitalWrite(buzzer_Pin, LOW); 
  //     digitalWrite(green_led, HIGH);
  //     digitalWrite(red_led, LOW); 
  //     delay(1000);
  //     myservo.write(120); 
  //     delay(1000);
  //     myservo.write(30);
  //     delay(100);
  //  }
  // }
  if(face_status == 'b')
  {
    //Serial.print("Face Mask Detection");
     lcd.clear();
     delay(100);
     //Serial.println("No mask detected");
     //Serial.println("Gate Closed");

     lcd.print("No mask detected");
     //lcd.setCursor(0,2);
     //lcd.print("detected");   
     delay(100);
     digitalWrite(buzzer_Pin, HIGH);
     digitalWrite(red_led, HIGH); 
     digitalWrite(green_led, LOW);
     delay(100);
     digitalWrite(buzzer_Pin, LOW);
  }
  else
  {
    /* Do nothing */
    lcd.clear();
     delay(100);
    // Serial.println(" mask detected");
      lcd.print("Masked Detected");
      delay(100);
      lcd.clear();
      //Serial.println("Gate Open"); 
      lcd.print("Gate Open"); 
      delay(100);
      digitalWrite(buzzer_Pin, LOW); 
      digitalWrite(green_led, HIGH);
      digitalWrite(red_led, LOW); 
      delay(100);
      myservo.write(120); 
      delay(100);
      myservo.write(30);
      delay(100);
  }
 }  
}
