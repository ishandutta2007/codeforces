#include <bits/stdc++.h>

const int MAXN = 100010;
int mod = 998244353;
typedef long long LL;
typedef std::pair<int, int> pi;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
void mma(int & x, int y, int z) { x = (x + (LL) y * z) % mod; }
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }

std::map<int, int> hav;
void solve(int l, int r, int dep) {
	if (l == r || dep <= 1) return (void) (++hav[r - l + 1]);
	int mid = l + r >> 1;
	solve(l, mid, dep - 1); solve(mid + 1, r, dep - 1);
}
inline int calc1(int x) {
	return (LL) pow(4, mod - 2, x * (x - 1ll) % mod);
}
inline int coef(pi x, pi y) {
	int t = x.second;
	if (x.first == y.first) return (LL) t * (t - 1) / 2 % mod;
	return mul(t, y.second);
}
int n, K;
const int MAXS = MAXN << 1;
int inv[MAXS];
inline int calc2(int x, int y) {
	int res = pow(2, mod - 2, mul(x, y));
	for (int i = 1; i <= x; ++i)
		reduce(res -= inv[i + y]), reduce(res += inv[i] - mod);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K >> mod;
	inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXS; ++i)
		inv[i] = mul(inv[mod % i], mod - mod / i);
	for (int i = 1; i != MAXS; ++i)
		reduce(inv[i] += inv[i - 1] - mod);
	solve(1, n, K);
	int ans = 0;
	for (auto t : hav)
		mma(ans, t.second, calc1(t.first));
	for (auto x : hav) for (auto y : hav)
		if (x.first <= y.first)
			mma(ans, coef(x, y), calc2(x.first, y.first));
	std::cout << ans << std::endl;
	return 0;
}