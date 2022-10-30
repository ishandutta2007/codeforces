#include <bits/stdc++.h>
using namespace std;

int main() {
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		int n; scanf("%d", &n);
		long long ans = 1LL * n * (n + 1) / 2;
		for (int x = 1; x <= n; x <<= 1) ans -= 2 * x;
		printf("%lld\n", ans);
	}
	return 0;
}