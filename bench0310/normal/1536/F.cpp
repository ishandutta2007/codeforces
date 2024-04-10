#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
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
    auto c=[&](int a,int b)->ll
    {
        if(a<0||b<0||a<b) return 0;
        return mul(f[a],mul(finv[b],finv[a-b]));
    };
    auto g=[&](int a,int b)->ll{return c(a-(b-1),b);};
    vector<ll> opt(n+1,0);
    opt[0]=1;
    for(int i=1;i<=n;i++) opt[i]=add(g(n-3,i-1),g(n-1,i));
    ll res=0;
    for(int h=(n&1);h<=n;h+=2)
    {
        res=add(res,2*mul(f[n-h],opt[h]));
    }
    cout << res << "\n";
    return 0;
}