#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    int m,k;
    cin >> m >> k;
    int n=2*k;
    vector<ll> f(n+1,1);
    vector<ll> inv(n+1,1);
    vector<ll> finv(n+1,1);
    for(int i=2;i<=n;i++)
    {
        f[i]=mul(f[i-1],i);
        inv[i]=(mod-mul(mod/i,inv[mod%i]));
        finv[i]=mul(finv[i-1],inv[i]);
    }
    vector<ll> fbig(n+1,1); //m*(m-1)*..*(m-i+1)
    for(int i=1;i<=n;i++) fbig[i]=mul(fbig[i-1],m-i+1);
    auto c=[&](int a,int b)->ll{return mul(f[a],mul(finv[b],finv[a-b]));};
    auto cbig=[&](int b)->ll{return mul(fbig[b],finv[b]);};
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>0) dp[i][j]=add(dp[i][j],mul(i-1,dp[i-1][j-1]));
        }
    }
    vector<vector<ll>> ndp(n+1,vector<ll>(k+1,0));
    ndp[0][0]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            ll &t=ndp[i][j];
            for(int x=0;x<=i;x++)
            {
                ll r=mul(c(i,x),dp[i-x][j]);
                if((x%2)==0) t=add(t,r);
                else t=sub(t,r);
            }
        }
    }
    vector<ll> opt(k+1,0);
    for(int j=0;j<=k;j++)
    {
        for(int i=0;i<=n;i++)
        {
            opt[j]=add(opt[j],mul(cbig(i),ndp[i][j]));
        }
    }
    for(int j=1;j<=k;j++)
    {
        if(j>1) opt[j]=add(opt[j],opt[j-2]);
        cout << opt[j] << " \n"[j==k];
    }
    return 0;
}