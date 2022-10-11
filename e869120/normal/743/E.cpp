#include<iostream>
#include<algorithm>
using namespace std;
int n, a[1005], d[9][1005][1005], dp[1005][256];
int solve(int pos, int mask, int ko) {
	if (pos > n)return -99999999;
	if (pos == n && mask != 255)return -99999999;
	if (mask == 255)return 0;
	if (dp[pos][mask] >= 0)return dp[pos][mask];

	int maxn = -999999999;
	for (int i = 1; i <= 8; i++) {
		if ((mask&(1 << (i - 1))) == 0) {
			if (d[i][pos][ko + 0] != -1)maxn = max(maxn, solve(d[i][pos][ko + 0], mask + (1 << (i - 1)), ko + 0) + ko + 0);
			if (d[i][pos][ko + 1] != -1)maxn = max(maxn, solve(d[i][pos][ko + 1], mask + (1 << (i - 1)), ko + 0) + ko + 1);
		}
	}
	dp[pos][mask] = maxn;
	return maxn;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 1; i <= 8; i++) { for (int j = 0; j < 1005; j++) { for (int k = 0; k < 1005; k++)d[i][j][k] = -1; } }
	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j < n; j++) {
			int F = 0; d[i][j][0] = j;
			for (int k = j; k < n; k++) {
				if (a[k] == i) { F++; d[i][j][F] = k + 1; }
			}
		}
	}
	int maxn = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 1005; j++) { for (int k = 0; k < 256; k++)dp[j][k] = -1; }
		maxn = max(maxn, solve(0, 0, i));
	}
	cout << maxn << endl;
	return 0;
}