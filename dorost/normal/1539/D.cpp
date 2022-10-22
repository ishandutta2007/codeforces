/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
pair <int, int> a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].S >> a[i].F;
	}
	sort(a, a + n);
	int lst = n - 1;
	int ans = 0, x = 0;
	for (int i = 0; i < n; i++) {
		if (i > lst) {
			break;
		}
		int y = 0;
		if (x < a[i].F) {
			y = a[i].F - x;
		}
		for (int j = lst; j >= i; j--) {
			if (y == 0)
				break;
			lst = j;
			int z = min(a[j].S, y);
			y -= z;
			a[j].S -= z;
			x += z;
			ans += z * 2;
		}
		if (x >= a[i].F) {
			ans += a[i].S;
			x += a[i].S;
			a[i].S = 0;
		}
	}
	cout << ans << '\n';
}