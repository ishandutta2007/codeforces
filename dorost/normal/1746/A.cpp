/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mkp make_pair

void solve() {
	int n, k;
	cin >> n >> k;
	bool f = false;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		f |= x;
	}
	cout << (f ? "YES" : "NO") << '\n';
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