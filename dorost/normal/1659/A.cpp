/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, r, b;
	cin >> n >> r >> b;
	int x = (r) / (b + 1);
	int y = (r) % (b + 1);
	for (int i = 0; i < (b + 1); i++) {
		if (i < y) {
			cout << 'R';
		}
		for (int i = 0; i < x; i++)
			cout << 'R';
		if (i != b)
			cout << 'B';
	}
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