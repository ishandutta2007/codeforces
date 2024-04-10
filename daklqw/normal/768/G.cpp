#include <bits/stdc++.h>

const int MAXN = 100010;
const int MAXP = MAXN * 256;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot, n;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int ls[MAXP], rs[MAXP], val[MAXP], idx;
int modify(int u, int l, int r, int tar, int v) {
	int now = ++idx;
	ls[now] = ls[u], rs[now] = rs[u], val[now] = val[u] + v;
	if (l == r) return now;
	int mid = l + r >> 1;
	if (tar <= mid) ls[now] = modify(ls[u], l, mid, tar, v);
	else rs[now] = modify(rs[u], mid + 1, r, tar, v);
	return now;
}
int merge(int x, int y) {
	if (!x || !y) return x | y;
	int now = ++idx;
	val[now] = val[x] + val[y];
	ls[now] = merge(ls[x], ls[y]);
	rs[now] = merge(rs[x], rs[y]);
	return now;
}
int rt[MAXP], sz[MAXN], fa[MAXN];
void dfs1(int u) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa[u]) {
		fa[to[i]] = u, dfs1(to[i]), sz[u] += sz[to[i]];
		rt[u] = merge(rt[u], rt[to[i]]);
	}
	rt[u] = modify(rt[u], 1, n, sz[u], 1);
}
int right(int u, int d, int l, int r, int L) {
	if (r < L) return -1;
	if (L <= l) {
		if (val[u] - val[d] > 0) {
			while (l < r) {
				int mid = l + r >> 1;
				if (val[ls[u]] - val[ls[d]] > 0) { r = mid; u = ls[u], d = ls[d]; }
				else { l = mid + 1; u = rs[u], d = rs[d]; }
			}
			return l;
		}
		return -1;
	}
	int mid = l + r >> 1, res = -1;
	res = right(ls[u], ls[d], l, mid, L);
	if (res != -1) return res;
	return right(rs[u], rs[d], mid + 1, r, L);
}
int left(int u, int d, int l, int r, int R) {
	if (R < l) return -1;
	if (r <= R) {
		if (val[u] - val[d] > 0) {
			while (l < r) {
				int mid = l + r >> 1;
				if (val[rs[u]] - val[rs[d]] > 0) { l = mid + 1; u = rs[u], d = rs[d]; }
				else { r = mid; u = ls[u], d = ls[d]; }
			}
			return l;
		}
		return -1;
	}
	int mid = l + r >> 1, res = -1;
	res = left(rs[u], rs[d], mid + 1, r, R);
	if (res != -1) return res;
	return left(ls[u], ls[d], l, mid, R);
}
int qry(int u, int d, int A, int B, int cannot) {
	int x = A - B >> 1;
	int r = x <= n ? right(u, d, 1, n, std::max(x, 1)) : -1;
	if (r == cannot) r = -1;
	int l = x >= 1 ? left(u, d, 1, n, std::min(x, n)) : -1;
	int ret = 0x3f3f3f3f;
	if (r != -1) ret = std::min(ret, std::max(A - r, B + r));
	if (l != -1) ret = std::min(ret, std::max(A - l, B + l));
	return ret;
}
int ansl[MAXN];
void dfs2(int u, int tort, int rtd) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u])
		dfs2(to[i], modify(tort, 1, n, sz[u], 1), modify(rtd, 1, n, sz[u], -1));
	std::vector<std::pair<int, int> > V;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u])
		V.emplace_back(sz[to[i]], to[i]);
	if (fa[u]) V.emplace_back(n - sz[u], fa[u]);
	std::sort(V.begin(), V.end());
	if (V.size() < 2) { ansl[u] = V.begin() -> first; return ; }
	int hu = (V.end() - 1) -> second, mv = (V.end() - 2) -> first;
	int shu = V.back().first, sle = V.begin() -> first;
	int res = shu;
	if (hu != fa[u]) res = std::min(res, qry(rt[hu], 0, shu, sle, shu));
	else {
		res = std::min(res, qry(rtd, rt[u], shu, sle, -1));
		res = std::min(res, qry(tort, 0, shu + sz[u], sle - sz[u], n));
	}
	ansl[u] = std::max(mv, res);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	if (n == 1) return std::cout << 0 << std::endl, 0;
	int r = -1;
	for (int i = 1, t1, t2; i <= n; ++i) {
		std::cin >> t1 >> t2;
		if (t1 == 0) r = t2;
		else addedge(t1, t2);
	}
	dfs1(r); dfs2(r, 0, rt[r]);
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}