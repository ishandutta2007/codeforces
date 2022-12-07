#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct point {
	int x, y, p, q;
	point() : point(0, 0, 0, 0) {}
	point(int xx, int yy) : point(xx, yy, 0, 0) {}
	point(int xx, int yy, int pp, int qq) { x = xx, y = yy, p = pp, q = qq; }
};
bool f(point p1, point p2)
{
	if (1LL * p1.q*p2.p != 1LL * p1.p*p2.q)return 1LL * p1.q*p2.p < 1LL * p1.p*p2.q;
	if (p1.y != p2.y) return p1.y < p2.y;
	return p1.x < p2.x;
}

point operator - (point &p1)
{
	int xx = -p1.x, yy = -p1.y;
	return point(xx, yy);
}
point operator - (point &p1, point &p2)
{
	int xx = p1.x - p2.x, yy = p1.y - p2.y;
	return point(xx, yy);
}

inline double dist(point p1)
{
	return sqrt(1.0 * p1.x*p1.x + 1.0 * p1.y*p1.y);
}
inline double dist(point p1, point p2)
{
	return sqrt(1.0 * (p1.x - p2.x)*(p1.x - p2.x) + 1.0 * (p1.y - p2.y)*(p1.y - p2.y));
}

struct Convex_hull{
	int n,N;
	point p[100000];
	bool ccw(int i, int j, int k)
	{
		if (1LL * (p[j] - p[i]).x*(p[k] - p[j]).y - 1LL * (p[j] - p[i]).y*(p[k] - p[j]).x > 0)return 1;
		return 0;
	}
	Vi hull;
	vector<pair<ll,db> > v;
	void get_hull()
	{
		fup(i,0,n-1,1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			p[i]=point(x,y);
		}
		sort(p, p + n, f);
		for (int i = 1; i < n; i++)
		{
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p + 1, p + n, f);
		hull.push_back(0);
		hull.push_back(1);
		int next = 2;
		int minY = p[1].y;
		while (next < n)
		{
			while (hull.size() >= 2)
			{
				int first = hull.back();
				hull.pop_back();
				int second = hull.back();
				if (ccw(second, first, next))
				{
					hull.push_back(first);
					break;
				}
			}
			hull.push_back(next++);
		}
		N=hull.size();
	}
	void get_v()
	{
		fup(i,0,N-1,1)
		{
			int x1,y1,x2,y2,x3,y3;
			x1=p[hull[(i+N-1)%N]].x,y1=p[hull[(i+N-1)%N]].y;
			x2=p[hull[i]].x,y2=p[hull[i]].y;
			x3=p[hull[(i+1)%N]].x,y3=p[hull[(i+1)%N]].y;
			int a1=x2-x1,a2=y2-y1,b1=x3-x2,b2=y3-y2;
			ll L,P;
			db Q;
			L=1LL*b1*b1+1LL*b2*b2;
			bool neg=0;
			P=1LL*a1*b1+1LL*a2*b2;
			Q=sqrt(1LL*a1*a1+1LL*a2*a2)*sqrt(1LL*b1*b1+1LL*b2*b2);
			v.pb(mp(L,P/Q));
		}
	}
}A,B;

bool equal(const pair<ll,db> &p1, const pair<ll,db> &p2)
{
	return (p1.X==p2.X && abs(p1.Y-p2.Y)<1e-9);
}
int pi[100000];
int main() {
	scanf("%d%d",&A.n,&B.n);
	A.get_hull();B.get_hull();
	if(A.N!=B.N)return !printf("NO");
	A.get_v();A.get_v();B.get_v();
	auto &v1=A.v, &v2=B.v;
	int n=v1.size(),m=v2.size();
	for (int i = 1, j = 0; i < m; i++)
	{
		while (j > 0 && !equal(v2[i],v2[j])) j = pi[j - 1];
		if (equal(v2[i],v2[j])) pi[i] = ++j;
	}
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && !equal(v1[i],v2[j])) j = pi[j-1];
		if (equal(v1[i],v2[j]))
		{
			if (j == m - 1)
			{
				return !printf("YES");
				j=pi[j];
			}
			else j++;
		}
	}
	puts("NO");
}