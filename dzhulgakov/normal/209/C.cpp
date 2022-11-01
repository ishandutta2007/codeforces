#pragma comment(linker, "/STACK:64000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i,n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define REPD(i,n) for (int i = (n)-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = (a); _##i = (b); i <= _##i; ++i)
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define pb push_back
#define MP make_pair
const double pi = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef long long LL;

LL gcd(LL a, LL b) {
	if (a<0) a=-a;
	if (b<0) b=-b;
	if (a<b) swap(a,b);
	while (b) {
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}

template <typename T>
struct Point {
	T x,y;
	Point(T xx = 0, T yy = 0) : x(xx), y(yy) {}
};

template <typename T> Point<T> operator+(const Point<T>& a, const Point<T>& b) { return Point<T>(a.X+b.X,a.Y+b.Y); }
template <typename T> Point<T> operator-(const Point<T>& a, const Point<T>& b) { return Point<T>(a.X-b.X,a.Y-b.Y); }

#define MOD 1000000007

#define N 1024000
int n,m;
VI adj[N];
bool mark[N];
bool isodd;
int odd;
int sum;

void dfs(int v) {
	mark[v] = true;
	sum += SZ(adj[v]);
	if (SZ(adj[v]) % 2 == 1)
	{
		isodd=true;
		++odd;
	}
	REP(i,SZ(adj[v])) if (!mark[adj[v][i]])
		dfs(adj[v][i]);
}

int main()
{
	//freopen(".in","r",stdin);

	/*n=1000000;
	REP(i,n-1)
		adj[i].pb(i+1),adj[i+1].pb(i);*/
	scanf("%d%d",&n,&m);
	REP(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int comp = 0, comp0 = 0;
	CLEAR(mark);
	odd = 0;
	REP(i,n) if (!mark[i])
	{
		sum = 0;
		isodd = false;
		dfs(i);
		if (sum == 0 && i != 0) continue;
		++comp;
		if (!isodd) ++comp0;
	}
	int res = odd/2;
	if (comp > 1) res += comp0;
	printf("%d\n",res);
	return 0;
}