/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 18;
ld dp[1 << N];
ld a[N][N];
ld ans[N];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = (1 << n) - 1; i > 0; i--) {
		if (i == (1 << n) - 1) 
			dp[i] = 1;
		int sz = __builtin_popcount(i);
		if (sz == 1) {
			ans[__builtin_ctz(i)] = dp[i];
			continue;
		}
		ld c = 1 / (ld)((sz * (sz - 1)) / 2);
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < n; k++) 
				if (j != k && ((i >> j) & (i >> k) & 1)) 
					dp[i - (1 << k)] += dp[i] * a[j][k] * c;
	}
	cout << fixed << setprecision(7);
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}