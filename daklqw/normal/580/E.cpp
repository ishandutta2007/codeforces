#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
const int mod1 = 998244353;
const int mod2 = 1004535809;

typedef long long LL;
int pow(int a, int b, int mod) {
	int r = 1;
	for (; b; b >>= 1, a = (LL) a * a % mod)
		if (b & 1) r = (LL) a * r % mod;
	return r;
}

struct info {
	int v1, p1, v2, p2;
} tr[MAXN << 2];
const info none = (info) {0, 1, 0, 1};
bool operator == (info a, info b) {
	return a.v1 == b.v1 && a.v2 == b.v2;
}
info operator + (info a, info b) {
	info res;
	res.v1 = ((LL) a.v1 * b.p1 + b.v1) % mod1;
	res.v2 = ((LL) a.v2 * b.p2 + b.v2) % mod2;
	res.p1 = (LL) a.p1 * b.p1 % mod1;
	res.p2 = (LL) a.p2 * b.p2 % mod2;
	return res;
}
int tag[MAXN << 2];

int pre1[MAXN], pre2[MAXN], pw1[MAXN], pw2[MAXN];
void mkset(int u, int L, int v) {
	tr[u].v1 = (LL) pre1[L] * v % mod1;
	tr[u].p1 = pw1[L];
	tr[u].v2 = (LL) pre2[L] * v % mod2;
	tr[u].p2 = pw2[L];
	tag[u] = v;
}
void pushdown(int u, int L) {
	if (int & t = tag[u]) {
		mkset(u << 1, L + 1 >> 1, t);
		mkset(u << 1 | 1, L >> 1, t);
		t = 0;
	}
}
int n;
void mdf(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) return mkset(u, r - l + 1, v);
	int mid = l + r >> 1;
	pushdown(u, r - l + 1);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}
info get(int L, int R, int u = 1, int l = 1, int r = n) {
	if (L <= l && r <= R) return tr[u];
	int mid = l + r >> 1;
	pushdown(u, r - l + 1);
	info res = none;
	if (L <= mid) res = get(L, R, u << 1, l, mid);
	if (mid < R) res = res + get(L, R, u << 1 | 1, mid + 1, r);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int Q, _;
	std::cin >> n >> Q >> _; Q += _;
	const int bse1 = 21312, bse2 = 3123;
	*pw1 = *pw2 = 1;
	for (int i = 1; i <= n; ++i) {
		pw1[i] = pow(bse1, i, mod1);
		pw2[i] = pow(bse2, i, mod2);
		pre1[i] = (pre1[i - 1] + pw1[i - 1]) % mod1;
		pre2[i] = (pre2[i - 1] + pw2[i - 1]) % mod2;
	}
	static char buf[MAXN];
	std::cin >> buf;
	for (int i = 0; i < n; ++i)
		mdf(1, 1, n, i + 1, i + 1, buf[i]);
	while (Q --> 0) {
		int opt, l, r, v;
		std::cin >> opt >> l >> r >> v;
		if (opt == 1)
			mdf(1, 1, n, l, r, v + '0');
		else {
			bool can = v == r - l + 1 ? true : get(l, r - v) == get(l + v, r);
			std::cout << (can ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}