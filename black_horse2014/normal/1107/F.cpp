#include <bits/stdc++.h>
using namespace std;

const int N = 550;

long long a[N], b[N], c[N];
int id[N];
long long dp[N][N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i], id[i] = i;
	sort(id + 1, id + n + 1, [](int i, int j) {
		return b[i] < b[j];
	});
	const long long inf = 1LL<<60;
	for (int i = 1; i <= n; i++) dp[n+1][i] = -inf;
	dp[n+1][0] = 0;
	long long ans = 0;
	for (int i = n; i > 0; i--) {
		int u = id[i];
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i+1][j];
			if (a[u] - b[u] * c[u] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i+1][j] + a[u] - b[u] * c[u]);
			}
		}
		for (int j = 0; j <= n; j++) {
			if (dp[i+1][j] > -inf) {
				dp[i][j+1] = max(dp[i][j+1], dp[i+1][j] + a[u] - min((long long)j, c[u]) * b[u]);
				ans = max(ans, dp[i][j+1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}