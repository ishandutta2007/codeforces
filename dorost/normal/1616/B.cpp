/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	int n;
	cin >> n >> s;
	string t, g;
	vector <string> v;
	for (int i = 0; i < n; i++) {
		t += s[i];
		g += s[i];
		if (i != (int)n - 1) {
			if (s[i] < s[i + 1])
				break;
			if (s[i] != s[i + 1] || (i == 0 || s[i] != s[i - 1])) {
				reverse(g.begin(), g.end());
				v.push_back(t + g);
				reverse(g.begin(), g.end());
			}
		}
	}
	reverse(g.begin(), g.end());
	v.push_back(t + g);
	reverse(g.begin(), g.end());
	cout << *min_element(v.begin(), v.end()) << '\n';
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