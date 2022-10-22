#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

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

ll fac[MAXN];
ll ifac[MAXN];

ll comb(int n,int m)
{
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (fac[n]*den)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=ifac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }

    ll n;
    cin >> n;
    ll res=(qp(3,n*n)-qp((qp(3,n)-3+mod)%mod,n)+mod)%mod;
//    db(res)
    for(int i=1;i<=n;i++)
    {
        ll cp=comb(n,i);
        ll c1=3;
        ll c2=(qp(3,i)-3+mod)%mod;
        ll o1=(qp(3,n-i)-1+mod)%mod;
        o1=qp(o1,n);
        ll o2=qp(3,n-i);
        o2=qp(o2,n);
        ll add=(c1*o1+c2*o2)%mod;
        add=(add*cp)%mod;
//        cout << i << ' ' << cp << ' ' << add << '\n';
        if(i&1)
            res=(res+add)%mod;
        else
            res=(res-add+mod)%mod;
    }
    db(res)

    return 0;
}