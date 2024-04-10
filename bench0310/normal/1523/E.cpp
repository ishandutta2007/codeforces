#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=100000;
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> f(N+1,1);
    vector<ll> inv(N+1,1);
    vector<ll> finv(N+1,1);
    for(int i=2;i<=N;i++)
    {
        f[i]=mul(f[i-1],i);
        inv[i]=mod-mul(mod/i,inv[mod%i]);
        finv[i]=mul(finv[i-1],inv[i]);
    }
    auto c=[&](ll a,int b)->ll
    {
        if(a<0||b<0||a<b) return 0;
        return mul(f[a],mul(finv[b],finv[a-b]));
    };
    auto fpow=[&](ll b,ll e)->ll
    {
        ll res=1;
        while(e)
        {
            if(e&1) res=mul(res,b);
            b=mul(b,b);
            e/=2;
        }
        return res;
    };
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        ll res=1;
        for(int i=1;i<n;i++)
        {
            res=add(res,mul(c(n-ll(i-1)*(k-1),i),fpow(c(n,i),mod-2)));
        }
        cout << res << "\n";
    }
    return 0;
}