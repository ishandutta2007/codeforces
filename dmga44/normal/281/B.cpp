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
typedef pair<ld,pii> pdp;
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
#define MAXN (ll)(5e5+5)

bool best(pii a,pii b,pii c)
{
    ld n1=abs(c.f*a.s-a.f*c.s);
    ld d1=a.s*c.s;
    ll g1=__gcd((ll)n1,(ll)d1);
    n1/=g1;
    d1/=g1;
    ld n2=abs(c.f*b.s-b.f*c.s);
    ld d2=b.s*c.s;
    ll g2=__gcd((ll)n2,(ll)d2);
    n2/=g2;
    d2/=g2;
    if(n1*d2>n2*d1)
        return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x,y,n;
    cin >> x >> y >> n;
    ll g=__gcd(x,y);
    x/=g;
    y/=g;
    pii res=pii(0,1);
    for(ll i=1;i<=n;i++)
    {
        ll v1=(x*i)/y;
        ll v2=v1+1;
//        cout << v1 << ' ' << v2 << ' ' << i << '\n';
        if(best(res,pii(v1,i),pii(x,y)))
            res=pii(v1,i);
        if(best(res,pii(v2,i),pii(x,y)))
            res=pii(v2,i);
    }
    cout << res.f << '/' << res.s << '\n';

    return 0;
}