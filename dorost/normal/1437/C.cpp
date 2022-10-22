/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 205, Inf = 1000 * 1000;
int t[N], dp[N][2 * N];
int n;

int ans(int in, int ti) {
	if (in == n)
		return 0;
	if (in < 0 || in > n || ti > 2 * N)
		return Inf;
	if (dp[in][ti] != -1)
		return dp[in][ti];
	return dp[in][ti] = min(ans(in + 1, ti + 1) + abs(ti - t[in]), ans(in, ti + 1));
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++)
			dp[i][j] = -1;
	}
	sort(t, t + n);
	cout << ans(0, 1) << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q = 1;
	cin >> q;
	while (q--) {
		solve();
	}
}