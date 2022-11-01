#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fpow(ll b,ll e,ll mod)
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
    const ll mod=1000003;
    ll n,k;
    cin >> n >> k;
    if(n<=60&&(k>(1ll<<n)))
    {
        cout << "1 1\n";
        return 0;
    }
    ll p=0;
    for(ll i=1;i<=min(n,60ll);i++) p=(p+((k+(1ll<<i)-1)/(1ll<<i)))%(mod-1);
    p=(p+max(0ll,n-60))%(mod-1);
    ll x=fpow(fpow(2,mod-2,mod),p,mod);
    ll a=1;
    ll s=fpow(2,n,mod);
    if(k>=mod) a=0;
    else for(ll i=s;i>=s-k+1;i--) a=(a*i)%mod;
    a=(a*x)%mod;
    ll b=fpow(2,(n%(mod-1))*(k%(mod-1)),mod);
    b=(b*x)%mod;
    cout << ((b-a+mod)%mod) << " " << b << "\n";
    return 0;
}