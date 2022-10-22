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
#define MAXN (ll)(5e5+5)

struct line { point p, q; };

double cross(point a, point b) { return imag(conj(a) * b); }

point operator*(double a,point p)
{
    return point(a*p.real(),a*p.imag());
}

point crosspoint(const line &l, const line &m)
{
	double A = cross(l.q - l.p, m.q - m.p);
	double B = cross(l.q - l.p, l.q - m.p);
	if (abs(A) < eps && abs(B) < eps)
		return m.p; // same line
	if (abs(A) < eps)
		assert(false); // !!!PRECONDITION NOT SATISFIED!!!
	return m.p + B / A * (m.q - m.p);
}

point read()
{
    ll x,y;
    cin >> x >> y;
    return point(x,y);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ld h;
    cin >> n >> h;
    vector<point> ps;
    for(int i=0;i<n;i++)
        ps.push_back(read());

    point se=ps.back()+point(0,h);
    point dir=point(0,-h);

    ld res=0;
    for(int i=n-1;i>0;i--)
    {
        point p1=ps[i];
        point p2=ps[i-1];
        if(cross(p2-se,dir)<0)
            continue;
        line l1=line{se,se+dir};
        line l2=line{p1,p2};
        res+=abs(p2-crosspoint(l1,l2));
        dir=p2-se;
    }
    prec(10);
    db(res)

    return 0;
}