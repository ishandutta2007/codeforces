#include <bits/stdc++.h>

const int MAXN = 2510;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int n, m, A[MAXN], f[100010];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], m += A[i];
	f[1] = pow(m, mod - 2, pow(m - 1, 2));
	for (int i = 1; i <= 100000; ++i)
		f[i + 1] = remod(2ll * f[i] - f[i - 1] - pow(m - i, mod - 2, m - 1));
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		reduce(ans += f[A[i]] - mod);
	std::cout << ans << std::endl;

	return 0;
}