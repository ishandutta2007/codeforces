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
    int n,k;
    cin >> n >> k;
    vector<ll> f(n+1,1);
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(n+1,1);
    finv[n]=fpow(f[n],mod-2);
    for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto c=[&](int a,int b)->ll
    {
        ll res=f[a];
        res=(res*finv[b])%mod;
        res=(res*finv[a-b])%mod;
        return res;
    };
    vector<array<int,2>> v; //1-add 2-rm
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin >> l >> r;
        v.push_back({l,1});
        v.push_back({r,2});
    }
    sort(v.begin(),v.end());
    ll res=0;
    int now=0;
    for(auto [x,t]:v)
    {
        if(t==1)
        {
            if(now>=k-1) res=(res+c(now,k-1))%mod;
            now++;
        }
        else now--;
    }
    cout << res << "\n";
    return 0;
}