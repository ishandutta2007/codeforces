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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

struct line { point p, q; };
using segment = line;

ll dot(point a, point b) { return real(conj(a) * b); }

ll cross(point a, point b) { return imag(conj(a) * b); }

int ccw(point a, point b, point c)
{
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1; // counter clockwise
	if (cross(b, c) < 0) return -1; // clockwise
	if (dot(b, c) < 0) return +2; // c--a--b on line
	if (dot(b, b) < dot(c, c)) return -2; // a--b--c on line
	return 0;
}

bool intersectSS(const segment &s, const segment &t)
{
	return ccw(s.p, s.q, t.p) * ccw(s.p, s.q, t.q) <= 0
			&& ccw(t.p, t.q, s.p) * ccw(t.p, t.q, s.q) <= 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll p=0;
        ll act=0;
        ll res=0;
        segment kk;
        vector<ll> hh(n+1);
        vector<ll> xx(n+1);
        for(int i=0;i<n;i++)
            cin >> hh[i] >> xx[i];
        hh[n]=3e9+5;
        for(int i=0;i<n;i++)
        {
            ll t,x;
            t=hh[i];
            x=xx[i];
//            cin >> t >> x;
            if(i==0)
            {
                act=t;
                kk=segment{point(act,0),point(act+abs(x),x)};
                segment este=segment{point(t,x),point(hh[i+1],x)};
                res+=intersectSS(kk,este);
                act=t+abs(x);
                p=x;
            }
            else
            {
                if(act<=t)
                {
                    act=t;
                    kk=segment{point(act,p),point(act+abs(x-p),x)};
                    segment este=segment{point(t,x),point(hh[i+1],x)};
                    res+=intersectSS(kk,este);
                    act=t+abs(x-p);
                    p=x;
                }
                else
                {
                    segment este=segment{point(t,x),point(hh[i+1],x)};
                    res+=intersectSS(kk,este);
                }
            }
        }
        db(res)
    }

    return 0;
}