/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N], b[N], c[N], w[N], dp[N][N], pd[2][15 * N];

int f(int x) {
	return x & 1;
}

void solve() {
	int n, k;
	cin >> n >> k;
	k = min(k, n * 15);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		w[i] = dp[1][b[i]];
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			pd[f(i)][j] = 0;
			if (i == 0) {
				if (j >= w[i]) {
					pd[f(i)][j] = c[i];
				} else {
					pd[f(i)][j] = 0;
				}
			} else {
				pd[f(i)][j] = pd[f(i - 1)][j];
				if (j >= w[i]) {
					pd[f(i)][j] = max(pd[f(i)][j], pd[f(i - 1)][j - w[i]] + c[i]);
				}
			}
		}
	}
	cout << pd[f(n - 1)][k] << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = N;
			if (i == j)
				dp[i][j] = 0;
			else if (i < j) {
				for (int k = 1; k <= N; k++) {
					if (i + i / k >= N)
						continue;
					dp[i][j] = min(dp[i][j], dp[i + i / k][j] + 1);
				}
			}
		}
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}