#include <bits/stdc++.h>

const int MAXN = 300010;
int n, m;
void gmi(int & x, int y) { x > y ? x = y : 0; }
struct sgt1 {
	int tree[MAXN << 2];
	sgt1() { memset(tree, 0x3f, sizeof tree); }
	void mdf(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) return gmi(tree[u], v);
		int mid = l + r >> 1;
		if (L <= mid) mdf(u << 1, l, mid, L, R, v);
		if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	}
	int qry(int u, int l, int r, int tar) {
		if (l == r) return tree[u];
		int mid = l + r >> 1;
		if (tar <= mid)
			return std::min(tree[u], qry(u << 1, l, mid, tar));
		return std::min(tree[u], qry(u << 1 | 1, mid + 1, r, tar));
	}
} sg;
struct sgt2 {
	int tree[MAXN << 2];
	void mdf(int u, int l, int r, int tar, int v) {
		if (l == r) return (void) (tree[u] = v);
		int mid = l + r >> 1;
		if (tar <= mid) mdf(u << 1, l, mid, tar, v);
		else mdf(u << 1 | 1, mid + 1, r, tar, v);
		tree[u] = std::max(tree[u << 1], tree[u << 1 | 1]);
	}
	int qry(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) return tree[u];
		int mid = l + r >> 1, res = 0;
		if (L <= mid) res = qry(u << 1, l, mid, L, R);
		if (mid < R) res = std::max(res, qry(u << 1 | 1, mid + 1, r, L, R));
		return res;
	}
} s2;
int lim[MAXN];
int opt[MAXN], ls[MAXN], rs[MAXN], xs[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	memset(lim, -1, sizeof lim);
	for (int i = 1; i <= m; ++i) {
		std::cin >> opt[i] >> ls[i] >> rs[i];
		if (opt[i] == 1) {
			std::cin >> xs[i];
			sg.mdf(1, 1, n, ls[i], rs[i], xs[i]);
		} else if (lim[ls[i]] == -1)
			lim[ls[i]] = sg.qry(1, 1, n, ls[i]);
	}
	for (int i = 1; i <= n; ++i) if (lim[i] == -1)
		lim[i] = sg.qry(1, 1, n, i);
	for (int i = 1; i <= n; ++i) s2.mdf(1, 1, n, i, lim[i]);
	std::set<int> L;
	for (int i = 1; i <= m; ++i) {
		if (opt[i] == 1) {
			if (xs[i] != s2.qry(1, 1, n, ls[i], rs[i]))
				return std::cout << "NO" << std::endl, 0;
			L.insert(xs[i]);
		} else s2.mdf(1, 1, n, ls[i], rs[i]);
	}
	int ox = 0;
	std::vector<int> li;
	for (int i = 1; i <= n; ++i)
		if (!L.count(lim[i])) li.push_back(i);
		else L.erase(lim[i]), ox |= lim[i];
	for (auto i : li) {
		const int U = 1000000000;
		int nx = 0, up = std::min(lim[i], U);
		for (int j = 30; ~j; --j)
			if ((nx | 1 << j) <= up && !(ox >> j & 1))
				nx |= 1 << j;
		lim[i] = nx;
		ox |= lim[i];
	}
	std::cout << "YES" << std::endl;
	for (int i = 1; i <= n; ++i) std::cout << lim[i] << ' ';
	return 0;
}