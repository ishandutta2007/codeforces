/*  * In the name of GOD 
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
	string t = "";
	vector <string> v;
	for (int i = 0; i < n - 1; i++) {
		t += s[i];
		if (s[i] != s[i + 1]) {
			v.push_back(t);
			t = "";
		}
	}
	t += s[n - 1];
	v.push_back(t);
	if (v.size() == 1) {
		cout << (v[0].size() + 2) / 3 << ' ';
		return;
	}
	int ans = 0;
	for (int i = 1; i < v.size() - 1; i++) {
		ans += (int)v[i].size() / 3;
	}
	if (v[0][0] == v[v.size() - 1][0]) {
		ans += (int)(v[0].size() + v[v.size() - 1].size()) / 3;
	} else {
		ans += (int)(v[0].size()) / 3 + (int)(v[v.size() - 1].size()) / 3;
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