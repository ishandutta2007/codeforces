#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
using namespace std;
int n, m, p, a[1009], b[2009], dp[1009][2009];
int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= m; i++)cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (int i = 0; i < 1009; i++) { for (int j = 0; j < 2009; j++)dp[i][j] = 2.1e9; }
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			int D = abs(a[i + 1] - b[j + 1]) + abs(b[j + 1] - p);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], D));
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}