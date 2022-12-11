#include <bits/stdc++.h>

const int MAXN = 1e6 + 10;

void bye() {
	std::cout << "IMPOSSIBLE" << std::endl;
	exit(0);
}
struct info {
	int v, at;
} tr[MAXN << 2];
info operator + (info a, info b) {
	return a.v < b.v ? a : b;
}
int tag[MAXN << 2];
void mkadd(int x, int v) {
	tr[x].v += v;
	tag[x] += v;
}
void pushdown(int u) {
	if (int & t = tag[u]) {
		mkadd(u << 1, t);
		mkadd(u << 1 | 1, t);
		t = 0;
	}
}
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return mkadd(u, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
info qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tr[u];
	int mid = l + r >> 1;
	pushdown(u);
	info res = (info) {0x3f3f3f3f, -1};
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
void build(int u, int l, int r) {
	tr[u].at = l;
	if (l == r) return ;
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}
std::vector<int> out[MAXN][2];
int n, m;
int ansl[MAXN], bak;
void solve(int l, int r) {
	if (l >= r) {
		if (l == r)
			ansl[++bak] = l;
		return ;
	}
	std::sort(out[l][0].begin(), out[l][0].end());
	std::sort(out[l][1].begin(), out[l][1].end());
	int L = l, R = r + 1;
	if (!out[l][0].empty())
		L = out[l][0].back();
	if (!out[l][1].empty())
		R = out[l][1][0];
	if (L >= R) bye();
	for (auto t : out[l][0])
		mdf(1, 1, n, l, t - 1, -1);
	for (auto t : out[l][1])
		mdf(1, 1, n, l, t - 1, -1);
	info ret = qry(1, 1, n, L, R - 1);
	if (ret.v >= 1) bye();
	solve(l + 1, ret.at);
	ansl[++bak] = l;
	solve(ret.at + 1, r);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		int x, y; static char buf[100];
		std::cin >> x >> y >> buf;
		if (x >= y) bye();
		out[x][*buf == 'R'].push_back(y);
		mdf(1, 1, n, x, y - 1, 1);
	}
	solve(1, n);
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] << (" \n" [i == n]);
	return 0;
}