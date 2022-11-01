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
    int n,x,pos;
    cin >> n >> x >> pos;
    int a=0,b=0; //smaller,bigger
    int l=0,r=n;
    while(l<r)
    {
        int m=(l+r)/2;
        if(m==pos) l=m+1;
        else if(l<=pos+1&&pos+1<=m)
        {
            b++;
            r=m;
        }
        else
        {
            a++;
            l=m+1;
        }
    }
    auto zero=[]()
    {
        cout << "0\n";
        exit(0);
    };
    if(x-1<a||n-x<b) zero();
    vector<ll> f(n+1,1);
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(n+1,1);
    finv[n]=fpow(f[n],mod-2);
    for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto ch=[&](int c,int d)->ll
    {
        ll res=f[c];
        res=(res*finv[d])%mod;
        res=(res*finv[c-d])%mod;
        return res;
    };
    ll res=ch(x-1,a);
    res=(res*f[a])%mod;
    res=(res*ch(n-x,b))%mod;
    res=(res*f[b])%mod;
    res=(res*f[n-1-a-b])%mod;
    cout << res << "\n";
    return 0;
}