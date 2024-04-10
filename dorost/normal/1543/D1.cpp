/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, poker_face;
	cin >> n >> poker_face;
	set <int> st;
	for (int i = 0; i < n; i++) {
		st.insert(i);
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		int y = *st.begin();
		cout << (y ^ x) << endl;
		cout.flush();
		int r;
		cin >> r;
		if (r == 1) {
			return;
		} else {
			st.erase(y);
			x = y;
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