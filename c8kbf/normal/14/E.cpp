#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 20+8;
constant maxm = 10+8;
constant maxk = 4+8;

_ n, m, dp[maxn][maxm][maxm][maxk][maxk];

int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= 4; ++i) for(_ j = 1; j <= 4; ++j) if(abs(i-j) >= 1) dp[2][0][0][i][j] = 1;
	for(_ i = 3; i <= n; ++i) for(_ j = 0; j <= m; ++j) for(_ k = 0; k <= m-1; ++k) for(_ x = 1; x <= 4; ++x) for(_ y = 1; y <= 4; ++y) for(_ z = 1; z <= 4; ++z) if(abs(x-y) >= 1 && abs(y-z) >= 1) dp[i][j+(y>x && y>z)][k+(y<x && y<z)][y][z] += dp[i-1][j][k][x][y];
	_ s = 0;
	for(_ i = 1; i <= 4; ++i) for(_ j = 1; j <= 4; ++j) s += dp[n][m][m-1][i][j];
	printf("%lld\n", s);
	
	return 0;
}