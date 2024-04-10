#include <bits/stdc++.h>

using namespace std;

unsigned dp[1024][2048][4];

int main()
{
	int n, k;
	cin >> n >> k;
	dp[1][1][0] = 1;
	dp[1][1][3] = 1;
	dp[1][2][1] = 1;
	dp[1][2][2] = 1;
	int p = 998244353;
	for(int i=2;i<=n;i++) {
		dp[i][1][0] = dp[i][1][3] = 1;
		for(int j=2;j<=k;j++) {
			dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] +
						  dp[i-1][j][2] + dp[i-1][j-1][3])%p;
			dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j][1] +
						  dp[i-1][j-1][3] + dp[i-1][j-2][2])%p;
			dp[i][j][2] = (dp[i-1][j-1][0] + dp[i-1][j][2] +
						  dp[i-1][j-1][3] + dp[i-1][j-2][1])%p;
			dp[i][j][3] = (dp[i-1][j][3] + dp[i-1][j][1] +
						  dp[i-1][j][2] + dp[i-1][j-1][0])%p;
		} 
	}
	cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3])%p << endl;
	
}