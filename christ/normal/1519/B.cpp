#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3 + 5;
bitset<10005> dp[105][105];
int main () {
	dp[1][1][0] = 1;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i > 1) dp[i][j] |= dp[i-1][j]<<j;
			if (j > 1) dp[i][j] |= dp[i][j-1]<<i;
		}
	}
	int t; scanf ("%d",&t);
	while (t--) {
		int n,m,k; scanf ("%d %d %d",&n,&m,&k);
		printf (dp[n][m][k] ? "YES\n" : "NO\n");
	}
	return 0;
}