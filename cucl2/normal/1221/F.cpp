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

int n, m;
int x[1 << 19], y[1 << 19], c[1 << 19];

template<typename num> struct Lissan {
	vector<num> lss; bool built;
	num inline operator[](int id) {return lss[id];}
	void inline clear() {lss.clear(); built = 0;}
	void inline add(num x) {lss.pub(x);}
	void inline build() {sort(all(lss)); lss.erase(unique(all(lss)), lss.end()); built = 1;}
	int inline size() {assert(built); return SZ(lss);} // Don't forget to build before querying.
	int inline get(num x, int th = 0) {assert(built); return lower_bound(all(lss), x) - lss.begin() + th;}
};

Lissan<int> lss;
vector<pair<int, int> > hv[1 << 20];

struct Segtree {
	pair<ll, ll> dt[1 << 22];
	ll wp[1 << 22];
	void inline pd(int now) {
		if(wp[now]) {
			dt[now << 1].first += wp[now]; dt[now << 1 | 1].first += wp[now];
			wp[now << 1] += wp[now]; wp[now << 1 | 1] += wp[now];
			wp[now] = 0;
		}
	}
	void inline pu(int now) {
		dt[now] = max(dt[now << 1], dt[now << 1 | 1]);
	}
	void inline init(int now = 1, int nl = 0, int nr = m - 1) {
		if(nl == nr) return void(dt[now] = mak(0, lss[nl]));
		int m = (nl + nr) >> 1;
		init(now << 1, nl, m); init(now << 1 | 1, m + 1, nr);
		pu(now);
	}
	void inline add(int l, int r, int x, int now = 1, int nl = 0, int nr = m - 1) {
		if(nl >= l && nr <= r) {
			dt[now].first += x; wp[now] += x;
			return;
		}
		if(nl > r || nr < l) return;
		pd(now); int m = (nl + nr) >> 1;
		add(l, r, x, now << 1, nl, m);
		add(l, r, x, now << 1 | 1, m + 1, nr);
		pu(now);
	}
} seg;

int main() {
	scanf("%d", &n);
	cont(i, n) {
		scanf("%d%d%d", x + i, y + i, c + i);
		lss.add(x[i]); lss.add(y[i]);
	}
	lss.build(); m = SZ(lss); seg.init();
	cont(i, n) {
		if(x[i] > y[i]) swap(x[i], y[i]);
		x[i] = lss.get(x[i]); y[i] = lss.get(y[i]);
		hv[y[i]].pub(mak(x[i], c[i]));
	}
	ll ans = 0;
	int al = 2e9, ar = 2e9;
	loop(i, m) {
		foreach(j, hv[i]) seg.add(0, j->first, j->second);
		seg.add(i, i, lss[i]);
		seg.add(0, i, -lss[i]);
		if(ans < seg.dt[1].first) {
			ans = seg.dt[1].first;
			al = seg.dt[1].second; ar = lss[i];
		}
		seg.add(0, i, lss[i]);
	}
	printf("%lld\n", ans);
	printf("%d %d %d %d\n", al, al, ar, ar);
	return 0;
}

/**
 * 
 *  (x, y) => [min(x, y), max(x, y)]
 *   i
 *    i 
 *    i  I
 *    i  I max
 *    i  I
 */