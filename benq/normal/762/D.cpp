#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

#define F0R(i, a) for (int i=0; i<a; i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

ll dp[3][100000], table[3][100000];

int main() {
	int n; cin >> n;
	F0R(i,3) F0R(j,n) cin >> table[i][j];
	dp[2][n-1] = table[2][n-1];
	dp[1][n-1] = table[1][n-1] + dp[2][n-1];
	dp[0][n-1] = table[0][n-1] + dp[1][n-1];
	
	F0Rd(j,n-1) F0R(i,3) {
		dp[i][j] = dp[i][j+1] + table[i][j];
		if (i == 1) {
			dp[1][j] = max(dp[1][j],dp[2][j+1]+table[1][j]+table[2][j]);
			dp[1][j] = max(dp[1][j],dp[0][j+1]+table[1][j]+table[0][j]);
		} else {
			dp[i][j] = max(dp[i][j], dp[1][j+1]+table[1][j]+table[i][j]);
			dp[i][j] = max(dp[i][j], dp[2-i][j+1]+table[0][j]+table[1][j]+table[2][j]);
			if (j < n-2) dp[i][j] = max(dp[i][j], table[0][j]+table[1][j]+table[2][j]
								+table[0][j+1]+table[1][j+1]+table[2][j+1]+dp[2-i][j+2]);
			else if (i == 0) dp[i][j] = max(dp[i][j], table[0][j]+table[1][j]+table[2][j]
								+table[0][j+1]+table[1][j+1]+table[2][j+1]);
		}
	}
	cout << dp[0][0];
}