#include <bits/stdc++.h>
using namespace std;

long long a[222222];

int main() {
	int n; long long m;
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	long long ans = 0;
	for (int r = 1; r * n <= m; r++) {
		long long cur = m * r - 1LL * r * (r + 1) / 2 * n;
		for (int i = n; i > 0; i--) cur = min(cur, a[i] - r * i);
		if (cur < 1LL * r * (r - 1) / 2 * n) continue;
		cur = min(cur + m - r * n, m * r - 1LL * r * (r + 1) / 2 * n);
		long long sum = 0;
		for (int i = n; i > 0; i--) cur = min(cur, a[i] - r * i), sum += cur + r * i;
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}