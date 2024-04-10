/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = (1 << 20), M = 1000 * 1000 * 1000 + 7;
int a[N], dp[N], p2[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	p2[0] = 1;
	for (int i = 1; i < N; i++) {
		p2[i] = (p2[i - 1] * 2) % M;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], dp[a[i]]++;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < (1 << 20); j++) {
			if (!((j >> i) & 1)) {
				dp[j] += dp[j + (1 << i)];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 1000000; i++) {
		int t = __builtin_popcount(i);
		ans += (t & 1 ? -1 : +1) * (p2[dp[i]] - 1);
		ans %= M;
		ans += M;
		ans %= M;
	}
	cout << ans;
}