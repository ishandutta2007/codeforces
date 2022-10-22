#include <bits/stdc++.h>
using namespace std;
long long fac(int x){
  if(x == 0){
    return 1;
  }
  return fac(x - 1) * x;
}
int main(){
  int a;
  cin >> a;
  cout << fac(a + a - 2) / (fac(a - 1) * fac(a - 1));
}