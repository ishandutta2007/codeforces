#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
ll inv[maxn],fac[maxn],dp[maxn],sum[maxn];
const int mod =1e9+7;

ll qpower(ll a,ll b){
  ll res = 1;
  while(b)
  {
    if(b&1)res = res*a%mod;
    b>>=1;
    a= a*a%mod;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  ll n,k;
  cin>>n>>k;
  if(k+1>=n)
  {
    printf("0\n");
    exit(0);
  }
  fac[0] = 1;
  for(int i=1;i<=n;i++){
    fac[i] = fac[i-1]*i%mod;
  }
  inv[n] = qpower(fac[n],mod-2);
  for(int i=n-1;i>=0;i--){
    inv[i] = inv[i+1] * (i+1) %mod;
  }
  dp[1] = sum[1] = 1;
  ll ans = fac[n-1];
  for(int i=2;i<=n;i++){
    dp[i] = (sum[i-1] - sum[max(0LL,i-k-1)]) *fac[i-2] %mod;
    sum[i] = (sum[i-1] + dp[i] * inv[i-1]) % mod;
    ans = (ans + dp[i] * fac[n-1] %mod * inv[i-1])%mod;
  }
  cout<<(fac[n]-ans+mod)%mod<<endl;
  return 0;
}