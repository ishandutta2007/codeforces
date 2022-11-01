#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin >> c;
        if(c=='-') v[i]=-1;
        else cin >> v[i];
    }
    ll res=0;
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    for(int i=1;i<=n;i++) if(v[i]!=-1) res=add(res,v[i]);
    vector<ll> p(n+1,1);
    for(int i=1;i<=n;i++) p[i]=mul(p[i-1],2);
    res=mul(res,p[n-1]);
    for(int o=1;o<=n;o++)
    {
        if(v[o]==-1) continue;
        vector<bool> bad(n+1,0);
        for(int i=1;i<=n;i++) bad[i]=(v[i]!=-1&&((i<o&&v[i]<=v[o])||(i>o&&v[i]<v[o])));
        vector<ll> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(i==o) continue;
            vector<ll> ndp(n+1,0);
            if(i>o&&v[i]==-1) res=sub(res,mul(mul(v[o],dp[0]),p[n-i]));
            for(int j=0;j<=n;j++)
            {
                if(v[i]==-1)
                {
                    if(i<o) ndp[max(j-1,0)]=add(ndp[max(j-1,0)],dp[j]);
                    else if(j>0) ndp[j-1]=add(ndp[j-1],dp[j]);
                    ndp[j]=add(ndp[j],dp[j]);
                }
                if(v[i]!=-1)
                {
                    if(bad[i]==1)
                    {
                        if(j<n) ndp[j+1]=add(ndp[j+1],dp[j]);
                        ndp[j]=add(ndp[j],dp[j]);
                    }
                    else ndp[j]=add(ndp[j],mul(2,dp[j]));
                }
            }
            dp=ndp;
        }
    }
    cout << res << "\n";
    return 0;
}