#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ll k;

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        e>>=1;
        b=(b*b)%mod;
    }
    return ans;
}

ll solve(ll dx,ll dy,ll r,ll c)
{
    if(dx==0 && dy==0)
        return qp(k,r*c);
    if(dx>=r || dy>=c)
        return qp(k,r*c);
    ll nr=r-dx;
    ll nc=c-dy;
    ll mul;
    if(2*nr-r>=0 && 2*nc-c>=0)
        mul=qp(k,2*dx*dy);
    else
        mul=qp(k,r*c-2*nr*nc);
    return (mul*solve(dx,dy,nr,nc))%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,r,c;
    cin >> n >> m >> k >> r >> c;
    ll ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    if(ax>bx)
    {
        ax=n-(ax+r-1);
        bx=n-(bx+r-1);
    }
    if(ay>by)
    {
        ay=m-(ay+c-1);
        by=m-(by+c-1);
    }

    ll cx=ax+r-bx;
    ll cy=ay+c-by;
    cx=max(cx,0ll);
    cy=max(cy,0ll);
    ll ans=qp(k,n*m-2*r*c+cx*cy);
//    db(ans)
    ans=(ans*solve(bx-ax,by-ay,r,c))%mod;
    db(ans)

    return 0;
}