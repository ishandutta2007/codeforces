/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
#define int long long
pair <pair <ld, pair <int, int>>, int> a[N];

bool onl(pair <int, int> a, pair <int, int> b, pair <int, int> c) {
	ld x = b.S - a.S, y = b.F - a.F, a2;
	if (y != 0)
		a2 = x / y;
	else
		a2 = INT_MAX;
	ld x1 = b.S - c.S, y1 = b.F - c.F, a1;
	if (y1 != 0)
		a1 = x1 / y1;
	else
		a1 = INT_MAX;
	return (!(a1 == a2));
}

int32_t main() {
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		int g, h;
		cin >> g >> h;
		if (i == 0) {
			x = g;
			y = h;
		}
		ld aa = (abs(x - g)) * (abs(x - g)) + abs(h - y) * abs(h - y);
		aa = sqrt(aa);
		a[i] = make_pair(make_pair(aa, make_pair(g, h)), i + 1);
	}
	sort(a, a + n);
	cout << 1 << ' ' << a[1].S << ' ';
	for (int i = 2; i < n; i++) {
		if (onl(a[0].F.S, a[1].F.S, a[i].F.S)) {
			cout << a[i].S;
			return 0;
		}
	}
}