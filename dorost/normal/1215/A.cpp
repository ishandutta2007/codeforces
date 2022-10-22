// in the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  if((c >= d) && (e < (d-1)*b)){
    cout << 0;
  }else if((d > c) && e < (c-1)*a){
    cout << 0;
  }else if((e <= ((a*(c-1))+(b*(d-1))))){
    cout << 0;
  }else if(e >= ((a*c)+(b*d))){
    cout << a + b;
  }else{
    cout << e - ((a*(c-1))+(b*(d-1)));
  }
  cout << " ";
  if((c >= d) && e < (d*b)){
    cout << e / d;
  }else if((d > c) && e < (c*a)){
    cout << e / c;
  }else if((c >= d) && (e < ((a*c)+(b*d)))){
    cout << b +((e-(d*b))/c);
  }else if((d > c) && (e < ((a*c)+(b*d)))){
    cout << a +((e-(a*c))/d);
  }else{
    cout << a+b;
  }
}