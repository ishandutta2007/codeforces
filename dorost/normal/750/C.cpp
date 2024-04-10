/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, inf = N * 1000;

int32_t main() {
	int l = -inf, r = inf, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, d;
		cin >> x >> d;
		if (d == 1) {
			l = max(l, 1900);
		} else {
			r = min(r, 1899);
		}
		l += x;
		r += x;
	}
	if (r >= N * 101) {
		cout << "Infinity";
	} else if (l > r) {
		cout << "Impossible";
	} else {
		cout << r;
	}
}