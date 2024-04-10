#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif



	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &x : a) {
			cin >> x;
		}
		int mn = a[0], c = 0;
		int lol = 2 * mn - 1;
		for (auto &x : a) {
			// a[i] <= 2 * mn - 1
			if (x >= lol + 1) {
				int t = (x - 1) / lol;
				c += t;
			}
		}
		cout << c << "\n";
	}
		
	return 0;
}