#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005
#define mod ((ll)(998244353))

ll fac[MAXN],ifac[MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return (b!=0);
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

ll c(ll n,ll m)
{
    ll num=fac[n];
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (num*den)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fac[0]=1;
    ifac[0]=1;
    for(ll i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }

    ll n,k;
    cin >> n >> k;
    if(k==0)
        db(fac[n])
    else if(k>n-1)
        db(0)
    else
    {
        ll res=(2*c(n,k))%mod;
        ll f1=qp(n-k,n);
        for(int i=1;i<n-k;i++)
        {
            if(i&1)
                f1=(f1-((c(n-k,i)*qp(n-k-i,n))%mod)+mod)%mod;
            else
                f1=(f1+((c(n-k,i)*qp(n-k-i,n))%mod)+mod)%mod;

        }
        res=(res*f1)%mod;
        db(res)
    }

    return 0;
}
/**
1337 42
**/