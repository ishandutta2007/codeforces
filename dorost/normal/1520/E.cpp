/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n;
	string s;
	vector <int> v;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == '*')
			v.push_back(i);
	int ans = 0;
	for (int i = 0; i < (int)v.size() - 1; i++) {
		ans += min(i + 1, (int)v.size() - i - 1) * (v[i + 1] - v[i] - 1);
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