/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int k;
	cin >> k;
	vector <pair <int, int>> v;
	if (k % 2 == 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	cout << k * 4 - 2 << ' ' << k * (k * 4 - 2) / 2 << '\n';
	for (int i = 2; i <= k; i++) {
		for (int j = k + 1; j <= k * 2 - 1; j++) {
			v.push_back({i, j});
		}
	}
	for (int i = k * 2 + 1; i <= k * 3 - 1; i++) {
		for (int j = k * 3; j <= k * 4 - 2; j++) {
			if (i == j)
				continue;
			v.push_back({i, j});
		}
	}
	for (int i = 2; i <= k; i++) {
		v.push_back({1, i});
	}
	for (int i = k * 2 + 1; i <= k * 3 - 1; i++) {
		v.push_back({k * 2, i});
	}
	for (int i = k + 1; i < k * 2; i += 2) { 
		v.push_back({i, i + 1});
	}
	for (int i = k * 3; i <= k * 4 - 2; i += 2) { 
		v.push_back({i, i + 1});
	}
	v.push_back({1, 2 * k});
	for (auto [x, y] : v) {
		cout << x << ' ' << y << '\n';
	}
}