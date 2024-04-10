/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	string t = s;
	reverse(t.begin(), t.end());
	if (k == 0) {
		cout << "Yes\n";
		return;
	}
	bool f = true;
	for (int i = 0; i < k; i++) {
		if (s[i] != s[n - 1 - i])
			f = false;
	}
	if (!f || k * 2 == n) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}