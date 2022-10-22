/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 505;
int a[N], dp[N][N];

int ans(int l, int r) {
	int s = r - l + 1;
	if (s < 1)
		return 0;
	if (s == 1)
		return 1;
	if (s == 2 && a[l] == a[r])
		return 1;
	if (s == 2)
		return 2;
	if (dp[l][r] != -1)
		return dp[l][r];
	int mn = 1 + ans(l + 1, r);
	if (a[l] == a[l + 1]) 
		mn = min(mn, 1 + ans(l + 2, r));
	for (int i = l + 2; i <= r; i++) {
		if (a[i] == a[l]) {
			mn = min(mn, ans(l + 1, i - 1) + ans(i + 1, r));
		}
	}
	return dp[l][r] = mn;
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << ans(0, n - 1) << '\n';
}