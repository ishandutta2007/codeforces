#include <iostream>
#include <algorithm>
using namespace std;
int n, d, p[100009], s[100009], dp[100009][509], maxn;
int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) { cin >> p[i]; s[p[i]]++; }
	for (int i = 0; i <= 30000; i++) { for (int j = 0; j <= 500; j++)dp[i][j] = -1; }
	dp[d][250] = s[d]; int F = d - 250;
	for (int i = 0; i <= 30000; i++) {
		for (int j = 0; j <= 500; j++) {
			maxn = max(maxn, dp[i][j]);
			if (dp[i][j] == -1)continue;
			if (F + j - 1 >= 1 && j >= 1) {
				dp[i + (F + j - 1)][j - 1] = max(dp[i + (F + j - 1)][j - 1], dp[i][j] + s[i + (F + j - 1)]);
			}
			if (F + j >= 1) {
				dp[i + (F + j)][j] = max(dp[i + (F + j)][j], dp[i][j] + s[i + (F + j)]);
			}
			if (F + j + 1 >= 1) {
				dp[i + (F + j + 1)][j + 1] = max(dp[i + (F + j + 1)][j + 1], dp[i][j] + s[i + (F + j + 1)]);
			}
		}
	}
	cout << maxn << endl;
	return 0;
}