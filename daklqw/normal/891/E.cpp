#include <bits/stdc++.h>

const int MAXN = 5010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
void fma(int & x, int y, int z) {
	x = ((LL) y * z + x) % mod;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }

int n, K, A[MAXN], f[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j; --j)
			f[j] = ((LL) f[j] * A[i] - f[j - 1] + mod) % mod;
		f[0] = mul(f[0], A[i]);
	}
	int ans = 0;
	const int in = pow(n, mod - 2);
	int pw = 1;
	for (int i = 0; i <= n; ++i) {
		if (i) fma(ans, pw, f[i]);
		pw = mul(pw, in);
		pw = mul(pw, K - i);
	}
	reduce(ans = -ans);
	std::cout << ans << '\n';
	return 0;
}