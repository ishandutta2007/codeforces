#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
char op[3];
int main(){
  int a, initial = 0;
  cin >> a;
  for(int i = 0; i < a; i++){
    for(int j = 0; j < 3; j++){
      cin >> op[j];
      }
    if(op[1] == '+'){
      initial++;
    }
    else if(op[1] == '-'){
      initial--;
    }
  }
  cout << initial << endl;
  return 0;
}