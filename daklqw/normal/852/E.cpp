#include <bits/stdc++.h>

const int MAXN = 100010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int fastpow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int deg[MAXN], n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, t1, t2; i < n; ++i)
		std::cin >> t1 >> t2, ++deg[t1], ++deg[t2];
	int cl = std::count(deg + 1, deg + 1 + n, 1);
	int ans = 0;
	reduce(ans += fastpow(2, n - cl, n - cl) - mod);
	reduce(ans += fastpow(2, n - cl + 1, cl) - mod);
	if (n == 1) ans = 1;
	std::cout << ans << '\n';
	return 0;
}