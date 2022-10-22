/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, ans = 0, ans2 = 0, x = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			x++;
		else {
			ans += max(0, (x - 1));
			x = 0;
		}
	}
	ans += max(0, (x - 1));
	x = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			x++;
		else {
			ans2 += max(0, (x - 1));
			x = 0;
		}
	}
	ans2 += max(0, (x - 1));
	ans = max(ans, ans2);
	cout << ans << '\n';
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