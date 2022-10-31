#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int dp[N][N], c[N][2], a[N];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		c[i][1] = c[i -1][1], c[i][2] = c[i - 1][2];
		c[i][a[i]]++; 
	}
	
	int ans = max(c[n][1], c[n][2]);
	for (int i = 1; i <= n; i++) ans = max(ans, c[i][1] + c[n][2] - c[i][2]);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			if (i == j) dp[i][j] = 1;
			else {
				if (a[j] == 1) dp[i][j] = dp[i][j - 1] + 1;
				else dp[i][j] = max(c[j][2] - c[i - 1][2], dp[i][j - 1]);
			}
			ans = max(ans, c[i - 1][1] + c[n][2] - c[j][2] + dp[i][j]);
		}
	printf("%d\n", ans);
	return 0;
}