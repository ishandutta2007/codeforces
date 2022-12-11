#include <bits/stdc++.h>

const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
const int MAXN = 3e5 + 10;
int n, m;
int fac[MAXN], inv[MAXN];
int C(int a, int b) {
	return (LL) fac[a] * inv[b] % mod * inv[a - b] % mod;
}
int A[MAXN];
void fma(int & x, int y, int z) {
	x = ((LL) y * z + x) % mod;
}
void fms(int & x, int y, int z) {
	x = ((LL) (mod - y) * z + x) % mod;
}
int calc(int A, int U) {
	if (U < 0) return 0;
	if (A > n - 1) return 0;
	return C(n * 2 - 1, n - 1);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i < MAXN; ++i)
		inv[i] = mul(inv[i - 1], inv[i]);
	std::cin >> n; m = n << 1;
	for (int i = 1; i <= m; ++i)
		std::cin >> A[i];
	std::sort(A + 1, A + 1 + m);
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		fms(ans, calc(i - 1, m - i - 1), A[i]);
		fma(ans, calc(m - i, i - 2), A[i]);
	}
	ans = mul(ans, 2);
	std::cout << ans << std::endl;
	return 0;
}