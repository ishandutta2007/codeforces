/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int k = n / 2;
	int ans = 1;
	for (int i = k - 1; i >= 0; i--) {
		if (s[i] != s[i + 1])
			break;
		ans++;
	}
	for (int i = k + 1; i < n; i++) {
		if (s[i] != s[i - 1])
			break;
		ans++;
	}
	cout << ans << '\n';
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