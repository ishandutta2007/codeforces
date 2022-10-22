/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int l[N], r[N];

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++)
		l[i] = r[i] = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i < x) {
			l[a]++;
		} else {
			r[a]++;
		}
	}
	int cnt = n, ans = 0;
	for (int i = 1; i <= n; i++) {
		cnt -= min(l[i], r[i]) * 2;
		if (l[i] >= r[i]) {
			l[i] = l[i] + r[i] - (min(l[i], r[i]) * 2);
			r[i] = 0;
		} else {
			r[i] = l[i] + r[i] - (min(l[i], r[i]) * 2);
			l[i] = 0;
		}
	}
	int l1 = 0, r1 = 0, fl = 0, fr = 0;
	for (int i = 1; i <= n; i++) {
		l1 += l[i];
		if (l[i] % 2)
			fl++;
		r1 += r[i];
		if (r[i] % 2)
			fr++;
	}
	ans += min(l1, r1);
	cnt -= (min(l1, r1) * 2);
	int xx = min(l1, r1);
	l1 -= xx;
	r1 -= xx;
	ans += cnt / 2;
	if (l1 != 0) {
		if (fl > xx) {
			ans += (fl - xx) / 2;
		}
	}
	if (r1 != 0) {
		if (fr > xx) {
			ans += (fr - xx) / 2;
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}