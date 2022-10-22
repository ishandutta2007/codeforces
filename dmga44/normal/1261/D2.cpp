#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

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

ll comb(ll n,ll m)
{
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (den*fac[n])%mod;
}

int a[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=ifac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }
//    cout << fac[2] << ' ' << ifac[2] << ' ' << ifac[0] << '\n';

    ll n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    ll m=0;
    for(int i=0;i<n;i++)
        if(a[i]!=a[(i+1)%n])
            m++;

    ll res=qp(k,n-m);
//    cout << res << '\n';
    ll mul=0;
    ll ac=1;
    for(int i=1;i<=m;i++)
    {
        ll f1=(comb(m,i)*ac)%mod;
//        cout << ac << '\n';
        ll f2=qp(k-2,m-i);
        ac=(2*ac)%mod;
        if(i&1)
            ac=(ac+mod-comb(i,(i+1)/2))%mod;
        else
            ac=(ac+mod+comb(i,(i+1)/2))%mod;

//        cout << i << ' ' << f1 << ' ' << f2 << '\n';
        mul=(mul+(f1*f2))%mod;
    }
    db((mul*res)%mod)

    return 0;
}