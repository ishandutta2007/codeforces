#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (998244353);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(2e3 + 5)

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return ans;
}

ll ifac[MAXN],fac[MAXN];
ll iinv[MAXN];
ll stirling[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=ifac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
        iinv[i]=qp(i,mod-2);
    }
    
    stirling[1][1]=1;
    for(int i=2;i<MAXN;i++)
        for(int j=1;j<=i;j++)
            stirling[i][j]=(stirling[i-1][j]*j+stirling[i-1][j-1]*j)%mod;

    int t;
    cin >> t;
    while(t--)
    {
        ll n,m,k;
        cin >> n >> m >> k;
        ll ans=0;
        ll comb=1;
        ll po_m1=(m+1)/2;
        ll po_m=qp(m,n-1);
        ll inv_m=qp(m,mod-2);
        for(int i=1;i<=k && i<=n;i++)
        {
            ll times=(stirling[k][i]*po_m1)%mod;
            times=(times*po_m)%mod;
            comb=(comb*(n-i+1))%mod;
            comb=(comb*iinv[i])%mod;
            ans=(ans+comb*times)%mod;

            po_m1=(po_m1*((m+1)/2))%mod;
            po_m=(po_m*inv_m)%mod;
        }
        cout << ans << '\n';
    }

    return 0;
}