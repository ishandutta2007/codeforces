#include <bits/stdc++.h>
using namespace std;
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
 
string s,t;
int n,m,k, dp[1001][1001][11], ans = 0, c[1001][1001];

int main() {
	ios_base::sync_with_stdio(0), cin >> n >> m >> k >> s >> t;
	F0Rd(i,n) F0Rd(j,m) if (s[i] == t[j]) c[i][j] = c[i+1][j+1]+1;
	F0Rd(cur,k) F0Rd(b,m) F0Rd(a,n) {
		dp[a][b][cur] = max(dp[a][b+1][cur],dp[a+1][b][cur]);
		if (c[a][b]) dp[a][b][cur] = max(dp[a][b][cur],c[a][b]+dp[a+c[a][b]][b+c[a][b]][cur+1]);
	}
	cout << dp[0][0][0];
}