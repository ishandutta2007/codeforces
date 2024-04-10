/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair

void solve() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x;
	int wef = (10 - n);
	cout << 3 * wef * (wef - 1) << '\n';
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