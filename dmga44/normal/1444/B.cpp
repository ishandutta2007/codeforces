#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll fac[MAXN];
ll ifac[MAXN];

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=ifac[0]=1;
    for(ll i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }

    int n;
    cin >> n;
    vector<ll> a(2*n);
    for(int i=0;i<2*n;i++)
        cin >> a[i];

    sort(all(a));

    ll res=0;
    ll mul=(fac[2*n]*ifac[n])%mod;
    mul=(mul*ifac[n])%mod;
    for(int i=0;i<2*n;i++)
    {
        ll add;
        if(i<n)
        {
            add=(a[i]*mul)%mod;
            add=mod-add;
        }
        else
            add=(a[i]*mul)%mod;
        res=(res+add)%mod;
    }
    db(res)

    return 0;
}