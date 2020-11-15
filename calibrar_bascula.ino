#include "HX711.h"
const int DOUT=A0;
const int CLK=A1;

//1 Encender el sistema sin peso con la estructura final
//2 Anotar el valor después de 1 minuto, ese es el offset
//3 Poner el peso 
//4 Calcular escala = (valorMedido-offset)/(Peso U)
//5 Modificar los datos de escala y offset en el programa principal

HX711 balanza;
void setup() {
  Serial.begin(9600);
  balanza.begin(DOUT, CLK);
  Serial.print("Lectura del valor del ADC:t");
  Serial.println(balanza.read());
  Serial.println("No ponga ningún objeto sobre la balanza");
  Serial.println("Destarando...");
  balanza.set_scale(); //La escala por defecto es 1
  balanza.tare(20);  //El peso actual es considerado Tara.
  Serial.println("Coloque un peso conocido:");
}

void loop() {

  Serial.print("Valor de lectura: t");
  Serial.println(balanza.get_value(10),0);
  delay(100);
}
