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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e3+5)

#define NEXT(i) (((i)+1)%n)
ll dot(point a,point b) {return real(conj(a)*b);}
ll cross(point a,point b) {return imag(conj(a)*b);}
ll area2(point a,point b,point c) {return cross(b-a,c-a);}

namespace std
{
    bool operator<(point a,point b)
    {
        if(a.real()!=b.real())
            return a.real()<b.real();
        return a.imag()<b.imag();
    }
}

polygon convex_hull(polygon& p)
{
    int n=p.size(),k=0;
    vector<point> h(2*n);
    sort(all(p));
    for(int i=0;i<n;h[k++]=p[i++])
        while(k>=2 && area2(h[k-2],h[k-1],p[i])<=0) k--;
    for(int i=n-2,t=k+1;i>=0;h[k++]=p[i--])
        while(k>=t && area2(h[k-2],h[k-1],p[i])<=0) k--;
    return polygon(h.begin(),h.begin()+k-(k>1));
}

enum{OUT,ON,IN};
int contains(const polygon& P,point p)
{
    bool in=0;
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

vector<bool> contains(vector<point> p,vector<point> ps)
{
    p=convex_hull(p);
    int n=p.size();
    int my=0;
    for(int i=0;i<n;i++)
        if(p[my].imag()>p[i].imag())
            my=i;
    polygon pp;
    for(int i=my;i<my+n;i++)
        pp.push_back(p[i%n]);

    point origin=pp[0];
    for(int i=n-1;i>=0;i--)
        pp[i]-=pp[0];
    p=pp;

    int m=ps.size();
    vector<bool> res;
    for(int i=0;i<m;i++)
    {
        point x=ps[i];
        x-=origin;

        int pos=0;
        for(int po=(1<<19);po;po>>=1)
            if(pos+po<n && cross(p[pos+po],x)>=0)
                pos+=po;
        if(pos==0)
        {
            res.push_back(0);
            continue;
        }
        if(pos==n-1)
            pos--;
        res.push_back((bool)(contains(polygon{p[0],p[pos],p[pos+1]},x)));
    }
    return res;
}

int quad(point x)
{
    if(x.imag()>=0 && x.real()>0) return 0;
    if(x.imag()>0 && x.real()<=0) return 1;
    if(x.imag()<=0 && x.real()<0) return 2;
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<point> ps[3];
    for(int i=0;i<3;i++)
    {
        int n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            int x,y;
            cin >> x >> y;
            ps[i].push_back(point(x,y));
        }
        int pos=0;
        for(int j=0;j<n;j++)
            if(ps[i][j].imag()<ps[i][pos].imag() || (ps[i][j].imag()==ps[i][pos].imag() && ps[i][j].real()<ps[i][pos].real()))
                pos=j;
        for(int j=0;j<pos;j++)
            ps[i].push_back(ps[i][j]);
        reverse(all(ps[i]));
        for(int j=0;j<pos;j++)
            ps[i].pop_back();
        reverse(all(ps[i]));
    }

    vector<point> px;
    px.push_back(ps[0][0]+ps[1][0]+ps[2][0]);
    vector<point> ads;
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<ps[i].size();j++)
            ads.push_back(ps[i][j]-ps[i][j-1]);
        ads.push_back(ps[i][0]-ps[i].back());
    }

    sort(all(ads),[&](point &a,point &b){
        if(quad(a)!=quad(b)) return quad(a)<quad(b);
        return cross(a,b)>0;
    });

    for(auto p : ads)
        px.push_back(px.back()+p);
    px.pop_back();

    int m;
    cin >> m;
    vector<point> pm;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        x*=3;
        y*=3;
        pm.push_back(point(x,y));
    }

    vector<bool> ans=contains(px,pm);

    for(auto x : ans)
    {
        if(x)
            db("YES")
        else
            db("NO")
    }

    return 0;
}