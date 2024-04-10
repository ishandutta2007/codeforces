#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int sign(int x) { if (x==0) return 0; if (x>0) return +1; else return -1; }
int sign(double x) { if (fabs(x)<eps) return 0; if (x>0) return +1; else return -1; }
template<typename T> T sqr(T x) { return x*x; }

template<typename T> struct Point {
	T x,y,z;
	Point(T _x=0,T _y=0,T _z=0) : x(_x),y(_y),z(_z) {}
	void read();
	double len() const;
	Point<T> norm() const;
	Point<double> asDouble() { return Point<double>(x,y,z); }
};

template<typename T> Point<T> operator+ (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x+b.x,a.y+b.y,a.z+b.z); }
template<typename T> Point<T> operator- (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x-b.x,a.y-b.y,a.z-b.z); }
template<typename T> Point<T> operator* (const T a, const Point<T> &b) { return Point<T>(a*b.x,a*b.y,a*b.z); }
template<typename T> Point<T> operator* (const Point<T> &b, const T a) { return a*b; }
template<typename T> T operator* (const Point<T> &a, const Point<T> &b) { return a.x*b.x+a.y*b.y+a.z*b.z; }
template<typename T> Point<T> operator^ (const Point<T> &a, const Point<T> &b) { return Point<T>(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x); }
template<typename T> double Point<T>::len() const { return sqrt((double)((*this)*(*this))); }
template<typename T> Point<T> Point<T>::norm() const { return (1.0/len())*(*this); }
typedef Point<double> DPnt;
typedef Point<int> IPnt;
template<> void Point<int>::read() { scanf("%d%d%d",&x,&y,&z); }
template<> void Point<double>::read() { scanf("%lf%lf%lf",&x,&y,&z); }

double PointSegDist(IPnt p, IPnt c, IPnt v) {
	IPnt base = c-p;
	double t = -(v*base)/(double)(v*v);
	if (t<-eps) return 1.0e30;
	DPnt otr = (base.asDouble()+t*v.asDouble());
	return otr.len();
}

int n;
int R;
IPnt a,v;

double solve(IPnt p, int R)
{
/*	double dist = PointSegDist(p,a,v);
	if (dist > R-eps) return 1.0e30;*/
	IPnt q = a-p;
	LL A = v*v;
	LL B = q*v;
	LL C = q*q - R*R;
	LL det = B*B-A*C;
	if (det < 0) return 1.0e30;
	if (-A*B < 0) return 1.0e30;
	double t = (-B - sqrt((double)det))/A;
	return t;
}

int main()
{
	//freopen("data.in","r",stdin);

	a.read();
	v.read();
	scanf("%d%d",&R,&n);
	double res = 1.0e30;
	REP(i,n)
	{
		int r,m;
		IPnt c;
		c.read();
		scanf("%d%d",&r,&m);
		res = min(res,solve(c,r+R));
		REP(j,m)
		{
			IPnt p;
			p.read();
			res = min(res,solve(c+p,R));
		}
	}
	if (res > 1.0e20)
		printf("-1\n");
	else
		printf("%.10lf\n",res);
	return 0;
}