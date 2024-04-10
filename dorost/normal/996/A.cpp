#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b=0;
  cin >> a;
  b+=a/100;
  a=a%100;
  b+=a/20;
  a=a%20;
  b+=a/10;
  a=a%10;
  b+=a/5;
  a=a%5;
  b+=a;
  cout<<b;
}