#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll>fac(MAXN),ifac(MAXN);
    fac[0]=1;
    for(int i=1;i<MAXN;i++)
        fac[i]=(fac[i-1]*i)%mod;
    ifac[MAXN-1]=qp(fac[MAXN-1],mod-2);
    for(int i=MAXN-2;i>=0;i--)
        ifac[i]=(ifac[i+1]*(i+1))%mod;

    ll n,k;
    cin >> n >> k;
    vector<int> pos(n+1);
    pos[n]=-1;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        pos[a[i]]=i;
    }

    int c=0;
    for(int i=1;i<n;i++)
        if(pos[a[i]+1]<pos[a[i-1]+1])
            c++;
    
    if(n+k-1-c<n)
    {
        db(0)
        return 0;
    }
    ll ans=(fac[n+k-1-c]*ifac[n])%mod;
    ans=(ans*ifac[k-1-c])%mod;
    db(ans)

    return 0;
}