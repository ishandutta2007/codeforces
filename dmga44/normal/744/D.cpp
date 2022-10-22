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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(35)

struct line { point p, q; };

double dot(point a, point b) { return real(conj(a) * b); }

double cross(point a, point b) { return imag(conj(a) * b); }

double area2(point a, point b, point c) { return cross(b - a, c - a); }

namespace std
{
	bool operator<(point a, point b)
	{
		if (a.real() != b.real())
			return a.real() < b.real();
		return a.imag() < b.imag();
	}
}

polygon convex_hull(vector<point> &P)
{
	int n = P.size(), k = 0;
	vector<point> h(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; h[k++] = P[i++])
		while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) < 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
		while (k >= t && area2(h[k - 2], h[k - 1], P[i]) < 0) --k;
	return polygon(h.begin(), h.begin() + k - (k > 1));
}

point operator*(ld x,point a)
{
    return point(a.real()*x,a.imag()*x);
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
    int x,y;
    cin >> x >> y;
    return point(x,y);
}

void print(point p)
{
    cout << p.real() << ' ' << p.imag() << '\n';
}

ld solve(vector<point> ps)
{
    ld cnt=1e4;
    int n=ps.size();
    for(int j=n-1;j>=0;j--)
        ps[j]=ps[j]-ps[0];
    for(int j=1;j<n;j++)
        ps[j]=(cnt/(abs(ps[j])*abs(ps[j])))*ps[j];

    ps=convex_hull(ps);

    n=ps.size();
    bool ok=1;
    for(int i=0;i<n;i++)
        if(abs(ps[i])<eps)
            ok=0;
    if(!ok)
        return -1;
    ps.push_back(ps[0]);
    ld res=0;
    for(int j=0;j<n;j++)
    {
        point p1=ps[j];
        point p2=ps[j+1];
        point nor=point(0,1)*(p2-p1);
        ld d=-dot(nor,p1);
        ld dist=abs(d)/abs(nor);
        res=max(res,cnt/(2*dist));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<point> vr(n);
    vector<point> vb(m);
    for(int i=0;i<n;i++)
        vr[i]=read();
    for(int i=0;i<m;i++)
        vb[i]=read();

    ld res=0;
    for(int i=0;i<m;i++)
    {
        vector<point> cr;
        vector<point> cb;
        for(int j=0;j<n;j++)
            cr.push_back(vr[j]-vb[i]);
        for(int j=0;j<m;j++)
            cb.push_back(vb[j]-vb[i]);
        ld cnt=1e4;
        for(int j=0;j<n;j++)
            cr[j]=(cnt/(abs(cr[j])*abs(cr[j])))*cr[j];
        for(int j=0;j<m;j++)
        {
            if(i==j)
                continue;
            cb[j]=(cnt/(abs(cb[j])*abs(cb[j])))*cb[j];
        }
//        db(i)
//        db("")
//        for(int j=0;j<n;j++)
//            print(cr[j]);
//        db("")
//        for(int j=0;j<m;j++)
//            print(cb[j]);
        cr=convex_hull(cr);
        cb=convex_hull(cb);

        cb.push_back(cb[0]);
        int lb=cb.size()-1;
        int lr=cr.size();
//        db("")
//        for(int j=0;j<lr;j++)
//            print(cr[j]);
//        db("")
//        for(int j=0;j<lb;j++)
//            print(cb[j]);
        int best=0;
        for(int j=0;j<lb;j++)
        {
            point p1=cb[j];
            point p2=cb[j+1];
            point nor=point(0,1)*(p2-p1);
            if(j==0)
            {
                for(int k=0;k<lr;k++)
                    if(dot(nor,cr[k])<dot(nor,cr[best]))
                        best=k;
            }
            else
            {
                while(dot(nor,cr[best])>dot(nor,cr[(best+1)%lr])+eps)
                    best=(best+1)%lr;
            }
            if(dot(nor,cr[best])>dot(nor,p1)+eps)
                continue;
            ld d=-dot(nor,p1);
            ld dist=abs(d)/abs(nor);
            if(dist==0)
                res=-1;
            else if(res!=-1)
                res=max(res,cnt/(2*dist));
//            cout << best << '\n';
//            print(nor);
//            cout << j << ' ' << res << '\n';
        }
//        db("")
    }

    for(int i=0;i<n;i++)
    {
        vector<point> to_solve;
        to_solve.push_back(vr[i]);
        for(int j=0;j<m;j++)
            to_solve.push_back(vb[j]);
        ld x=solve(to_solve);
        if(x==-1)
            res=-1;
        else if(res!=-1)
            res=max(res,x);
    }

    prec(10);

    if(res==-1)
        db(-1)
    else
        db(res)

    return 0;
}