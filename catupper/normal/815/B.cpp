#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define MOD 1000000007

Int n, a[2160000];
Int frac[2160000];
Int invf[2160000];
Int inv[2160000];

Int init(){
  inv[1] = 1;
  invf[0] = 1;
  invf[1] = 1;
  frac[0] = 1;
  frac[1] = 1;
  for(int i = 2;i <216000;i++){
    frac[i] = frac[i-1] * i % MOD;
    inv[i] = -(MOD / i) * inv[MOD % i] % MOD;
    if(inv[i] < 0)inv[i] += MOD;
    invf[i] = invf[i-1] * inv[i] % MOD;
  }
}

Int C(Int n, Int k){
  return frac[n] * invf[k] % MOD * invf[n-k] % MOD;
}

Int solve(int n, int sgn){
  if(n == 1)return (a[0]%MOD+MOD)%MOD;
  if(n % 4 == 1){
    Int res = 0;
    for(int i = 0;i < n;i += 2){
      res += a[i] * C(n/2, i/2);
      res %= MOD;
    }
    return (res % MOD + MOD) % MOD ;
  }
  for(int i = 0;i < n-1;i++){
    (a[i] += sgn * a[i+1])%=MOD;
    sgn *= -1;
   }
  return solve(n-1, sgn);
}

int main(){
  init();
  cin >> n;
  for(int i = 0;i < n;i++)cin >> a[i];
  cout << solve(n, 1) << endl;
  return 0;
}