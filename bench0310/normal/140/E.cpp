#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    ll mod;
    cin >> n >> m >> mod;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    const int L=5000;
    vector<vector<ll>> opt(L+1,vector<ll>(L+1,0));
    opt[0][0]=1;
    for(int i=0;i<L;i++)
    {
        for(int j=0;j<=i;j++)
        {
            //add an existing color
            if(j>0) opt[i+1][j]=add(opt[i+1][j],mul(j-1,opt[i][j]));
            //add a new color
            if(j<m) opt[i+1][j+1]=add(opt[i+1][j+1],opt[i][j]);
        }
    }
    vector<ll> p(L+1,1);
    for(int i=1;i<=L;i++) p[i]=mul(p[i-1],m-i+1);
    vector<ll> f(L+1,1);
    for(int i=1;i<=L;i++) f[i]=mul(f[i-1],i);
    vector<array<ll,2>> dp(1,{1,0});
    int pl=0;
    for(int i=1;i<=n;i++)
    {
        int l;
        cin >> l;
        vector<array<ll,2>> ndp(l+1,{0,0});
        ll sum=0;
        for(int j=0;j<=pl;j++) sum=add(sum,dp[j][0]);
        for(int j=1;j<=l;j++)
        {
            if(j<=pl) sum=add(sum,sub(dp[j][1],dp[j][0]));
            ndp[j][0]=mul(sum,mul(p[j],opt[l][j]));
            ndp[j][1]=mul(sum,mul(sub(p[j],f[j]),opt[l][j]));
            if(j<=pl) sum=add(sum,sub(dp[j][0],dp[j][1]));
        }
        dp=ndp;
        pl=l;
    }
    ll res=0;
    for(int i=1;i<=pl;i++) res=add(res,dp[i][0]);
    cout << res << "\n";
    return 0;
}