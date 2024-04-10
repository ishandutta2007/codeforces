/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 20, M = 102;
const long long INF = 3000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
long long dp[2][1 << N];
pair <int, pair <int, int>> p[M];

int f(int x) {
	return x & 1;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, b;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		int sz, x;
		cin >> p[i].S.F >> p[i].F >> sz;
		while (sz--) {
			cin >> x;
			x--;
			p[i].S.S += (1 << x);
		}
	}
	sort(p, p + n);
	long long ans = INF;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j < (1 << m); j++) {	
			dp[f(i)][j] = INF;
		}
		if (i == 0)
			continue;
		for (int j = 1; j < (1 << m); j++) {
			dp[f(i)][j] = min(dp[f(i)][j], p[i - 1].S.F + dp[f(i - 1)][j & ((1 << m) - p[i - 1].S.S - 1)]);
			dp[f(i)][j] = min(dp[f(i)][j], dp[f(i - 1)][j]);
		}
		ans = min(ans, dp[f(i)][(1 << m) - 1] + (long long)b * (long long)p[i - 1].F);
	}
	cout << (ans == INF ? -1 : ans);
}