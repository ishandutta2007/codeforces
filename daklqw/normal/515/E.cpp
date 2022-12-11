#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
LL D[MAXN];
int H[MAXN];
int n, m;
const LL NINF = 0xcfcfcfcfcfcfcfcfLL;
struct info {
	LL lma, rma, ans;
} tr[MAXN << 2];
info operator + (info a, info b) {
	info res;
	res.lma = std::max(a.lma, b.lma);
	res.rma = std::max(a.rma, b.rma);
	res.ans = std::max(a.ans, b.ans);
	res.ans = std::max(res.ans, a.lma + b.rma);
	return res;
}
void build(int u, int l, int r) {
	if (l == r) {
		tr[u].lma = H[l] * 2 - D[l - 1];
		tr[u].rma = H[l] * 2 + D[l - 1];
		tr[u].ans = NINF;
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
const info none = (info) {NINF, NINF, NINF};
info qry(int L, int R, int u = 1, int l = 1, int r = n) {
	if (L > R) return none;
	if (L <= l && r <= R) return tr[u];
	int mid = l + r >> 1;
	info res = none;
	if (L <= mid) res = qry(L, R, u << 1, l, mid);
	if (mid < R) res = res + qry(L, R, u << 1 | 1, mid + 1, r);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> D[i], D[i] += D[i - 1];
	for (int i = 1; i <= n; ++i)
		std::cin >> H[i];
	build(1, 1, n);
	while (m --> 0) {
		int l, r;
		std::cin >> l >> r;
		LL ans = NINF;
		if (l > r) ans = qry(r + 1, l - 1).ans;
		else {
			info rhs = qry(1, l - 1), lhs = qry(r + 1, n);
			lhs.lma += D[n];
			ans = (lhs + rhs).ans;
		}
		std::cout << ans << '\n';
	}
	return 0;
}