#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

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
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        int r=1;
        vector<ll> f(n+1,1);
        for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
        vector<ll> finv(n+1,1);
        finv[n]=fpow(f[n],mod-2);
        for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
        auto c=[&](int d,int e)->ll
        {
            ll res=f[d];
            res=(res*finv[e])%mod;
            res=(res*finv[d-e])%mod;
            return res;
        };
        ll res=0;
        for(int l=1;l<=n;l++)
        {
            while(r+1<=n&&a[r+1]<=a[l]+k) r++;
            if(r-l>=m-1) res=(res+c(r-l,m-1))%mod;
        }
        cout << res << "\n";
    }
    return 0;
}