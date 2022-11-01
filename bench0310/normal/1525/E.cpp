#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> f(n+1,1);
    vector<ll> inv(n+1,1);
    vector<ll> finv(n+1,1);
    for(int i=2;i<=n;i++)
    {
        f[i]=mul(f[i-1],i);
        inv[i]=mod-mul(mod/i,inv[mod%i]);
        finv[i]=mul(finv[i-1],inv[i]);
    }
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    ll res=0;
    for(int i=1;i<=m;i++)
    {
        vector<int> c(n+2,0);
        for(int j=1;j<=n;j++) c[n-a[j][i]+2]++;
        int cnt=0;
        ll now=1;
        for(int j=1;j<=n;j++)
        {
            cnt+=c[j];
            now=mul(now,cnt);
            cnt--;
        }
        res=add(res,mul(sub(f[n],now),finv[n]));
    }
    cout << res << "\n";
    return 0;
}