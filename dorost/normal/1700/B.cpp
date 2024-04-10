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
	if (s[0] != '9') {
		for (int i = 0; i < n; i++) {
			cout << ('9' - s[i]);
		}
		cout << endl;
		return;
	}
	int rem = 0;
	vector <int> t;
	for (int i = n - 1; i >= 0; i--) {
		s[i] -= '0';
		if ((s[i] + rem) <= 1) {
			t.push_back(1 - (s[i] + rem));
			rem = 0;
		} else {
			t.push_back(11 - (s[i] + rem));
			rem = 1;
		}
	}
	reverse(t.begin(), t.end());
	for (int i : t)
		cout << i;
	cout << '\n';
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