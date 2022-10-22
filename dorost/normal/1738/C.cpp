/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int dp[N][N][2][2];

void solve() {
	int n;
	cin >> n;
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x & 1)
			cnt1++;
		else
			cnt0++;
	}
	cout << (dp[cnt0][cnt1][0][0] ? "Alice" : "Bob") << '\n';
}

int32_t main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int s = 0; s < 2; s++) {
				for (int a = 0; a < 2; a++) {
					if (s == 0) {
						dp[i][j][s][a] = false;
						if (i) {
							dp[i][j][s][a] |= dp[i - 1][j][!s][a];
						}
						if (j) {
							dp[i][j][s][a] |= dp[i][j - 1][!s][!a];
						}
						if (i == 0 && j == 0) {
							dp[i][j][s][a] = !a;
						}
					} else {
						dp[i][j][s][a] = true;
						if (i) {
							dp[i][j][s][a] &= dp[i - 1][j][!s][a];
						}
						if (j) {
							dp[i][j][s][a] &= dp[i][j - 1][!s][a];
						}
						if (i == 0 && j == 0) {
							dp[i][j][s][a] = !a;
						}
					}
				}
			}
		}
	}
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}