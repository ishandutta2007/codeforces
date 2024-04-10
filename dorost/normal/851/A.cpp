#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(c >= b && c <= a){
    cout << b;
    return 0;
  }
  if(c > a){
    cout << b - (c - a);
    return 0;
  }
  if(c < b){
    cout << c;
  }
}