#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long double db;

int n, K;
const int MINI = 768;
db dp[2][MINI];

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	std::cout << std::fixed << std::setprecision(15);
	db ans = 0;
	int now = 1, lst = 0;
	dp[now][1] = K;
	for (int i = 1; i <= n; ++i) {
		std::swap(now, lst);
		memset(dp[now], 0, sizeof dp[now]);
		for (int j = 1; j < MINI; ++j) {
			db p1 = dp[lst][j] / K / (j + 1);
			ans += p1 * j;
			ans += dp[lst][j] / K * j / 2;
			if (j + 1 < MINI) dp[now][j + 1] += p1;
			dp[now][j] += dp[lst][j] - p1;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}