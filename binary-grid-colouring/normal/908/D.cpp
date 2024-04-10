#include<bits/stdc++.h>

using namespace std;
const int maxn = 2000;
const double eps = 1e-9;
const int mod = 1e9+7;
typedef long long ll;

ll qpower(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
ll dp[2100][2100];
int main(int argc, char const *argv[]) {
  /* code */
  ll k,pa,pb;
  std::cin >> k >> pa >> pb;
  ll inb = qpower(pb,mod-2,mod);
  ll inc = qpower(pa+pb,mod-2,mod);
  dp[1][0] =1;
  ll ans = 0;
  for(int i=1;i<k;i++) {
    for (size_t j = 0; j < k; j++) {
      /* code */
      dp[i][j+i] = (dp[i][i+j] + dp[i][j]*pb%mod*inc%mod) % mod;
      dp[i+1][j] = (dp[i+1][j] + dp[i][j]*pa%mod*inc%mod) % mod;
    }
    for(int kk=k;kk<=k*2;kk++) {
      ans = (ans + dp[i][kk] * kk) % mod;
    }
  }
  //std::cout << "ans=" << ans << '\n';
  ll res = 0;
  for(int i=0;i<k;i++) {
    res = (pa+pb*(i+k) % mod)*inb % mod;
    ans = (ans + res * dp[k][i]) % mod;
    //std::cout << "ans=" << ans << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}