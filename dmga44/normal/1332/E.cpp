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
#define MAXN 32005
#define mod ((ll)998244353)

ll fac[MAXN],ifac[MAXN];

ll comb(ll n,ll m)
{
    ll num=fac[n];
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (num*den)%mod;
}

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

pii solve(ll x,ll c1,ll c0)
{
    ll r0=0,r1=0;
    if(x<MAXN)
    {
        for(int i=0;i<=x;i+=2)
        {
            ll add=(comb(x,i)*qp(c1,i))%mod;
            add=(add*qp(c0,x-i))%mod;
            r0=(r0+add)%mod;
        }
        r1=(qp(c1+c0,x)-r0+mod)%mod;
        return pii(r1,r0);
    }

    pii cc=solve(32000,c1,c0);
    pii x1=solve(x/32000,cc.first,cc.second);
    pii x2=solve(x%32000,c1,c0);
    r0=(x1.first*x2.first+x1.second*x2.second)%mod;
    r1=(x1.first*x2.second+x1.second*x2.first)%mod;
    return pii(r1,r0);
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

    ll n,m,l,r;
    cin >> n >> m >> l >> r;
    r-=l;
    if((n*m)&1)
    {
        db(qp(r+1,n*m))
        return 0;
    }
    pii r1=solve(m,(r+1)/2,r/2+1);
    pii res=solve(n,r1.first,r1.second);
    db(res.second)

    return 0;
}