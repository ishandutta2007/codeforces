/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int p, n;
	cin >> p >> n;
	set <int> st;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (st.count(x % p)) {
			cout << i + 1;
			return;
		}
		st.insert(x % p);
	}
	cout << -1;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}