/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s, t, r, g;
	cin >> n >> s >> t;
	vector <int> a, c, a2, c2;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'b')
			continue;
		r += s[i];
		if (s[i] == 'a')
			a.push_back(i);
		else
			c.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (t[i] == 'b')
			continue;
		g += t[i];
		if (t[i] == 'a')
			a2.push_back(i);
		else
			c2.push_back(i);
	}
	bool f = ((r == g) && (a.size() == a2.size()) && (c.size() == c2.size()));
	if (!f) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < (int)a.size(); i++) {
		f &= (a[i] <= a2[i]);
	}
	for (int i = 0; i < (int)c.size(); i++) {
		f &= (c[i] >= c2[i]);
	}
	cout << (f ? "YES" : "NO") << '\n';
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