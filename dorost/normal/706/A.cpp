/* 	* In the name of GOD 
	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	ld x, y, n;
	ld mn = 191199;
	cin >> x >> y >> n;
	for (int i = 0; i < n; i++) {
		ld x2, y2, v;
		cin >> x2 >> y2 >> v;
		ld dis = abs(x2 - x) * abs(x2 - x) + abs(y2 - y) * abs(y2 - y);
		dis = sqrt(dis);
		dis /= v;
		mn = min(mn, dis);
	}
	cout << fixed << setprecision(100101) << mn;
}