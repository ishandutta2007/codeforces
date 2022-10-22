/* 	* In the name of GOD 
	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012345, M = 1000 * 1000 * 1000 + 7;
int dp[N][2];

int ans (int x, bool b) {
	if (dp[x][b] != -1)
		return dp[x][b];
	if (x == 0)
		return 1;
	if ((x % 2) != (int)(b)) {
		return dp[x][b] = ans(x - 1, b);
	} else {
		return dp[x][b] = (ans(x - 1, b) + ans(x - 1, !b)) % M;
	}
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < N; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	cout << (ans(n, 0) + ans(n, 1) - 2) % M;
}