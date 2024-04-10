#include <bits/stdc++.h>

const int MAXN = 100010;
const int MAXP = MAXN * 50;
int ls[MAXP], rs[MAXP], tree[MAXP], idx;
int mdf(int u, int l, int r, int tar, int v) {
	int now = ++idx;
	tree[now] = tree[u] + v;
	ls[now] = ls[u], rs[now] = rs[u];
	if (l == r) return now;
	int mid = l + r >> 1;
	if (tar <= mid) ls[now] = mdf(ls[now], l, mid, tar, v);
	else rs[now] = mdf(rs[now], mid + 1, r, tar, v);
	return now;
}
int rt[MAXN];
int kth(int u, int l, int r, int K) {
	if (l == r)
		return K <= tree[u] ? l : l + 1;
	int mid = l + r >> 1;
	if (K > tree[ls[u]])
		return kth(rs[u], mid + 1, r, K - tree[ls[u]]);
	return kth(ls[u], l, mid, K);
}
int R[MAXN], lst[MAXN], n, A[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		R[lst[A[i]]] = i, lst[A[i]] = i;
	}
	for (int i = n; i; --i) {
		rt[i] = rt[i + 1];
		if (R[i]) rt[i] = mdf(rt[i], 1, n, R[i], -1);
		rt[i] = mdf(rt[i], 1, n, i, 1);
	}
	for (int i = 1; i <= n; ++i) {
		int ans = 0, now = 1;
		while (now != n + 1)
			++ans, now = kth(rt[now], 1, n, i + 1);
		std::cout << ans << ' ';
	}
	return 0;
}