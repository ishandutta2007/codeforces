#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;
int n;
struct linear {
	int A[30];
	void reset() { memset(A, 0, 120); }
	void insert(int x) {
		for (int i = 29; ~i; --i)
			if (x >> i & 1) {
				if (A[i]) {
					x ^= A[i];
				} else {
					A[i] = x;
					return ;
				}
			}
	}
} ;
linear operator + (linear A, linear B) {
	for (int i = 0; i != 30; ++i)
		if (B.A[i])
			A.insert(B.A[i]);
	return A;
}
struct bit {
	int tr[MAXN];
	void add(int x, int v) {
		for (; x <= n; x += x & -x)
			tr[x] ^= v;
	}
	int qry(int x) {
		int r = 0;
		for (; x; x &= x - 1) r ^= tr[x];
		return r;
	}
} tr;
int A[MAXN];
linear rt[MAXN << 2];
void build(int u, int l, int r) {
	if (l == r) {
		rt[u].reset();
		rt[u].insert(A[l]);
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	rt[u] = rt[u << 1] + rt[u << 1 | 1];
}
void upd(int tar) {
	int u = 1, l = 1, r = n;
	while (l != r) {
		int mid = l + r >> 1;
		if (tar <= mid)
			u <<= 1, r = mid;
		else
			u = u << 1 | 1, l = mid + 1;
	}
	rt[u].reset();
	rt[u].insert(A[l]);
	while (u >>= 1)
		rt[u] = rt[u << 1] + rt[u << 1 | 1];
}
linear qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return rt[u];
	int mid = l + r >> 1;
	linear res; res.reset();
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q;
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i];
	for (int i = n; i; --i)
		tr.add(i, A[i] ^= A[i - 1]);
	build(1, 1, n);
	while (Q --> 0) {
		int opt, l, r, v;
		std::cin >> opt >> l >> r;
		if (opt == 1) {
			std::cin >> v;
			A[l] ^= v; upd(l);
			if (r != n) {
				A[r + 1] ^= v; upd(r + 1);
			}
			tr.add(l, v);
			tr.add(r + 1, v);
		} else {
			linear res;
			if (l == r) {
				res.reset();
			} else {
				res = qry(1, 1, n, l + 1, r);
			}
			res.insert(tr.qry(l));
			int ans = 0;
			for (int i = 0; i != 30; ++i)
				ans += res.A[i] > 0;
			std::cout << (1 << ans) << '\n';
		}
	}
	return 0;
}