/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 19, M = 262200, K = 102;
int p[N], p2[N], cnt[N];
ll dp[M][K];
 
ll fac(ll x) {
	ll ans = 1;
	for (int i = 1; i <= x; i++) {
		ans *= i;
	}
	return ans;
}
 
int32_t main() {
	string s;
	int m;
	cin >> s >> m;
	int n = s.size();
	int x = (1 << n);
	p[0] = p2[0] = 1;
	for (auto c : s) {
		cnt[(c - '0')]++;
	}
	for (int i = 1; i < N; i++) {
		p[i] = p[i - 1] * 10;
		p[i] %= m;
		p2[i] = p2[i - 1] * 2;
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < m; j++) {
			ll ans = 0;
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
				continue;
			}
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (i & (1 << k)) 
					cnt++;
			}
			cnt--;
			for (int k = 0; k < n; k++) {
				int c = s[cnt] - '0';
				if (k == 0 && c == 0)
					continue;
				if (i & (1 << k)) {
					int mod = j;
					mod -= c * p[n - k - 1];
					mod %= m;
					mod += m;
					mod %= m;
					ans += dp[i - (1 << k)][mod];
				}
			}
			dp[i][j] = ans;
		}
	}
	ll ans = dp[x - 1][0];
	for (int i = 0; i < 10; i++) {
		ans /= fac(cnt[i]);
	}
	cout << ans;
}