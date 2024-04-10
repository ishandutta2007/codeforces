/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, n, ans = 0;
	string s;
	cin >> a >> b >> s;
	n = s.size();
	vector <pair <char, int>> v;
	int x = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			v.push_back({s[i - 1], x});
			x = 0;
		}
		x++;
	}
	v.push_back({s[n - 1], x});
	for (int i = 0; i < v.size(); i++) {
		if (v[i].F == '0') {
			if (i == 0 || i == v.size() - 1)
				continue;
			if (b * v[i].S < a) {
				ans += (b * v[i].S - a);
			}
		} else {
			ans += a;
		}
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