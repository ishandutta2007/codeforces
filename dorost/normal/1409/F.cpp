/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 202;
ll dp[N][N][N];

int32_t main() {
	int n, k;
	string s, t;
	cin >> n >> k >> s >> t;
	if (t[0] == t[1]) {
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[0])
				cnt++;
			else if (k) {
				cnt++;
				k--;
			}
		}
		cout << (cnt * (cnt - 1)) / 2;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= k; l++) {
				dp[i][j][l] = LLONG_MIN;
				if (i == 0) {
					if (j > 1)
						continue;
					if (j == 1) {
						if (s[0] == t[0] || l) {
							dp[i][j][l] = 0;
						}
					} else {
						if (s[0] != t[0] || l) {
							dp[i][j][l] = 0;
						}
					}
					continue;
				}
				if (s[i] == t[0]) {
					if (j != 0)
						dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l]);
					if (l != 0)
						dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l - 1] + j);
					dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);
				} else if (s[i] == t[1]) {
					dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l] + j);
					if (j != 0 && l != 0)
						dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l - 1]);
				} else {
					if (j != 0 && l != 0)
						dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j - 1][l - 1]);
					if (l != 0)
						dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l - 1] + j);
					dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);
				}
			}
		}
	}
	ll mx = 0;
	int i = n - 1;
	for (int j = 0; j <= n; j++) {
		mx = max(mx, dp[i][j][k]);
	}
	cout << mx;
}