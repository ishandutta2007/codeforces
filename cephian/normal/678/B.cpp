#include <iostream>

using namespace std;

bool leap(int y) {
  return y%4==0 && !(y%100==0 && y%400!=0);
}

int main() {
  int f = 0;
  int y,yp;
  cin >> y;
  yp = y;
  do {
    int a = 365;
    if(leap(yp)) ++a;
    f = (f + a)%7;
    ++yp;
  } while(f != 0 || (leap(y) != leap(yp)));
  cout << yp << "\n";
}