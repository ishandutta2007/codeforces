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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll c1(ll t,ll a,ll d)
{
    return ((t/d)+1)*a;
}

ll c2(ll t,ll b,ll c,ll d)
{
    if(t<=0)
        return 0;
    if(t<c)
    {
        ll times=t/d+1;
        ll base=times*b*t;
        ll men=(times*(times-1))/2*b*d;
        return base-men;
    }
    else
    {
        ll dif=t-c;
        ll tot=dif/d+1;
        return c2(t-tot*d,b,c,d)+tot*b*c;
    }
}

ll aux(ll x,ll a,ll b,ll c,ll d)
{
    ll dam=c1((x-1)*d,a,d);
    ll heal=c2((x-1)*d,b,c,d);
    ll d1=dam-heal;
    return d1;
}

ll dif(ll x,ll a,ll b,ll c,ll d)
{
    if(aux(x,a,b,c,d)<aux(x+1,a,b,c,d))
        return 1;
    return 0;
}

ll solve(ll a,ll b,ll c,ll d)
{
    ll times=0;
    for(ll po=(1ll<<30);po;po>>=1)
    {
        if((times+po-1)*d>2*c)
            continue;
        if(dif(times+po,a,b,c,d))
            times+=po;
    }

    return max(aux(times,a,b,c,d),aux(times+1,a,b,c,d));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a>b*c)
            db(-1)
        else
            db(solve(a,b,c,d))
    }

    return 0;
}
/**
7
1 1 1 1
2 2 2 2
1 2 3 4
4 3 2 1
228 21 11 3
239 21 11 3
1000000 1 1000000 1
1
4 3 2 1
**/