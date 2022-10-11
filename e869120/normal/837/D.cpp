#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int dp[209][18001], prev_[209][18001], n, p; long long a[209]; int x[209], y[209];
int main() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (a[i] % 5 == 0) { a[i] /= 5; y[i]++; }
		while (a[i] % 2 == 0) { a[i] /= 2; x[i]++; }
	}
	for (int i = 0; i <= 200; i++) { for (int j = 0; j <= 18000; j++) { prev_[i][j] = -1; dp[i][j] = -1; } }prev_[0][6000] = 0;
	for (int h = 0; h < n; h++) {
		for (int i = 0; i <= p; i++) {
			for (int j = 0; j <= 18000; j++) {
				if (prev_[i][j] == -1)continue;
				dp[i][j] = max(dp[i][j], prev_[i][j]);
				dp[i + 1][j + x[h] - y[h]] = max(dp[i + 1][j + x[h] - y[h]], prev_[i][j] + x[h] + y[h]);
			}
		}
		for (int i = 0; i <= p; i++) {
			for (int j = 0; j <= 18000; j++) { prev_[i][j] = dp[i][j]; dp[i][j] = -1; }
		}
	}
	int maxn = 0;
	for (int i = 0; i <= 18000; i++)maxn = max(maxn, (prev_[p][i] - abs(i - 6000)) / 2);
	cout << maxn << endl;
	return 0;
}