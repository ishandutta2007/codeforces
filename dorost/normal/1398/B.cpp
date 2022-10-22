/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	vector <int> v;
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			x++;
		else {
			v.push_back(x);
			x = 0;
		}
	}
	v.push_back(x);
	int ans = 0;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i += 2)
		ans += v[i];
	cout << ans << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}