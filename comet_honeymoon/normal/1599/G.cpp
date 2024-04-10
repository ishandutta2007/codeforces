#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x)
{
    x = 0; int c = gc(); int flag = 0;
    while (c < '0' || c > '9') flag |= (c == '-'), c = gc();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
    if (flag) x = -x;
}
template <class T> bool checkmax(T &a, T b){return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b){return b < a ? a = b, 1 : 0;}
const int N = 200005;
int n, k;
struct Point
{
	int x, y;
	Point(int x = 0, int y = 0):x(x), y(y){}
	bool operator < (const Point &rhs) const
	{
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
}a[N], b[N];
Point operator - (const Point &a, const Point &b){return Point(a.x - b.x, a.y - b.y);}
ll det(Point x, Point y){return (ll)x.x * y.y - (ll)x.y * y.x;}
ll dot(Point x, Point y){return (ll)x.x * y.x + (ll)x.y * y.y;}
int on[N];
double dis(Point x, Point y){return sqrt(dot(x - y, x - y));}

bool check(int u, int v)
{
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (det(a[i] - a[u], a[i] - a[v]) == 0) on[i] = 1, ++cnt;
		else on[i] = 0;
	}
	return cnt == n - 1;
}

void init()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 1; i <= 3; ++i) for (int j = i + 1; j <= 3; ++j) if (check(i, j)) break;
}

namespace solver0
{
	void main()
	{
		int m = 0;
		for (int i = 1; i <= n; ++i) if (i != k) b[++m] = a[i];
		sort(b + 1, b + m + 1);
		double ans = min(dis(b[1], a[k]), dis(a[k], b[m])) + dis(b[1], b[m]);
		printf("%.12lf\n", ans);
	}
}

namespace solver1
{
	Point P;
	int m, pos;
	double ans = 1e100;
	void calc1()
	{
		double w = dis(b[1], b[pos]);
		for (int i = pos + 1; i < m; ++i)
		{
			double q = w + dis(b[1], b[i]) + dis(b[i], P) + dis(P, b[i + 1]) + dis(b[i + 1], b[m]);
			checkmin(ans, q);
		}
		checkmin(ans, w + dis(b[1], b[m]) + dis(b[m], P));
	}

	void calc2()
	{
		double w = dis(b[pos], b[m]);
		for (int i = 2; i <= pos; ++i)
		{
			double q = w + dis(b[m], b[i]) + dis(b[i], P) + dis(P, b[i - 1]) + dis(b[i - 1], b[1]);
			checkmin(ans, q);
		}
		checkmin(ans, w + dis(b[1], b[m]) + dis(b[1], P));
	}

	void main()
	{
		m = 0, pos = 0;
		for (int i = 1; i <= n; ++i) if (!on[i]) P = a[i];
		for (int i = 1; i <= n; ++i) if (on[i]) b[++m] = a[i];
		sort(b + 1, b + m + 1);
		for (int i = 1; i <= m; ++i) if (b[i].x == a[k].x && b[i].y == a[k].y) pos = i;
		for (int i = 1; i <= m; ++i)
		{
			double w = dis(b[i], b[pos]) + dis(b[i], P);
			int l = min(i, pos), r = max(i, pos);
			if (l == 1 && r == m) ;
			else if (1 < l && r < m)
			{
				double q = min(dis(P, b[1]), dis(P, b[m])) + dis(b[1], b[m]);
				w += q;
			}
			else if (r == m)
			{
				double q = min(dis(P, b[1]), dis(P, b[l - 1])) + dis(b[1], b[l - 1]);
				w += q;
			}
			else
			{
				double q = min(dis(P, b[r + 1]), dis(P, b[m])) + dis(b[r + 1], b[m]);
				w += q;
			}
			checkmin(ans, w);
		}
		calc1(); calc2();
		printf("%.12lf\n", ans);
	}
}

void solve()
{
	if (on[k] == 0)
	{
		solver0::main();
	}
	else
	{
		solver1::main();
	}
}

int main()
{
	//setIO("");
	init();
	solve();
	return 0;
}