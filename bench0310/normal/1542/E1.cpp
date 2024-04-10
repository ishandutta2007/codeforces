#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll mod;
    cin >> n >> mod;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector c(n+1,vector(n+1,ll(0)));
    for(int i=0;i<=n;i++) c[i][0]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=add(c[i-1][j],c[i-1][j-1]);
    vector<ll> f(n+1,1);
    for(int i=1;i<=n;i++) f[i]=mul(f[i-1],i);
    vector dp(n+1,vector(n*(n-1)/2+1,ll(0)));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=i*(i-1)/2;j++)
        {
            dp[i][j]=sub(add(dp[i-1][j],dp[i][j-1]),(j>=i?dp[i-1][j-i]:0));
        }
    }
    vector dp2(n+1,vector(n*(n-1)/2+1,ll(0))); //number of (p,q) of length i with inv(p)-inv(q)>=j
    for(int i=1;i<=n;i++)
    {
        int mx=i*(i-1)/2;
        for(int j=mx;j>=0;j--)
        {
            if(j<mx) dp2[i][j]=dp2[i][j+1];
            for(int k=0;k+j<=mx;k++)
            {
                dp2[i][j]=add(dp2[i][j],mul(dp[i][k],dp[i][j+k]));
            }
        }
    }
    ll res=0;
    for(int match=0;match<=n-2;match++)
    {
        int len=n-match;
        ll opt=mul(c[n][match],f[match]);
        ll t=0;
        for(int d=1;d<=len-1;d++)
        {
            int cnt=len-d;
            t=add(t,mul(cnt,dp2[len-1][d+1]));
        }
        res=add(res,mul(opt,t));
    }
    cout << res << "\n";
    return 0;
}