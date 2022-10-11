#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
int a[300009], n, k, dp[5009][5009];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int M = n / k, R = n%k, L = k - (n%k);
	for (int i = 0; i < 5009; i++) { for (int j = 0; j < 5009; j++)dp[i][j] = -1; }
	dp[0][0] = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i][j] < 0)continue;
			int S = j*M + (i - j)*(M + 1);
			if (S >= n)continue;
			if (i >= 1) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (a[S + 1] - a[S]));
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (a[S + 1] - a[S]));
			}
			else {
				dp[i + 1][j] = 0; dp[i + 1][j + 1] = 0;
			}
		}
	}
	cout << (a[n] - a[1]) - dp[k][L] << endl;
	return 0;
}