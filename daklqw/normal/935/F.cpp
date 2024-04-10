#include <bits/stdc++.h>

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef std::pair<int, int> pi;
LL A[MAXN], sm;
int n, Q;
pi tree[MAXN << 2];
pi gmin(pi a, pi b) { return a < b ? a : b; }
void mdf(int u, int l, int r, int tar, pi v) {
	if (l == r) return (void) (tree[u] = v);
	int mid = l + r >> 1;
	if (tar <= mid) mdf(u << 1, l, mid, tar, v);
	else mdf(u << 1 | 1, mid + 1, r, tar, v);
	tree[u] = gmin(tree[u << 1], tree[u << 1 | 1]);
}
pi qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1;
	pi res(INF, 1);
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = gmin(res, qry(u << 1 | 1, mid + 1, r, L, R));
	return res;
}
pi split(LL a, LL b) {
	int l = std::max(std::min(-a, (LL) INF), 0ll);
	int r = std::max(std::min(b, (LL) INF), 0ll);
	return pi(std::min(l + r, INF + 1), l && r);
}
void upd(int x) {
	mdf(1, 1, n - 2, x, split(A[x], A[x + 1]));
}
void mkadd(int x, int y) {
	sm -= std::abs(A[x]);
	A[x] += y;
	sm += std::abs(A[x]);
	if (x != n - 1) upd(x);
	if (x > 1) upd(x - 1);
}
LL calc(int x, int v) {
	--x;
	LL res = -(std::abs(A[x]) + std::abs(A[x + 1]));
	if (x > 0) res += std::abs(A[x] + v);
	if (x < n - 1) res += std::abs(A[x + 1] - v);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	static int B[MAXN];
	for (int i = 0; i < n; ++i) std::cin >> B[i];
	for (int i = n - 1; i; --i)
		mkadd(i, B[i] - B[i - 1]);
	std::cin >> Q;
	while (Q --> 0) {
		int opt, l, r, x;
		std::cin >> opt >> l >> r >> x;
		if (opt == 1) {
			int _l = std::max(l - 1, 1), _r = std::min(r - 1, n - 2);
			pi res = _l <= _r ? qry(1, 1, n - 2, _l, _r) : pi(INF, 1);
			LL ans = -INF * 1000ll;
			if (x >= res.first) ans = (x - res.first) * 2;
			else {
				if (res.second)
					for (int i = l; i <= r; ++i)
						ans = std::max(ans, calc(i, x));
				else ans = 0;
			}
			if (l == 1) ans = std::max(ans, calc(1, x));
			if (r == n) ans = std::max(ans, calc(n, x));
			std::cout << sm + ans << '\n';
		} else {
			if (l > 1) mkadd(l - 1, x);
			if (r < n) mkadd(r,  -x);
		}
	}
	return 0;
}