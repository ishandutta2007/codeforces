/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

struct Point {
	ll x, y;
	Point(): x(0), y(0) {}
	Point(ll x, ll y): x(x), y(y) {}
	ll operator*(ll pos) const {
		return x * pos + y;
	}
};

struct Node {
	Point p;
	int l, r;
	Node(): p(Point(0, INF)), l(0), r(0) {}
};

vector<Node> t;

void inline init() {
	t.pub(Node());
}

int inline newnode() {
	t.pub(Node());
	return SZ(t) - 1;
}

void add(Point p, int now, int l = -(1 << 17), int r = (1 << 17)) {
	int m = (l + r) >> 1;
	bool Lcmp = p * l < t[now].p * l;
	bool Mcmp = p * m < t[now].p * m;
	if(Mcmp) swap(p, t[now].p);
	if(l == r) return;
	if(Lcmp != Mcmp) {
		if(!t[now].l) {
			int id = newnode();
			t[now].l = id;
		}
		add(p, t[now].l, l, m);
	} else {
		if(!t[now].r) {
			int id = newnode();
			t[now].r = id;
		}
		add(p, t[now].r, m + 1, r);
	}
}

int merge(int u, int v, int l = -(1 << 17), int r = (1 << 17)) {
	if(!u || !v) return u + v;
	add(t[v].p, u, l, r);
	int m = (l + r) >> 1;
	t[u].l = merge(t[u].l, t[v].l, l, m);
	t[u].r = merge(t[u].r, t[v].r, m + 1, r);
	return u;
}

ll get(int x, int now, int l = -(1 << 17), int r = (1 << 17)) {
	if(!now) return INF;
	if(l == r) return t[now].p * x;
	int m = (l + r) >> 1;
	return min(t[now].p * x, (m >= x ?
		get(x, t[now].l, l, m) :
		get(x, t[now].r, m + 1, r)
	));
}

int n;
int a[1 << 17], b[1 << 17];
int rt[1 << 17];
vector<int> nei[1 << 17];
ll dp[1 << 17];

void dfs(int now, int lst) {
	rt[now] = newnode();
	bool leaf = 1;
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		if(to == lst) continue;
		dfs(to, now);
		rt[now] = merge(rt[now], rt[to]);
		leaf = 0;
	}
	if(!leaf) dp[now] = get(a[now], rt[now]);
	else dp[now] = 0;
	add(Point(b[now], dp[now]), rt[now]);
}

int main() {
	init();
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	cont(i, n) scanf("%d", b + i);
	cont(i, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].pub(v); nei[v].pub(u);
	}
	dfs(1, 0);
	cont(i, n) printf("%lld%c", dp[i], " \n"[i == n]);
	return 0;
}

/**
 * 30min
 * 25min
 * 
 *   f(i)  i 
 *    i  f(i) = 0
 *   f(i) = min[j in subtree i] (f(j) + AiBj)
 *   dfs
 *    Ai  f(i) 
 *    (Bi, f(i)) 
 */