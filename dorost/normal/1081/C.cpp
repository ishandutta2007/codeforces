/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 2012, M = 998244353;
int dp[N][N], n;

int ans(int x, int m, int k) {
	if (n == x)
		return (m * ans(x - 1, m, k)) % M;
	if (x == 0 && k == 0)
		return 1;
	if (x < 0)
		return 0;
	if (k < 0)
		return 0;
	if (dp[x][k] != -1)
		return dp[x][k];
	return dp[x][k] = ((ans(x - 1, m, k) + (m - 1) * ans(x - 1, m, k - 1)) % M);
}

int32_t main() {
	int m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			dp[i][j] = -1;
	}
	cout << ans(n, m, k);
}