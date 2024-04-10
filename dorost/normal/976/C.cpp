/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
pair <pair <int, int>, int> l[N];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i].F.F >> l[i].F.S;
		l[i].F.S = 1000000000 - l[i].F.S;
		l[i].S = i;
	}
	sort(l, l + n);
	int mx = 0, an = -1;
	int ans = -2, ans2 = -2;
	for (int i = 0; i < n; i++) {
		l[i].F.S = 1000000000 - l[i].F.S;
		if (l[i].F.S <= mx) {
			ans = an, ans2 = l[i].S;
			break;
		} else {
			mx = l[i].F.S;
			an = l[i].S;
		}
	}
	cout << ans2 + 1 << ' ' << ans + 1;
}