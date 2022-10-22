/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, n;
	string s;
	cin >> n >> a >> b >> s;
	int ans = a * n + b * n;
	int x = 1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1])
			x++;
	}
	ans = max(ans, a * n + b * ((x + 2) / 2));
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}