// This #include statement was automatically added by the Particle IDE.
#include "SparkFunMicroOLED/SparkFunMicroOLED.h" //this is the library for the OLED
#define PIN_RESET D6  // Connect RST to pin 6
#define PIN_DC    D5  // Connect DC to pin 5 (required for SPI)
#define PIN_CS    A2 // Connect CS to pin A2 (required for SPI)
MicroOLED oled(MODE_SPI, PIN_RESET, PIN_DC, PIN_CS);
int sens = D3;
int LED = D7;
int buzzerPin = D2;
bool sent = 0; // right now the fact that the message has been sent is false 

//MicroOLED oled(MODE_SPI, PIN_RESET, PIN_DC, PIN_CS);
//build.particle.io/build/57583a01aa0ceee8e8000872#verify

void setup() {
    pinMode(sens, INPUT_PULLUP);
    pinMode(LED, OUTPUT);https:
    oled.begin();
    oled.setFontType(0);
    oled.clear(PAGE);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    delay(2000);
    int sensState = digitalRead(sens);

    if ((sensState == LOW)&&(sent == 0)){
        digitalWrite(LED, HIGH);
    Particle.publish("sensState", "SensorOff", 60, PRIVATE);
    delay(500);
        sent = 1; // now the fact that the message was sent is true 
        oled.clear(PAGE);
        oled.setCursor(0 , 20);
        oled.print("Triggered");
        oled.display();
        
        int qNote = 800;
        tone(buzzerPin, 392, qNote);
        delay(qNote);
        delay(2000);        //https://build.particle.io/build/57583a01aa0ceee8e8000872#verify
}

else{
    digitalWrite(LED, LOW);
    sent = 0;
    oled.clear(PAGE);
    oled.setCursor(20 , 20);
    oled.print("Ready");
    oled.display();
    delay(1000);
}
}