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

struct DynLichao {
	struct Node {
		Point p;
		int l, r;
		Node(): p(Point(0, -INF)), l(0), r(0) {}
	};
	vector<Node> t;
	void inline init() {
		t.clear();
		t.pub(Node());
		t.pub(Node());
	}
	int inline newnode() {
		t.pub(Node());
		return SZ(t) - 1;
	}
	void add(Point p, int now = 1, int l = 0, int r = 1 << 20) {
		int m = (l + r) >> 1;
		bool Lcmp = p * l > t[now].p * l;
		bool Mcmp = p * m > t[now].p * m;
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
	ll get(ll x, int now = 1, int l = 0, int r = 1 << 20) {
		if(!now) return -INF;
		if(l == r) return t[now].p * x;
		int m = (l + r) >> 1;
		return max(t[now].p * x, (m >= x ?
			get(x, t[now].l, l, m) :
			get(x, t[now].r, m + 1, r)
		));
	}
} seg;

int n;
int a[1 << 20];
ll p[1 << 20];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i), p[i] = p[i - 1] + a[i];
	ll ans = 0; seg.init();
	cont(i, n) {
		ans = max(ans, seg.get(i) - p[i]);
		seg.add(Point(a[i], p[i] - 1ll * a[i] * i));
	}
	seg.init();
	range(i, n, 1, -1) {
		ans = max(ans, seg.get(i) - p[i - 1]);
		seg.add(Point(a[i], p[i - 1] - 1ll * a[i] * i));
	}
	cont(i, n) ans += 1ll * a[i] * i;
	printf("%lld\n", ans);
	return 0;
}

/**
 * 10min
 * 20min
 * 
 *   i  j Pi - Pj + ai(j - i)
 *   i  j P(i - 1) - P(j - 1) + ai(j - i)
 *  
 */