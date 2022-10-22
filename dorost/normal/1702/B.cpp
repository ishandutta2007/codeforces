/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	set <char> st;
	int ans = 1;
	for (int i = 0; i < (int)s.size(); i++) {
		st.insert(s[i]);
		if (st.size() >= 4) { 
			ans++;
			st.clear();
			st.insert(s[i]);
		}
	}
	cout << ans << '\n';
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