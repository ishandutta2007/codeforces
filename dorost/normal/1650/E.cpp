/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];
int n, d;

inline bool is_valid (int x) {
	a[0] = 0;
	a[n + 1] = d + x + 1;
	int mx = 0, cnt = 0, o = -1, b = -1;
	for (int i = 0; i <= n; i++) {
		if (a[i + 1] - a[i] - 1 < x) {
			cnt++;
			if (cnt == 1)
				o = i;
			else
				b = i;
		}
		mx = max(mx, a[i + 1] - a[i] - 1);
	}
	if (cnt == 0)
		return true;
	if (cnt > 2)
		return false;
	if (cnt == 1) {
		int s1 = (a[o + 1] - (o == 0 ? 0 : a[o - 1]) - 1);
		int s2 = (a[o + 2] - (a[o]) - 1);
		mx = max(mx, s1);
		mx = max(mx, s2);
		if (mx <= x * 2) {
			return false;
		}
		if (s1 >= x)
			return true;
		if (s2 >= x)
			return true;
		return false;
	} else {
		if (o != b - 1)
			return false;
		if (a[b + 1] - a[b - 1] - 1 < x)
			return false;
		if (mx <= x * 2)
			return false;
		return true;
	}
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 0, r = d;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) 
			l = mid;
		else
			r = mid;
	}
	cout << l << '\n';
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