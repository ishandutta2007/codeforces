#include<bits/stdc++.h>
using namespace std;
int a,b,ans;
int main(){
  cin >> a >> b;
  while (a < b){
    a *= 2;
    ++ans;
  }
  int t = ans;
  a -= b;
  for (int i = 0; i < t; ++i){
    if (a & (1 << i)){
      ++ans;
      a -= (1 << i);
    }
  }
  cout << ans + a/(1 << t);
}