#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 500005
#define mod ((ll)(998244353))

ll fact[MAXN],ifact[MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

ll comb(ll n,ll m)
{
    ll num=fact[n];
    ll den=(ifact[m]*ifact[n-m])%mod;
    return (num*den)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0]=1;
    ifact[0]=1;
    for(ll i=1;i<MAXN;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        ifact[i]=qp(fact[i],mod-2);
    }

    ll n,k;
    cin >> n >> k;
    ll res=0;
    for(ll i=1;i<=n;i++)
    {
        ll ds=(n/i)-1;
        if(ds>=(k-1))
            res=(res+comb(ds,k-1))%mod;
    }
    db(res)

    return 0;
}