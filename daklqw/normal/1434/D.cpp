#include <bits/stdc++.h>

const int MAXN = 5e5 + 10;
const int INF = 1e7;
void gma(int & x, int y) {
	x < y ? x = y : 0;
}
struct _ {
	int l[2], m, r[2];
	int lm[2], mr[2];
	int lmr;
	void rev() {
		std::swap(l[0], l[1]);
		std::swap(r[0], r[1]);
		std::swap(lm[0], lm[1]);
		std::swap(mr[0], mr[1]);
	}
} tr[MAXN << 3];
int tag[MAXN << 3];
_ operator + (_ a, _ b) {
	_ r;
	r.l[0] = std::max(a.l[0], b.l[0]);
	r.l[1] = std::max(a.l[1], b.l[1]);
	r.r[0] = std::max(a.r[0], b.r[0]);
	r.r[1] = std::max(a.r[1], b.r[1]);
	r.m = std::min(a.m, b.m);
	r.lm[0] = std::max(a.lm[0], b.lm[0]);
	r.lm[1] = std::max(a.lm[1], b.lm[1]);
	r.mr[0] = std::max(a.mr[0], b.mr[0]);
	r.mr[1] = std::max(a.mr[1], b.mr[1]);
	gma(r.lm[0], a.l[0] - b.m * 2);
	gma(r.lm[1], a.l[1] - b.m * 2);
	gma(r.mr[0], b.r[0] - a.m * 2);
	gma(r.mr[1], b.r[1] - a.m * 2);
	r.lmr = std::max(a.lmr, b.lmr);
	gma(r.lmr, a.lm[0] + b.r[0]);
	gma(r.lmr, a.lm[1] + b.r[1]);
	gma(r.lmr, a.l[0] + b.mr[0]);
	gma(r.lmr, a.l[1] + b.mr[1]);
	return r;
}
void mkrev(int u) {
	tag[u] ^= 1;
	tr[u].rev();
}
void pushdown(int u) {
	if (tag[u]) {
		mkrev(u << 1);
		mkrev(u << 1 | 1);
		tag[u] = 0;
	}
}
void mdf(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return mkrev(u);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R);
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
int in[MAXN], out[MAXN], fa[MAXN];
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot = 1;
void adde(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
_ li[MAXN << 1];
int cnt;
void dfs(int u, int d = 0, int dep = 0) {
	_ & t = li[in[u] = ++cnt];
	t.l[d] = t.r[d] = dep;
	t.l[d ^ 1] = t.r[d ^ 1] = -INF;
	t.m = dep;
	t.lm[d] = t.mr[d] = -dep;
	t.lm[d ^ 1] = t.mr[d ^ 1] = -INF - dep * 2;
	t.lmr = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			fa[to[i]] = u;
			dfs(to[i], d ^ val[i], dep + 1);
			li[++cnt] = li[in[u]];
		}
	out[u] = cnt;
}
void build(int u, int l, int r) {
	if (l == r) {
		tr[u] = li[l];
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, x, y, v; i < n; ++i)
		std::cin >> x >> y >> v, adde(x, y, v);
	dfs(1);
	build(1, 1, cnt);
	int m;
	std::cin >> m;
	while (m --> 0) {
		int t; std::cin >> t;
		int x = to[t << 1], y = to[t << 1 | 1];
		if (fa[y] == x) std::swap(x, y);
		mdf(1, 1, cnt, in[x], out[x]);
		std::cout << tr[1].lmr << '\n';
	}
	return 0;
}