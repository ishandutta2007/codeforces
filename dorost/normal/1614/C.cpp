/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, K = 35, M = 1000 * 1000 * 1000 + 7;
int cnt[K];
 
int tav(int x, int n) {
	if (n == 0)
		return 1;
	int ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}
 
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < K; i++)
		cnt[i] = 0;
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		int ii = 0;
		while (x) {
			cnt[ii] += x % 2;
			x /= 2;
			ii++;
		}
	}
	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (cnt[i] == 0)
			continue;
		ans += tav(2, n - 1 + i);
		ans %= M;
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}