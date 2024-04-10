#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define MOD 998244353

int main(){
  Int ans = 1;
  Int fact = 1;
  Int n;
  cin >> n;
  for(int i = 2;i <= n;i++){
    ans = i * ((ans + fact - 1) % MOD) % MOD;
    fact = fact * i % MOD;
  }
  cout << ans << endl;
  return 0;
}