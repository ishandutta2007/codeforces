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

template <typename T> struct Point {
	T x,y;
	Point(T _x=0,T _y=0) : x(_x),y(_y) {}
	void swap() { swap(x,y); }
	double len() const;
	Point<double> asDouble() { return Point<double>(x,y); }
	Point<T> norm() const;
	Point<T> ort() const { return Point<T>(y,-x); }
	int side() const
	{
		if (x==0)
			if (y < 0) return 3;
			else return 1;
		else
			if (x>0)
				return 0;
			else return 2;
	}
};
template <typename T> Point<T> operator- (const Point<T> &a) { return Point<T>(-a.x,-a.y); }
template <typename T> Point<T> operator+ (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x+b.x,a.y+b.y); }
template <typename T> Point<T> operator- (const Point<T> &a, const Point<T> &b) { return Point<T>(a.x-b.x,a.y-b.y); }
template <typename T> Point<T> operator* (const T a, const Point<T> &b) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator* (const Point<T> &b, const T a) { return Point<T>(a*b.x,a*b.y); }
template <typename T> Point<T> operator/ (const Point<T> &b, const T a) { return Point<T>(b.x/a,b.y/a); }
template <typename T> T operator* (const Point<T> &a, const Point<T> &b) { return a.x*b.x+a.y*b.y; }
template <typename T> T operator^ (const Point<T> &a, const Point<T> &b) { return a.x*b.y-a.y*b.x; }
template <typename T> double Point<T>::len() const { return sqrt((double)((*this)*(*this))); }
template <typename T> Point<T> Point<T>::norm() const { return (*this)/len(); }
template <typename T> bool operator< (const Point<T> &a, const Point<T> &b) { return a.x<b.x || a.x==b.x && a.y<b.y; }
bool operator== (const Point<int> &a, const Point<int> &b) { return a.x==b.x && a.y==b.y; }
bool operator!= (const Point<int> &a, const Point<int> &b) { return a.x!=b.x || a.y!=b.y; }
int sign(int x) { if (x==0) return 0; if (x>0) return +1; else return -1; }
int sign(LL x) { if (x==0) return 0; if (x>0) return +1; else return -1; }
int sign(double x) { if (fabs(x)<eps) return 0; if (x>0) return +1; else return -1; }
template<typename T> T sqr(T x) { return x*x; }
typedef Point<double> DPnt;
typedef Point<LL> IPnt;
const DPnt INFDPnt(1.0e30,1.0e30);

vector<IPnt> a[3];

bool cmp(const IPnt& p1, const IPnt& p2)
{
	int s1 = p1.side();
	int s2 = p2.side();
	if (s1 != s2) return s1 < s2;
	return (p1^p2) > 0;
}

vector<IPnt> add(const vector<IPnt>& a, const vector<IPnt>& b)
{
	vector<IPnt> d;
	REP(i,SZ(a)) d.pb(a[(i+1)%SZ(a)]-a[i]);
	REP(i,SZ(b)) d.pb(b[(i+1)%SZ(b)]-b[i]);
	sort(ALL(d),cmp);
	//reverse(ALL(d));
	vector<IPnt> res;
	res.pb(IPnt(0,0));
	REP(i,SZ(d)-1)
		res.pb(res.back()+d[i]);
	IPnt shift = *min_element(ALL(a)) + *min_element(ALL(b)) - *min_element(ALL(res));
	REP(i,SZ(d))
		res[i] = res[i] + shift;
	return res;
}

int signOnLine(IPnt a, IPnt b, IPnt p) {
	if (a.x == b.x)
		if (p.y > b.y) return +1;
		else if (p.y < a.y) return -1;
		else return 0;
	else 
		return sign(p.y*(b.x-a.x) - ((p.x-a.x)*(b.y-a.y) + a.y*(b.x-a.x)));
}
struct Poly
{
	set<IPnt> bottom,top;
	void read(vector<IPnt> a) {
		int n = SZ(a);
		a.pb(a[0]);
		LL area=0;
		top.clear(); bottom.clear();
		REP(i,n) {
			if (a[i].x < a[i+1].x)
			{ bottom.insert(a[i]); bottom.insert(a[i+1]);	}
			if (a[i].x > a[i+1].x)
			{ top.insert(a[i]); top.insert(a[i+1]); }
			area += (a[i].y+a[i+1].y)*(a[i].x-a[i+1].x);
		}
		if (area < 0) { area = -area; top.swap(bottom); }
		if (n<=2) { top.clear(); top.insert(a[0]);
			top.insert(a[n-1]); bottom=top;	}
	}
	bool contains(IPnt p) {
		set<IPnt>::iterator it = top.end(), it1, it2, it1n, it2n;
		it--;
		if (p.x < top.begin()->x || p.x > it->x) return false;
		it1 = bottom.lower_bound(p);
		if (it1 == bottom.begin()) it1++;
		if (it1 == bottom.end()) it1--;
		it2 = top.lower_bound(p);
		if (it2 == top.begin()) it2++;
		if (it2 == top.end()) it2--;
		it1n = it1; it1--;
		it2n = it2; it2--;
		return signOnLine(*it1,*it1n,p)>=0 && signOnLine(*it2,*it2n,p)<=0;
	}
} poly;

int main()
{
	//freopen("e.in","r",stdin);
	REP(i,3)
	{
		int n;
		scanf("%d",&n);
		REP(j,n)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].pb(IPnt(x,y));
		}
	}
	vector<IPnt> b = add(a[0],a[1]);
	b = add(b,a[2]);
	poly.read(b);
	int n;
	scanf("%d",&n);
	REP(i,n)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%s\n",poly.contains(IPnt(x,y)*3LL)?"YES":"NO");
	}
	return 0;
}