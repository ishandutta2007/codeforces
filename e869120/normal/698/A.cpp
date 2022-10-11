#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1 << 18], dp[1 << 18][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) { for (int j = 0; j < 3; j++) dp[i][j] = (1 << 30); }
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if ((a[i] == 1 || a[i] == 3) && j != 1) {
				dp[i + 1][1] = min(dp[i + 1][1], dp[i][j]);
			}
			if ((a[i] == 2 || a[i] == 3) && j != 2) {
				dp[i + 1][2] = min(dp[i + 1][2], dp[i][j]);
			}
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
		}
	}
	int minx = (1 << 30);
	for (int i = 0; i < 3; i++) minx = min(minx, dp[n][i]);
	cout << minx << endl;
	return 0;
}