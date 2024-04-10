/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 998244353, N = 502;
int dp[N][N], A = 0, tava[N][N], C[N][N];

int tav(int x, int n) {
	if (x == 0)
		return 0;
	if (n >= N || x >= N)
		//		return tavb[x];
		x;
	else if (tava[x][n] != 0) {
		//		cout << x << ' ' << n << endl;
		return tava[x][n];
	}
	if (n == 0)
		return 1;
	ll ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	if (n >= N || x >= N) {
		//		tavb[x] = ans;
	} else {
		//		cout << x << ' ' << n << endl;
		tava[x][n] = ans;
	}
	return ans;
}

int inv(int x) {
	return tav(x, M - 2);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < j) {
				C[i][j] = 0;
			} else if (j == 0) {
				C[i][j] = 1;
			} else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
				if (C[i][j] >= M)
					C[i][j] -= M;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			if (i == 0) {
				dp[i][j] = 1;
			} else if (j == 0 || i == 1) {
				dp[i][j] = 0;
			} else {
				int nn = i - 1;
				dp[i][j] = tav(min(j, nn), i);
				for (int k = 0; k < i - 1; k++) {
					if (j < nn)
						continue;
					int x2 = ((ll)C[i][k] * (ll)tav(nn, k)) % M;
					dp[i][j] += ((ll)x2 * (ll)dp[i - k][j - nn]) % M;
					if (dp[i][j] >= M)
						dp[i][j] -= M;
				}
			}
		}
	}
	cout << dp[n][x];
}