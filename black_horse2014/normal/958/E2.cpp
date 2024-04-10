#include <bits/stdc++.h>
using namespace std;

long long a[510000];
pair<long long, long long> dp[2][2];

int main() {
	int m, n; scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	long long lo = -2e9, hi = 2e9;
	long long ans = 1LL<<60;
	while (hi - lo > 1) {
		long long mid = lo + hi >> 1;
		dp[0][0] = dp[0][1] = make_pair(0, 0);
		int now = 0;
		for (int i = 1; i < n; i++) {
			now ^= 1;
			dp[now][1] = make_pair(dp[!now][0].first + a[i+1] - a[i] + mid, dp[!now][0].second - 1);
			dp[now][0] = min(dp[!now][0], dp[!now][1]);
		}
		pair<long long, long long> cur = min(dp[now][0], dp[now][1]);
		if (cur.second <= -m) {
			lo = mid;
			ans = cur.first - mid * m;
		}
		else {
			hi = mid;
		}
	}
	printf("%lld\n", ans);
	return 0;
}