#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 2345;
// ll n , L;
// string ss[123][456];
// int L[123][456];
// string sss;
std::vector<pair<int,int> > v;
// ll a[maxn];
// int t[maxn];
// int res[maxn];
// int tmp[maxn];
// int ans,last;
ll tmp[maxn];
ll inva[maxn];
ll invb[maxn];
ll dp[maxn][maxn];
ll ans[maxn];
ll qpower(ll a,ll b,ll mod)
{
    long long ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int n;
int a,b;
ll invab;
int main(int argc, char const *argv[]) {
 /* code */
  // std::cout << "begin" << '\n';
 std::cin >> n;
 std::cin >> a >> b;
 invab = a * qpower(b,mod-2,mod)%mod;
 inva[0]=1;invb[0]=1;
 for(int i=0;i<=n;i++) {
   inva[i+1]=inva[i]*invab % mod;
   invb[i+1]=invb[i]*(mod-invab+1)%mod;
 }
 dp[1][1]=1;dp[1][0]=1;
 for(size_t i=1;i<=n;i++) {
    /* code */
   for(size_t j=0;j<=i;j++) {
      /* code */
     dp[i+1][j]=dp[i+1][j]+dp[i][j]*inva[j]%mod; dp[i+1][j]%=mod;
     dp[i+1][j+1]=dp[i+1][j+1]+1LL*dp[i][j]*invb[i-j]%mod; dp[i+1][j+1]%=mod;
   }
    // std::cout << "dp=" << dp[i] << '\n';
 }
 // std::cout << dp[n] << '\n';
 ans[1]=0;tmp[1] = 1;
 for(size_t i=2;i<=n;i++)
 {
    /* code */
   ans[i]=i*(i-1)>>1;
   for(size_t j=1;j<i;j++)
   {
      /* code */
     tmp[i]=tmp[i]+1LL*dp[i][j]*1LL*tmp[j]%mod;tmp[i]%=mod;
     ans[i]=ans[i]+1LL*dp[i][j]*1LL*tmp[j]%mod*1LL*(ans[i-j]+ans[j]+mod-(1LL*(i-j)*(i-j-1)>>1))%mod;
     ans[i]%=mod;
   }
  // std::cout << "ans=" << ans[i] << '\n';
   ans[i]=ans[i]*qpower(tmp[i],mod-2,mod);ans[i]%=mod;
   tmp[i]=mod+1-tmp[i];tmp[i]%=mod;
 }
 std::cout << ans[n] << '\n';
 cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}