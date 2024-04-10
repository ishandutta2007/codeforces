/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], n, dp[N][2];

int ans(int x, int l) {
	if (x >= N) {
		return 0;
	}
	if (dp[x][l] != -1)
		return dp[x][l];
	if (l == 1) {
		return dp[x][l] = ans(x + 1, 0);
	} else {
		return dp[x][l] = max(ans(x + 1, 0), a[x] * x + ans(x + 1, 1));
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i < N; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	cout << ans(0, 0);
}