#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> d(n+1,0);
    for(int i=1;i<=n;i++) cin >> d[i];
    sort(d.begin(),d.end());
    vector<ll> sum(n+1,0);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+d[i];
    auto mul=[](ll &a,ll b){a=(a*b)%mod;};
    vector<ll> f(n+1,1);
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(n+1,1);
    finv[n]=fpow(f[n],mod-2);
    for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto c=[&](int a,int b)->ll
    {
        ll res=f[a];
        mul(res,finv[b]);
        mul(res,finv[a-b]);
        return res;
    };
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        int l=0,r=n+1;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(d[mid]>=b) r=mid;
            else l=mid;
        }
        int c0=l;
        int c1=n-c0;
        ll s0=(sum[l])%mod;
        ll s1=(sum[n]-s0)%mod;
        ll res=0;
        if(c1>=a)
        {
            ll one=c1-a;
            mul(one,f[c1-1]);
            mul(one,c(n,c1));
            mul(one,f[c0]);
            mul(one,s1);
            ll zero=0;
            if(c0>0)
            {
                zero=f[c1];
                mul(zero,c1-a+1);
                mul(zero,s0);
                mul(zero,c(n,c0-1));
                mul(zero,f[c0-1]);
            }
            res=(one+zero)%mod;
        }
        mul(res,finv[n]);
        cout << res << "\n";
    }
    return 0;
}