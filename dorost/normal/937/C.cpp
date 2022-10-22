/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	int k, d, t;
	cin >> k >> d >> t;
	int x = k, y = (k + d - 1) / d * d - k;
	int a = x * 2 + y;
	t *= 2;
	ld ans = (x + y) * (t / a);
	t %= a;
	if (t <= x * 2) {
		ans += (ld)t / 2.0;
	} else {
		t -= x * 2;
		ans += t + x;
	}
	cout << fixed << setprecision(15);
	cout << ans;
}