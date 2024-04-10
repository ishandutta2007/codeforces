#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 50;
int n, k, a[500005];
ll dp[2][5005][2];
pair<int, int> d[500005];
bool cmp(pair<int, int> t1, pair<int, int> t2) {
	return t1.second < t2.second;
}
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
		d[i].first = a[i + 1] - a[i];
	for (int i = 0; i < n - 1; i++)
		d[i].second = i;
	sort(d, d + n - 1);
	int m = min(3 * k, n - 1);
	sort(d, d + m, cmp);
	for (int j = 1; j <= k; j++)
		for (int f = 0; f < 2; f++)
			dp[0][j][f] = INF;
	dp[0][0][0] = 0;
	dp[0][1][1] = d[0].first;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i & 1][j][0] = min(dp[(i - 1) & 1][j][1], dp[(i - 1) & 1][j][0]);
			dp[i & 1][j][1] = dp[(i - 1) & 1][j - 1][0] + d[i].first;
			if (d[i].second - 1 > d[i - 1].second)
				dp[i & 1][j][1] = min(dp[i & 1][j][1], dp[(i - 1) & 1][j - 1][1] + d[i].first);
		}
	}
	printf("%I64d\n", min(dp[(m - 1) & 1][k][0], dp[(m - 1) & 1][k][1]));
	return 0;
}