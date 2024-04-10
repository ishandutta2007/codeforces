/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], dp[N][3];
string s;

int ans(int x, int y) {
	if (x >= s.size())
		return 0;
	if (dp[x][y] != -1)
		return dp[x][y];
	return dp[x][y] = max(ans(x + 1, y), ((y + s[x] - '0') % 3 == 0 ? ans(x + 1, 0) + 1 : ans(x + 1, (y + s[x] - '0') % 3)));
}

void solve() {
	cin >> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = -1;
		}
	}
	cout << ans(0, 0);
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}