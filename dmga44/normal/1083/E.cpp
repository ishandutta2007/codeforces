#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef __int128 ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
//#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll cross(point a, point b) { return imag(conj(a) * b); } ///a_x*b_y-b_x*a_y

ll dot(point a, point b) { return real(conj(a) * b); } /// a_x*b_x+a_y*b_y

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

namespace std
{
	bool operator<(const point &a, const point &b)
	{
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
	}
}

const ll oo = 0x3f3f3f3f3f3f3f3f;

struct hull : vector<point>
{
    void add_point(point p)
    {
        for (int s = size(); s > 1; --s)
            if (area2(at(s - 2), at(s - 1), p) < 0) break;
            else pop_back();
        push_back(p);
    }

    ll max_dot(point p)
    {
        int lo = 0, hi = (int) size() - 1, mid;

        while (lo < hi)
        {
            mid = (lo + hi) / 2;

            if (dot(at(mid), p) <= dot(at(mid + 1), p))
                lo = mid + 1;
            else hi = mid;
        }

        return dot(at(lo), p);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pip> vp;
    for(int i=0;i<n;i++)
    {
        long long x,y,a;
        cin >> x >> y >> a;
        vp.push_back(pip(y,pii(x,a)));
    }

    sort(allr(vp));

    ll res=0;
    hull h;
    for(int i=0;i<n;i++)
    {
        ll y=vp[i].f;
        ll x=vp[i].s.f;
        ll a=vp[i].s.s;
        if(!i)
        {
            h.add_point(point(x,(x*y)-a));
            res=(x*y)-a;
            continue;
        }
        ll v=max((x*y)-a,h.max_dot(point(-y,1))+(x*y)-a);
        if(v>res)
        {
            res=v;
            h.add_point(point(x,v));
        }
    }
    db(((long long)res))

    return 0;
}