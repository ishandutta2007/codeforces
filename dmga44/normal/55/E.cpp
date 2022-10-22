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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
//typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)
#define NEXT(i) ((i+1)%n)

typedef vector<point> polygon;

ll dot(point a, point b) { return real(conj(a) * b); }

ll cross(point a, point b) { return imag(conj(a) * b); }

int quad(point x)
{
    if(x.imag()>=0 && x.real()>0) return 0;
    if(x.imag()>0 && x.real()<=0) return 1;
    if(x.imag()<=0 && x.real()<0) return 2;
    return 3;
}

void angular_sort(polygon &angs)
{
    sort(all(angs),[&](point &a,point &b){
            if(quad(a)!=quad(b)) return quad(a)<quad(b);
            return cross(a,b)>0;
        });
}


enum { OUT, ON, IN };
int contains(const polygon &P, const point &p)
{
	bool in = false;
	for (int i = 0, n = P.size(); i < n; ++i)
	{
		point a = P[i] - p, b = P[NEXT(i)] - p;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b))
			if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0)
			return ON;
	}
	return in ? IN : OUT;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    polygon p;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin >> x >> y;
        p.push_back(point(x,y));
    }

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        ll x,y;
        cin >> x >> y;
        point pp=point(x,y);
        if(contains(p,pp)!=IN)
        {
            db(0)
            continue;
        }
        vector<point> angs;
        for(int j=0;j<n;j++)
        {
            point v=p[j]-pp;
            angs.push_back(v);
        }

        angular_sort(angs);

        for(int j=0;j<n;j++)
            angs.push_back(angs[j]);

        ll act=0,pos=1;
        while(cross(angs[0],angs[pos])>0)
            pos++;
        ll r=pos;
        ll res=0;
        for(int l=1;l<pos;l++)
        {
            while(cross(angs[l],angs[r])>0)
                r++;
            act+=(r-pos);
        }
        res+=act;
        for(int j=1;j<n;j++)
        {
            ll pa=pos;
            if(j==pos)
                pos++;
            while(cross(angs[j],angs[pos])>0)
                pos++;
            ll dif=pos-pa;
            ll p1=pa-j;
            ll p2=n-p1-dif;
            act+=(dif*(p2-p1));
            res+=act;
        }
        db(res/3)
    }

    return 0;
}