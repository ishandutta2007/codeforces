#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n++;
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> f(n+1,0);
    vector<ll> g(n+1,0);
    f[1]=1;
    ll s=0;
    for(int i=2;i<=n;i++)
    {
        s=add(s,f[i-2]);
        f[i]=add(mul(f[i-1],add(s,1)),f[i-1]*(f[i-1]+1)/2);
        g[i]=sub(f[i],f[i-1]);
    }
    const ll inv6=166374059;
    ll res=0;
    res=add(res,f[n-1]);
    res=add(res,mul(s,f[n-1]));
    res=add(res,f[n-1]*(f[n-1]+1)/2);
    res=add(res,mul(f[n-1],(s*(s+1)/2)%mod));
    res=add(res,mul(s,(f[n-1]*(f[n-1]+1)/2)%mod));
    res=add(res,mul(mul(f[n-1],f[n-1]+1),mul(f[n-1]+2,inv6)));
    res=sub(2*res,1);
    for(int i=2;i<=n-2;i++) res=add(res,mul(g[i],sub(f[n-i],1)));
    cout << res << "\n";
    return 0;
}