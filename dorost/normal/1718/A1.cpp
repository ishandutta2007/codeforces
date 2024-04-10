/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], px[N], dp[N];
map <int, int> mp;
int lst[N];

void solve() {
	int n, ans = 0;
	cin >> n;
	mp.clear();
	px[0] = 0;
	mp[0] = 0;
	for (int i = 0; i <= n; i++)
		lst[i] = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		px[i + 1] = a[i] ^ px[i];
		int l = mp[px[i + 1]];
		if (l == 0) {
			if (px[i + 1] == 0)
				lst[i + 1] = 0;
			else
				lst[i + 1] = -1;
		} else {
			lst[i + 1] = l;
		}
		mp[px[i + 1]] = (i + 1);
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (lst[i] != -1) {
			dp[i] = max(dp[i], dp[lst[i]] + 1);
		}
	}
	cout << n - dp[n] << '\n';
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