#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1 << 17;
int n, r;

struct Segtree {
	int ls[maxn << 7], rs[maxn << 7], nds;
	int dt[maxn << 7];
	void inline add(int a, int x, int &now, int nl = 1, int nr = n) {
		if (!now) now = ++nds, dt[now] = Inf;
		dt[now] = min(dt[now], x);
		if (nl == nr) return;
		int m = (nl + nr) >> 1;
		if (m >= a) add(a, x, ls[now], nl, m);
		else add(a, x, rs[now], m + 1, nr);
	}
	int inline get(int l, int r, int now, int nl = 1, int nr = n) {
		if (!now || nl > r || nr < l) return Inf;
		if (nl >= l && nr <= r) return dt[now];
		int m = (nl + nr) >> 1;
		return min(get(l, r, ls[now], nl, m), get(l, r, rs[now], m + 1, nr));
	}
} seg;

struct ZkwSeg {
	int rt[maxn << 1];
	void inline add(int a, int t, int x) {
		for (a += maxn; a; a >>= 1) seg.add(t, x, rt[a]);
	}
	int inline get(int l, int r, int L, int R) {
		int res = Inf;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = min(res, seg.get(L, R, rt[l++]));
			if (r & 1) res = min(res, seg.get(L, R, rt[--r]));
		}
		return res;
	}
} t;

int a[maxn];
vector<int> nei[maxn];
int dep[maxn];
int bg[maxn], en[maxn], tmc;

void dfs(int now, int lst, int dept) {
	dep[now] = dept;
	bg[now] = ++tmc;
	t.add(dept, bg[now], a[now]);
	parse(to, nei[now]) {
		if (to == lst) continue;
		dfs(to, now, dept + 1);
	}
	en[now] = tmc;
}

int main() {
	scanf("%d%d", &n, &r);
	cont(i, n) scanf("%d", a + i);
	cont(i, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].pub(v); nei[v].pub(u);
	}
	dfs(r, 0, 0);
	int q; scanf("%d", &q);
	int lst = 0;
	while (q--) {
		int x, k; scanf("%d%d", &x, &k);
		x = (x + lst) % n + 1;
		k = (k + lst) % n;
		printf("%d\n", lst = t.get(dep[x], min(dep[x] + k, n), bg[x], en[x]));
	}
	return 0;
}