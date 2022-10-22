/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	set <pair <int, int>> st;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (a % 2 == 0)
			a /= 2;
		st.insert(make_pair(a, i));
	}
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		while (b) {
			auto in = st.lower_bound(make_pair(b, -1));
			if ((in != st.end()) && ((*in).F == b)) {
				st.erase(in);
				break;
			}
			b /= 2;
		}
	}
	cout << (st.empty() ? "YES" : "NO") << '\n';
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