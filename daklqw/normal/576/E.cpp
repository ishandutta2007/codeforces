#include <bits/stdc++.h>

const int MAXN = 500010;
int st[MAXN], ids[MAXN], top;
struct dsu {
	int idx;
	int fa[MAXN], sz[MAXN]; bool fae[MAXN];
	void init(int ix, int n) {
		idx = ix;
		for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
	}
	std::pair<int, int> find(int x) {
		int res = 0;
		while (x != fa[x]) res ^= fae[x], x = fa[x];
		return std::make_pair(x, res);
	}
	void pop() {
		int x = st[top], y = fa[x];
		sz[y] -= sz[x]; fa[x] = x; fae[x] = 0;
		--top;
	}
	bool link(int x, int y) {
		int ex, ey;
		std::tie(x, ex) = find(x);
		std::tie(y, ey) = find(y);
		if (x != y) {
			if (sz[x] > sz[y]) std::swap(x, y);
			st[++top] = x, ids[top] = idx;
			fae[x] = ex ^ ey ^ 1;
			sz[y] += sz[x];
			fa[x] = y;
			return true;
		}
		return (ex ^ ey) == 1;
	}
} ss[51];
int n, m, K, Q;
int xs[MAXN], ys[MAXN];
int col[MAXN], lst[MAXN], disa[MAXN];
const int MAXQ = MAXN * 50;
struct qry { int id, c; } fir[MAXN];
int qh[MAXN << 2], qn[MAXQ], qt[MAXQ], tot;
int pre[MAXN], faqry[MAXN], elst[MAXN];
int find(int x) { return x == faqry[x] ? x : faqry[x] = find(faqry[x]); }
void addq(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		qn[++tot] = qh[u]; qt[qh[u] = tot] = v;
		return ;
	}
	int mid = l + r >> 1;
	if (L <= mid) addq(u << 1, l, mid, L, R, v);
	if (mid < R) addq(u << 1 | 1, mid + 1, r, L, R, v);
}
void addq(int l, int r, int id) {
	fir[l] = (qry) {id, col[id]}; faqry[l] = l;
	pre[l] = elst[id]; elst[id] = l;
	if (l + 1 <= r) addq(1, 1, Q, l + 1, r, l);
}
void solve(int u, int l, int r) {
	int nowtop = top;
	for (int i = qh[u]; i; i = qn[i]) {
		const int v = find(qt[i]);
		if (v) {
			const qry t = fir[v];
			ss[t.c].link(xs[t.id], ys[t.id]);
		}
	}
	if (l == r) {
		static qry t; t = fir[l];
		disa[l] = !ss[t.c].link(xs[t.id], ys[t.id]);
		if (disa[l]) faqry[l] = pre[faqry[l]];
	} else {
		int mid = l + r >> 1;
		solve(u << 1, l, mid); solve(u << 1 | 1, mid + 1, r);
	}
	while (top > nowtop) ss[ids[top]].pop();
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K >> Q;
	for (int i = 1; i <= K; ++i) ss[i].init(i, n);
	for (int i = 1; i <= m; ++i)
		std::cin >> xs[i] >> ys[i];
	for (int i = 1, e, v; i <= Q; ++i) {
		std::cin >> e >> v;
		if (col[e]) addq(lst[e], i - 1, e);
		col[e] = v, lst[e] = i;
	}
	for (int i = 1; i <= m; ++i) if (col[i])
		addq(lst[i], Q, i);
	solve(1, 1, Q);
	const char out[][10] = {"YES", "NO"};
	for (int i = 1; i <= Q; ++i)
		std::cout << out[disa[i]] << '\n';
	return 0;
}