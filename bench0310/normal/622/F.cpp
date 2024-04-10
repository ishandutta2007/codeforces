#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,k;
    cin >> x >> k;
    int n=k+2;
    const ll mod=1000000007;
    auto add=[&](ll a,ll b){return (a+b)%mod;};
    auto sub=[&](ll a,ll b){return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b){return (a*b)%mod;};
    auto fpow=[&](ll b,ll e)
    {
        ll r=1;
        while(e)
        {
            if(e&1) r=mul(r,b);
            b=mul(b,b);
            e/=2;
        }
        return r;
    };
    vector<ll> inv(n+1,1);
    vector<ll> finv(n+1,1);
    for(int i=2;i<=n;i++)
    {
        inv[i]=mod-mul(mod/i,inv[mod%i]);
        finv[i]=mul(finv[i-1],inv[i]);
    }
    vector<ll> y(n+1,0);
    for(int i=1;i<=n;i++) y[i]=add(y[i-1],fpow(i,k));
    vector<ll> one(n+1,1);
    for(int i=1;i<=n;i++) one[i]=mul(one[i-1],sub(x,i));
    vector<ll> two(n+2,1);
    for(int i=n;i>=1;i--) two[i]=mul(two[i+1],sub(x,i));
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll t=mul(one[i-1],two[i+1]);
        t=mul(t,mul(finv[i-1],finv[n-i]));
        if((n-i)&1) t=sub(0,t);
        res=add(res,mul(t,y[i]));
    }
    cout << res << "\n";
    return 0;
}