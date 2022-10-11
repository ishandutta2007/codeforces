#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long dp[10009][4], n, a[10009]; vector<long long>F[10009][4];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i <= n; i++) { for (int j = 0; j <= 3; j++)dp[i][j] = -(1LL << 60); }
	for (int i = 0; i <= 3; i++) { dp[0][i] = 0; for (int j = 0; j < i; j++)F[0][i].push_back(0); }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 3; j++) {
			if (dp[i][j] == -(1LL << 60))continue;
			for (int k = j; k <= 3; k++) {
				if (j % 2 == 0 && dp[i + 1][k] < dp[i][j] + a[i]) {
					dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + a[i]);
					F[i + 1][k] = F[i][j];
					for (int l = 0; l < k - j; l++)F[i + 1][k].push_back(i + 1);
				}
				if (j % 2 == 1 && dp[i + 1][k] < dp[i][j] - a[i]) {
					dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] - a[i]);
					F[i + 1][k] = F[i][j];
					for (int l = 0; l < k - j; l++)F[i + 1][k].push_back(i + 1);
				}
			}
		}
	}
	cout << F[n][3][0] << " " << F[n][3][1] << " " << F[n][3][2] << endl;
	return 0;
}