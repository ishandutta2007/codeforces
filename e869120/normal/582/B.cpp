#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, T, a[1000], dp[110000][301], dp2[110000][301];
int main() {
	cin >> n >> T;
	for (int i = 0; i < n; i++)cin >> a[i];

	if (T <= 1000) {
		vector<int>J; for (int i = 0; i < n * T; i++)J.push_back(a[i%n]);
		for (int i = 0; i < J.size(); i++) {
			for (int j = 0; j <= 300; j++)dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			for (int j = 0; j <= J[i]; j++)dp[i + 1][J[i]] = max(dp[i + 1][J[i]], dp[i][j] + 1);
		}
		int ret = 0; for (int j = 0; j <= 300; j++)ret = max(ret, dp[J.size()][j]);
		cout << ret << endl;
	}
	else {
		vector<int>J; for (int i = 0; i < n * 500; i++)J.push_back(a[i%n]);
		for (int i = 0; i < J.size(); i++) {
			for (int j = 0; j <= 300; j++)dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			for (int j = 0; j <= J[i]; j++)dp[i + 1][J[i]] = max(dp[i + 1][J[i]], dp[i][j] + 1);
		}
		reverse(J.begin(), J.end());
		for (int i = 0; i < J.size(); i++) {
			for (int j = 0; j <= 300; j++)dp2[i + 1][j] = max(dp2[i + 1][j], dp2[i][j]);
			for (int j = J[i]; j <= 300; j++)dp2[i + 1][J[i]] = max(dp2[i + 1][J[i]], dp2[i][j] + 1);
		}
		for (int i = 1; i <= 300; i++)dp[J.size()][i] = max(dp[J.size()][i], dp[J.size()][i - 1]);
		for (int i = 300; i >= 1; i--)dp2[J.size()][i] = max(dp2[J.size()][i], dp2[J.size()][i + 1]);

		int ret = 0;
		for (int i = 1; i <= 300; i++) {
			int cnt = 0; for (int j = 0; j < n; j++) { if (a[j] == i)cnt++; }
			ret = max(ret, dp[J.size()][i] + dp2[J.size()][i] + (T - 1000)*cnt);
		}
		cout << ret << endl;
	}
	return 0;
}