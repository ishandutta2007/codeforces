/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

bool good(int x) {
	string s = to_string(x);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			continue;
		if (x % (s[i] - '0'))
			return false;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	for (int x = n; ; x++) {
		if (good(x)) {
			cout << x << '\n';
			return;
		}
	}
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