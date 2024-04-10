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

struct Segtree {
	int dt[1 << 20], wp[1 << 20];
	void inline pd(int now) {
		if(wp[now]) {
			dt[now << 1] = wp[now]; dt[now << 1 | 1] = wp[now];
			wp[now << 1] = wp[now]; wp[now << 1 | 1] = wp[now];
			wp[now] = 0;
		}
	}
	void inline pu(int now) {
		dt[now] = min(dt[now << 1], dt[now << 1 | 1]);
	}
	void inline add(int l, int r, int x, int now = 1, int nl = 0, int nr = (1 << 18) - 1) {
		if(nl >= l && nr <= r) return (void)(dt[now] = x, wp[now] = x);
		if(nl > r || nr < l) return;
		pd(now); int m = (nl + nr) >> 1;
		add(l, r, x, now << 1, nl, m);
		add(l, r, x, now << 1 | 1, m + 1, nr);
		pu(now);
	}
	int inline get(int l, int r, int now = 1, int nl = 0, int nr = (1 << 18) - 1) {
		if(nl >= l && nr <= r) return dt[now];
		if(nl > r || nr < l) return Inf;
		pd(now); int m = (nl + nr) >> 1;
		return min(get(l, r, now << 1, nl, m), get(l, r, now << 1 | 1, m + 1, nr));
	}
} seg, sg;

template<typename num> struct Lissan {
	vector<num> lss; bool built;
	num inline operator[](int id) {return lss[id];}
	void inline clear() {lss.clear(); built = 0;}
	void inline add(num x) {lss.pub(x);}
	void inline build() {sort(all(lss)); lss.erase(unique(all(lss)), lss.end()); built = 1;}
	int inline size() {assert(built); return SZ(lss);} // Don't forget to build before querying.
	int inline get(num x, int th = 0) {assert(built); return lower_bound(all(lss), x) - lss.begin() + th;}
};

const int qwq = 1 << 17;
int n, k, q, m;
int a[qwq];
int mode[qwq], l[qwq], r[qwq], x[qwq];
Lissan<int> lss;

int main() {
	scanf("%d%d", &n, &k);
	cont(i, n) scanf("%d", a + i);
	scanf("%d", &q);
	cont(i, q) {
		scanf("%d", mode + i);
		if(mode[i] == 1) scanf("%d%d%d", l + i, r + i, x + i);
		else scanf("%d%d", l + i, r + i);
		lss.add(l[i]); lss.add(r[i] + 1);
	}
	lss.add(1); lss.add(n * k + 1); lss.build(); m = SZ(lss) - 1;
	loop(i, n) seg.add(i, i, a[i + 1]);
	loop(i, m) {
		int l = lss[i] - 1, r = lss[i + 1] - 2;
		if(r - l + 1 >= n) sg.add(i, i, seg.get(0, n - 1));
		else if(l % n <= r % n) sg.add(i, i, seg.get(l % n, r % n));
		else sg.add(i, i, min(seg.get(l % n, n - 1), seg.get(0, r % n)));
	}
	cont(i, q) {
		int ls = lss.get(l[i]), rs = lss.get(r[i] + 1) - 1;
		if(mode[i] == 1) sg.add(ls, rs, x[i]);
		else printf("%d\n", sg.get(ls, rs));
	}
	return 0;
}