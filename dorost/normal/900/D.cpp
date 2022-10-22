/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 1000 * 1000 * 1000 + 7;

int tav(ll x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) 
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
	}
	return ans;
}

int answef(int n) {
	return tav(2, n - 1);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int x, y;
	cin >> x >> y;
	if (y % x) {
		cout << 0 << endl;
		return 0;
	}
	int n = y / x, wef = n;
	vector <int> v;
	for (int i = 2; i * i <= wef; i++) {
		if (wef % i == 0) {
			v.push_back(i);
			while (wef % i == 0)
				wef /= i;
		}
	}
	int ans = 0;
	if (wef != 1)
		v.push_back(wef);
	for (int i = 0; i < (1 << (int)v.size()); i++) {
		int x = n;
		for (int j = 0; j < (int)v.size(); j++) {
			if ((i >> j) & 1) {
				x /= v[j];
			}
		}
		ans += (__builtin_popcount(i) & 1 ? -1 : +1) * answef(x);
		ans %= M;
		ans += M;
		ans %= M;
	}
	cout << ans;
}