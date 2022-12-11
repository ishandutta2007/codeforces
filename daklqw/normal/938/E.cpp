#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1000010;
const int Dollar1 = 1000000007;
int fac[MAXN], inv[MAXN], n, a[MAXN];
typedef long long LL;

inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % Dollar1; }
inline void add(int & x, const int y) { x += y; if (x >= Dollar1) x -= Dollar1; }
inline int up(const int x) { return x >= Dollar1 ? x - Dollar1 : x; }
int main() {
	inv[0] = inv[1] = fac[0] = fac[1] = 1;
	for (int i = 2; i != MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(Dollar1 - Dollar1 / i, inv[Dollar1 % i]);
	}
	// for (int i = 2; i != MAXN; ++i) inv[i] = mul(inv[i], inv[i - 1]);
	scanf("%d", &n);
	int mn = 0;
	for (int i = 1; i <= n; ++i) scanf("%d", a + i), mn = std::max(mn, a[i]);
	std::sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == mn) continue;
		int ls = std::lower_bound(a + 1, a + 1 + n, a[i]) - a - 1;
		add(ans, mul(a[i], inv[n - ls]));
	}	
	printf("%d\n", mul(ans, fac[n]));
	return 0;
}