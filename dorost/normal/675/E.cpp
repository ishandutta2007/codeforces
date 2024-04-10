/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100123, LG = 17;
pair <int, int> rmq[N][LG];
ll dp[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> rmq[i][0].F;
		rmq[i][0].F--;
		rmq[i][0].S = i;
	}
	rmq[n - 1][0].F = n - 1;
	rmq[n - 1][0].S = n - 1;
	for (int i = 1; i < LG; i++) {
		for (int j = 0; j < n; j++) {
			if (j + (1 << i) > n + 1)
				break;
			rmq[j][i] = max(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
		}
	}
	ll ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		int l = i + 1, r = rmq[i][0].F;
		int sz = r - l + 1;
		pair <int, int> mx;
		if (sz == 1) {
			mx = rmq[l][0];
		} else {
			int x = 1, y = 0;
			while (x <= sz) {
				x *= 2;
				y++;
			}
			y--;
			mx = max(rmq[l][y], rmq[r - (1 << y) + 1][y]);
		}
		dp[i] = dp[mx.S] + (n - 1) - i - (rmq[i][0].F - mx.S);
		ans += dp[i];
	}
	cout << ans;
}