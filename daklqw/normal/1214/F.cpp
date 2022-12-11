#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
int n, R;
struct node {
	LL at; int id;
	bool operator < (node b) const { return at < b.at; }
} as[MAXN], bs[MAXN];
int ansl[MAXN];
LL pre1[MAXN], pre2[MAXN], * pre;
void _mkadd(int l, int r, int v) {
	// std::cout << "_MKADD " << l << ' ' << r << ' ' << v << std::endl;
	pre[l] += v, pre[r + 1] -= v;
}
void mkadd(int l, int r, int v, int dta) {
	if (l >= r) return ;
	--r;
	// std::cout << "MKADD " << l << ' ' << r << ' ' << v << ' ' << dta << std::endl;
	l = (l - 1 - dta + n) % n + 1;
	r = (r - 1 - dta + n) % n + 1;
	if (l <= r) _mkadd(l, r, v);
	else _mkadd(1, r, v), _mkadd(l, n, v);
}
void pusharr(int at, node * dst, int dta) {
	// std::cout << at << (dst == as ? " to as" : " to bs") << std::endl;
	node * it;
	if (dst == bs)
		it = std::lower_bound(dst + 1, dst + 1 + n, (node) {at << 1, 0});
	else
		it = std::upper_bound(dst + 1, dst + 1 + n, (node) {at << 1, 0});
	node * lhs = std::upper_bound(dst + 1, it, (node) {2 * at - R, 0});
	node * rhs = std::lower_bound(it, dst + 1 + n, (node) {2ll * at + R, 0});
	const int delta = (dst != as) * R;
	// std::cout << "GET " << lhs - dst << ' ' << it - dst << ' ' << rhs - dst << std::endl;
	mkadd(1, lhs - dst, delta - at, dta);
	mkadd(lhs - dst, it - dst, at, dta);
	mkadd(it - dst, rhs - dst, -at, dta);
	mkadd(rhs - dst, 1 + n, delta + at, dta);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> R >> n;
	for (int i = 1; i <= n; ++i) as[i].id = i, std::cin >> as[i].at;
	for (int i = 1; i <= n; ++i) bs[i].id = i, std::cin >> bs[i].at;
	std::sort(as + 1, as + 1 + n);
	std::sort(bs + 1, bs + 1 + n);
	for (int i = 1; i <= n; ++i) as[i].at <<= 1, bs[i].at <<= 1;
	for (int i = 1; i <= n; ++i) {
		pre = pre1, pusharr(as[i].at >> 1, bs, i - 1);
		pre = pre2, pusharr(bs[i].at >> 1, as, i - 1);
	}
	LL ans = 0x3f3f3f3f3f3f3f3fLL; int at = 1;
	for (int i = 1; i <= n; ++i)
		pre1[i] += pre1[i - 1], pre2[i] += pre2[i - 1];
	for (int i = 1; i <= n; ++i) {
		LL now = pre1[i] + pre2[i > 1 ? n - i + 2 : 1];
		// std::cout << now << ' ';
		if (now < ans) ans = now, at = i;
	}
	// std::cout << std::endl;
	for (int i = 1; i <= n; ++i)
		ansl[as[i].id] = bs[(i + at - 2) % n + 1].id;
	std::cout << ans << std::endl;
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] << ' ';
	std::cout << std::endl;
	return 0;
}