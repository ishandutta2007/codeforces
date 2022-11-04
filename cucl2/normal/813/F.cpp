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

struct PerUnionFind {
	int fa[1 << 17], tf[1 << 17], de[1 << 17];
	vector<pair<int, int> > op;
	void inline init() {memset(fa, -1, sizeof(fa));}
	PerUnionFind() {init();}
	pair<int, int> inline root(int x) {
		int res = 0;
		while(~fa[x]) res ^= tf[x], x = fa[x];
		return mak(x, res);
	}
	bool inline conn(int a, int b) {
		pair<int, int> Fa = root(a), Fb = root(b);
		a = Fa.first, b = Fb.first;
		if(a == b) return Fa.second ^ Fb.second;
		if(de[a] < de[b]) swap(a, b);
		op.pub(mak(b, de[a]));
		fa[b] = a; tf[b] = Fa.second ^ Fb.second ^ 1;
		de[a] += (de[a] == de[b]);
		return 1;
	}
	int inline size() {return SZ(op);}
	void inline undo() {
		pair<int, int> pr = op.back(); op.pob();
		de[fa[pr.first]] = pr.second;
		fa[pr.first] = -1;
	}
	void inline undo(int siz) {
		while(SZ(op) > siz) undo();
	}
} uf;

int n, q;
map<pair<int, int>, int> st;
vector<pair<int, int> > dt[1 << 19];

void inline add(int l, int r, pair<int, int> x, int now = 1, int nl = 1, int nr = q) {
	if(nl >= l && nr <= r) return void(dt[now].pub(x));
	if(nl > r || nr < l) return;
	int m = (nl + nr) >> 1;
	add(l, r, x, now << 1, nl, m);
	add(l, r, x, now << 1 | 1, m + 1, nr);
}

void inline solve(int now = 1, int nl = 1, int nr = q) {
	int sz = SZ(uf);
	loop(i, SZ(dt[now])) {
		int a = dt[now][i].first, b = dt[now][i].second;
		if(!uf.conn(a, b)) {
			circ(i, nl, nr) puts("NO");
			uf.undo(sz);
			return;
		}
	}
	if(nl == nr) {
		puts("YES");
		uf.undo(sz);
		return;
	}
	int m = (nl + nr) >> 1;
	solve(now << 1, nl, m);
	solve(now << 1 | 1, m + 1, nr);
	uf.undo(sz);
}

int main() {
	scanf("%d%d", &n, &q);
	cont(i, q) {
		int a, b; scanf("%d%d", &a, &b);
		if(st[mak(a, b)]) {
			int l = st[mak(a, b)], r = i - 1;
			add(l, r, mak(a, b));
			st[mak(a, b)] = 0;
		} else {
			st[mak(a, b)] = i;
		}
	}
	foreach(it, st) if(it->second) add(it->second, q, it->first);
	solve();
	return 0;
}