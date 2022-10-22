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
const ll mod = (1e9 + 7);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(3e5 + 5)

ll calc_k(vector<ll>& ac,ll base,int k)
{
    // cerr << k << '\n';
    return ac[k]+base;
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
		return x = 1, y = 0, a;
	ll r = gcd(b, a % b, y, x);
	y -= a / b * x;
	return r;
}

pii aux(ll mi,ll ma,ll x,ll cycle)
{
    ll a,b;
    if(ma<=x)
        a=ma;
    else if(mi>x)
        a=mi;
    else
        a=mi+(((x-mi)/cycle)*cycle);

    if(mi>x)
        b=mi;
    else if(ma<=x)
        b=ma;
    else
        b=ma-(((ma-(x+1))/cycle)*cycle);
    return pii(a,b);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll base=0;
    vector<ll> a(n),b(n); 
    vector<ll> d,ac;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        base+=a[i];
        d.push_back(b[i]-a[i]);
    }

    sort(all(d));
    ll p=lower_bound(all(d),0)-d.begin();
    sort(allr(d));

    ac.push_back(0);
    for(int i=0;i<n;i++)
        ac.push_back(ac.back()+d[i]);

    p=n-p;
    // cout << p << '\n';
    ll m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin >> x >> y;

        ll va,vb;
        ll g=gcd(x,y,va,vb);
        if(n%g)
        {
            cout << -1 << '\n';
            continue;
        }

        va*=n/g;
        vb*=n/g;
        // db(va)
        // db(vb)
        // db(g)
        ll cycle_x=y/g;
        ll cycle_y=x/g;
        if(va<0)
        {
            ll times=(abs(va)-1)/cycle_x+1;
            va+=times*cycle_x;
            vb-=times*cycle_y;
        }
        if(vb<0)
        {
            ll times=(abs(vb)-1)/cycle_y+1;
            va-=times*cycle_x;
            vb+=times*cycle_y;
        }
        if(va<0 || vb<0)
        {
            cout << -1 << '\n';
            continue;
        }
        // db(va)
        // db(vb)
        // db(x)
        // db(y)
        ll times=vb/cycle_y;
        va+=times*cycle_x;
        vb-=times*cycle_y;
        ll mi=vb*y;
        times=va/cycle_x;
        va-=times*cycle_x;
        vb+=times*cycle_y;
        ll ma=vb*y;
        // cerr << "xxx:ma " << ma << '\n';

        ll ans=calc_k(ac,base,mi);
        ans=max(ans,calc_k(ac,base,ma));
        ll act=0;
        // cerr << "xxx1\n";
        for(ll po=(1<<18);po;po>>=1)
            if(mi+(act+po)*cycle_y*y<=ma && calc_k(ac,base,mi+(act+po-1)*cycle_y*y)<=calc_k(ac,base,mi+(act+po)*cycle_y*y))
                act+=po;
        // cerr << act << '\n';
        // cerr << "xxx2\n";
        // cerr << '\n';
        cout << calc_k(ac,base,mi+act*cycle_y*y) << '\n';
    }

    return 0;
}