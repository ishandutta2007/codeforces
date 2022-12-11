#include <bits/stdc++.h>

const int MAXN = 200010;
const int INF = 0x3f3f3f3f;

int n;
int li[MAXN << 1], bak;
struct graph {
	int fa[MAXN], head[MAXN], nxt[MAXN];
	int in[MAXN], out[MAXN];
	int idx, ST[19][MAXN << 1];
	int dep[MAXN];
	int gmi(int x, int y) {
		return in[x] < in[y] ? x : y;
	}
	int dfn[MAXN], t0t;
	void dfs(int u) {
		ST[0][++idx] = u;
		in[u] = idx;
		dfn[u] = ++t0t;
		for (int i = head[u]; i; i = nxt[i])
			dep[i] = dep[u] + 1, dfs(i), ST[0][++idx] = u;
		out[u] = t0t;
	}
	int LCA(int l, int r) {
		if ((l = in[l]) > (r = in[r])) std::swap(l, r);
		const int L = std::__lg(++r - l);
		return gmi(ST[L][l], ST[L][r - (1 << L)]);
	}
	void init() {
		for (int i = 2; i <= n; ++i)
			std::cin >> fa[i], nxt[i] = head[fa[i]], head[fa[i]] = i;
		dfs(1);
		for (int i = 1; i != 19; ++i)
			for (int j = 1; j + (1 << i) - 1 <= idx; ++j)
				ST[i][j] = gmi(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	}
	int mi[MAXN << 2];
	inline void update(int u) {
		mi[u] = std::min(mi[u << 1], mi[u << 1 | 1]);
	}
	graph() { memset(mi, 0x3f, sizeof mi); }
	typedef std::pair<int, int> pi;
	std::set<pi> ss[MAXN];
	void upd(int u, std::set<pi> & s) {
		mi[u] = s.empty() ? INF : s.begin()->first;
	}
	void mdf(int tar, pi v, bool typ = false) {
		int u = 1, l = 1, r = n;
		while (l != r) {
			int mid = l + r >> 1;
			if (tar <= mid) u <<= 1, r = mid;
			else u = u << 1 | 1, l = mid + 1;
		}
		if (typ) ss[l].erase(v);
		else ss[l].insert(v);
		upd(u, ss[l]);
		while (u >>= 1) update(u);
	}
	void _mkdel(int u, int K, int l, int r) {
		if (mi[u] > K) return ;
		if (l == r) {
			while (mi[u] <= K) {
				li[++bak] = ss[l].begin()->second;
				ss[l].erase(ss[l].begin());
				upd(u, ss[l]);
			}
			return ;
		}
		int mid = l + r >> 1;
		_mkdel(u << 1, K, l, mid);
		_mkdel(u << 1 | 1, K, mid + 1, r);
		update(u);
	}
	void mkdel(int L, int R, int K, int u = 1, int l = 1, int r = n) {
		if (L <= l && r <= R) return _mkdel(u, K, l, r);
		int mid = l + r >> 1;
		if (L <= mid) mkdel(L, R, K, u << 1, l, mid);
		if (mid < R) mkdel(L, R, K, u << 1 | 1, mid + 1, r);
		update(u);
	}
	struct _ {
		int x, y, L;
	} es[MAXN];
	void mdfqry(_ e, bool typ = false) {
		if (e.x != e.L) mdf(dfn[e.x], pi(dep[e.L], e.x), typ);
		if (e.y != e.L) mdf(dfn[e.y], pi(dep[e.L], e.x), typ);
	}
	void initqry(graph & rhs) {
		for (int i = 2; i <= n; ++i) {
			es[i].x = i, es[i].y = fa[i];
			es[i].L = rhs.LCA(i, fa[i]);
			rhs.mdfqry(es[i]);
		}
	}
	void mkdel(int u) {
		mkdel(dfn[u], out[u], dep[fa[u]]);
	}
} gs[2];

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	gs[0].init();
	gs[1].init();
	gs[0].initqry(gs[1]);
	gs[1].initqry(gs[0]);
	std::cin >> li[bak = 1]; ++li[1];
	for (int now = 0, lst = 1; bak; now ^= 1, lst ^= 1) {
		std::cout << (now == 0 ? "Blue" : "Red") << '\n';
		std::sort(li + 1, li + 1 + bak);
		bak = std::unique(li + 1, li + 1 + bak) - li - 1;
		for (int j = 1; j <= bak; ++j)
			std::cout << (li[j] - 1) << (" \n" [j == bak]);
		static int tmp[MAXN], cb;
		cb = bak;
		std::copy(li + 1, li + 1 + bak, tmp + 1);
		bak = 0;
		for (int j = 1; j <= cb; ++j) {
			const int u = tmp[j];
			gs[lst].mdfqry(gs[now].es[u], true);
			gs[now].mkdel(u);
		}
	}
	return 0;
}