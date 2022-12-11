#include <bits/stdc++.h>

const int MAXN = 200010;

int head[MAXN], nxt[MAXN];
int ST[19][MAXN << 1], in[MAXN], bak;
inline int gmi(int x, int y) { return in[x] < in[y] ? x : y; }
int LCA(int x, int y) {
	if ((x = in[x]) > (y = in[y])) std::swap(x, y);
	const int L = std::__lg(y - x + 1);
	return gmi(ST[L][x], ST[L][y - (1 << L) + 1]);
}
void dfs(int u) {
	ST[0][++bak] = u; in[u] = bak;
	for (int i = head[u]; i; i = nxt[i])
		dfs(i), ST[0][++bak] = u;
}
int A[MAXN], fa[MAXN];
struct info {
	int x, y;
	info join(int z) {
		if (!x || !z) return (info) {0, 0};
		int l = LCA(x, y) ^ LCA(x, z) ^ LCA(y, z);
		if (l == x) return (info) {y, z};
		if (l == y) return (info) {x, z};
		if (l == z) return (info) {x, y};
		return (info) {0, 0};
	}
	friend info operator + (info a, info b) {
		return a.join(b.x).join(b.y);
	}
} tree[MAXN << 2];
void mdf(int u, int l, int r, int tar, int v) {
	if (l == r) return (void) (tree[u] = (info) {v, v});
	int mid = l + r >> 1;
	if (tar <= mid) mdf(u << 1, l, mid, tar, v);
	else mdf(u << 1 | 1, mid + 1, r, tar, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
int qry(int u, int l, int r, info pre) {
	if (l == r) return (pre + tree[u]).x ? l : l - 1;
	int mid = l + r >> 1;
	info res = pre + tree[u << 1];
	if (res.x) return qry(u << 1 | 1, mid + 1, r, res);
	return qry(u << 1, l, mid, pre);
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], ++A[i];
	for (int i = 2; i <= n; ++i)
		std::cin >> fa[i], nxt[i] = head[fa[i]], head[fa[i]] = i;
	dfs(1);
	for (int i = 1; i != 19; ++i)
		for (int j = 1; (1 << i) + j - 1 <= bak; ++j)
			ST[i][j] = gmi(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	int at = 0;
	for (int i = 1; i <= n; ++i) {
		mdf(1, 1, n, A[i], i);
		if (A[i] == 1) at = i;
	}
	int Q; std::cin >> Q;
	while (Q --> 0) {
		int opt, x, y;
		std::cin >> opt;
		if (opt == 2) {
			std::cout << qry(1, 1, n, (info) {at, at}) << '\n';
		} else {
			std::cin >> x >> y;
			std::swap(A[x], A[y]);
			mdf(1, 1, n, A[x], x);
			mdf(1, 1, n, A[y], y);
			if (A[x] == 1) at = x;
			if (A[y] == 1) at = y;
		}
	}
	return 0;
}