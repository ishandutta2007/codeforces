#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Dollar1 = 1000000007;
const int MAXN = 1000010;
typedef long long LL;
inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline int fastpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
int n, k, f[MAXN], ifac[MAXN];
int main() {
	scanf("%d%d", &n, &k);
	int tp = 1; *ifac = ifac[1] = 1;
	for (int i = 1; i <= 2 + k; ++i) {
		f[i] = f[i - 1] + fastpow(i, k) - Dollar1;
		f[i] += f[i] >> 31 & Dollar1;
		tp = mul(tp, n - i);
		if (i > 1) ifac[i] = mul(ifac[Dollar1 % i], Dollar1 - Dollar1 / i);
	}
	for (int i = 2; i <= 2 + k; ++i) ifac[i] = mul(ifac[i - 1], ifac[i]);
	if (n <= k + 2) printf("%d\n", f[n]);
	else {
		int t = 0;
		for (int i = 1, xt = k & 1 ? 1 : Dollar1 - 1; i <= k + 2; ++i, xt = Dollar1 - xt) {
			int x = mul(mul(mul(mul(tp, fastpow(n - i, Dollar1 - 2)), f[i]), mul(ifac[i - 1], ifac[k + 2 - i])), xt);
			t += x - Dollar1;
			t += t >> 31 & Dollar1;
		}
		printf("%d\n", t);
	}
	return 0;
}