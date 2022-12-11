#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 35010;
struct T {
	int tree[MAXN << 2], tag[MAXN << 2];
	void pushdown(int u) {
		if (tag[u]) {
			tree[u << 1] += tag[u];
			tree[u << 1 | 1] += tag[u];
			tag[u << 1] += tag[u];
			tag[u << 1 | 1] += tag[u];
			tag[u] = 0;
		}
	}
	void modify(int u, int l, int r, int L, int R, int v) {
		if (L > R) return ;
		if (L <= l && r <= R) {
			tree[u] += v;
			tag[u] += v;
			return ;
		}
		pushdown(u);
		int mid = l + r >> 1;
		if (L <= mid) modify(u << 1, l, mid, L, R, v);
		if (mid < R) modify(u << 1 | 1, mid + 1, r, L, R, v);
		tree[u] = std::max(tree[u << 1], tree[u << 1 | 1]);
	}
	int query(int u, int l, int r, int L, int R) {
		if (L > R) return 0;
		if (L <= l && r <= R) return tree[u];
		pushdown(u);
		int mid = l + r >> 1; int res = 0;
		if (L <= mid) res = std::max(res, query(u << 1, l, mid, L, R));
		if (mid < R) res = std::max(res, query(u << 1 | 1, mid + 1, r, L, R));
		return res;
	}
} tree[51];
int n, K, a[MAXN], pre[MAXN], lst[MAXN];
int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
		for (int j = 0; j < K; ++j) {
			tree[j].modify(1, 0, n, pre[i], i - 1, 1);
			int tv = tree[j].query(1, 0, n, 0, i - 1);
			tree[j + 1].modify(1, 0, n, i, i, tv);
			// std::cout << "DP " << i << " " << j << " " << tv << std::endl;
		}
	}
	printf("%d\n", tree[K].query(1, 0, n, n, n));
	return 0;
}