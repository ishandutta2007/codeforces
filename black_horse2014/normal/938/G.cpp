#include <bits/stdc++.h>
using namespace std;

const int N = 440000;

pair<int, int> query[N];
int edges;
map<pair<int, int> , int> H;
struct edge { int x, y, c, l, r; }E[N];
struct DSU {
	int rnk[N], par[N], odd[N], spoint, stk[2 * N];
	void init() {
		for (int i = 1; i < N; i++) par[i] = i, rnk[i] = 0, odd[i] = 0;
		spoint = 0;
	}
	
	int get(int x) {
		while (x != par[x]) x = par[x];
		return x;
	}
	
	int dis(int x) {
		int res = 0;
		while (x != par[x]) res ^= odd[x], x = par[x];
		return res;
	}
		
	void merge(int x, int y, int c) {
		int px = get(x), py = get(y);
		if (px == py) return;
		int dx = dis(x), dy = dis(y);
		if (rnk[px] > rnk[py]) swap(px, py);
		if (rnk[px] == rnk[py]) {
			rnk[py]++;
			stk[spoint++] = -py;
		}	
		par[px] = py;
		odd[px] = dx ^ dy ^ c;
		stk[spoint++] = px;
	}
	
	void restore(int last) {
		while (spoint > last) {
			int x = stk[--spoint];
			if (x > 0) {
				par[x] = x;
			} else {
				rnk[-x]--;
			}
		}
	}
}dsu;

struct Base {
	int p[31];
	Base() {
		memset(p, 0, sizeof p);
	}
	
	void add(int x) {
		for (int i = 30; i >= 0; i--) if (x >> i & 1) {
			if (!p[i]) {
				p[i] = x;
				break;
			}
			else {
				assert(p[i] >> i & 1);
				x ^= p[i];
			}
		}
	}
	
	int get(int x) {
		for (int i = 30; i >= 0; i--) if (x > (x ^ p[i])) x ^= p[i];
		return x;
	}
};

void solve(int l, int r, int n, Base b) {
	int cur = dsu.spoint;
	for (int i = 1; i <= n; i++) if (E[i].l <= l && E[i].r >= r) {
		int fx = dsu.get(E[i].x), fy = dsu.get(E[i].y);
		if (fx == fy) {
			b.add(dsu.dis(E[i].x) ^ dsu.dis(E[i].y) ^ E[i].c);
		} else {
			dsu.merge(E[i].x, E[i].y, E[i].c);
		}
		swap(E[i--], E[n--]);
	}
	if (l == r) {
		cout << b.get(dsu.dis(query[l].first) ^ dsu.dis(query[l].second)) << endl;
		dsu.restore(cur);
		return;
	}
	int m = l + r >> 1;
	int i, j;
	for (i = 1, j = n; i <= j; i++) if (E[i].l > m) {
		swap(E[i--], E[j--]);
	}
	solve(l, m, j, b);
	for (i = 1, j = n; i <= j; i++)	if (E[i].r <= m) {
		swap(E[i--], E[j--]);
	}
	solve(m + 1, r, j, b);
	dsu.restore(cur);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, c; cin >> x >> y >> c;
		H[{x, y}] = ++edges;
		E[edges] = edge{x, y, c, 1, N};
	}
	int q; cin >> q;
	int qn = 0;
	for (int i = 1; i <= q; i++) {
		int type, x, y; cin >> type >> x >> y;
		if (type == 1) {
			int c; cin >> c;
			H[{x, y}] = ++edges;
			E[edges] = edge{x, y, c, qn + 1, N};
		} else if (type == 2) {
			int cur = H[{x, y}];
			E[cur].r = qn;
			H.erase({x, y});
		} else {
			query[++qn] = {x, y};	
		}
	}
	for (int i = 1; i <= edges; i++) if (E[i].r > qn) E[i].r = qn;
	Base b;
	dsu.init();
	solve(1, qn, edges, b);
	return 0;
}