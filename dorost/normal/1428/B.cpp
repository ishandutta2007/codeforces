/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	bool f = false, h = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == '>')
			f = true;
		if (s[i] == '<')
			h = true;
	}
	if (h == false || f == false) {
		cout << n << ' ';
		return;
	}
	int ans = 0;
	if (s[0] == '-' || s[n - 1] == '-')
		ans++;
	for (int i = 1; i < n; i++) {
		if (s[i] == '-' || s[i - 1] == '-')
			ans++;
	}
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