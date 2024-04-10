/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
int a[N];
pair <int, int> dp[N][N];

int solve (int l, int r, int k) {
	if (l > r)
		return 0;
	if (l == r) {
		if (a[l] - k <= 0)
			return 0;
		else
			return 1;
	}
	int mn = r - l + 1;
	int x = dp[l][r].S;
	mn = min(mn, solve(l, x - 1, a[x]) + solve(x + 1, r, a[x]) + a[x] - k);
	return mn;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				dp[i][j] = make_pair(a[i], i);
			} else {
				if (a[i] < dp[i + 1][j].F) {
					dp[i][j] = make_pair(a[i], i);
				} else {
					dp[i][j] = dp[i + 1][j];
				}
			}
		}
	}
	cout << solve (0, n - 1, 0);
}