#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3333;
const int MAXM = 333;

double p[MAXN][MAXM], dp[MAXN][MAXM];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lf", &p[i][j]);
			p[i][j] /= 1000;
		}
	}
	for (int i = 1; i <= m; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i-1][j] * (1-p[i][j]);
		}
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = min_element(dp[n]+1, dp[n]+m+1) - dp[n];
		ans += 1 - dp[n][x];
		double cur = 1;
		for (int j = 0; j <= n; j++) {
			double now = cur * (1-p[j+1][x]) + dp[j][x] * p[j+1][x];
			dp[j][x] = cur, cur = now;
		}
	}
	printf("%.20lf\n", ans);
	return 0;
}