/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int p1, f1, cn1, cn2, s, w;
	cin >> p1 >> f1 >> cn1 >> cn2 >> s >> w;
	if (s > w) {
		swap(s, w);
		swap(cn1, cn2);
	}
	int mx = 0;
	for (int i = 0; i <= cn1; i++) {
		int c1 = cn1, c2 = cn2, p = p1, f = f1;
		int x = min(p / s, i);
		int ans = x;
		p -= x * s;
		c1 -= x;
		int y = min(f / s, c1);
		ans += y;
		f -= y * s;
		c1 -= y;
		int x2 = min(p / w, c2);
		ans += x2;
		p -= x2 * w;
		c2 -= x2;
		int y2 = min(f / w, c2);
		ans += y2;
		f -= y2 * w;
		c2 -= y2;
		mx = max(mx, ans);
	}
	for (int i = 0; i <= cn1; i++) {
		int c1 = cn1, c2 = cn2, p = p1, f = f1;
		int x = min(p / s, i);
		int ans = x;
		p -= x * s;
		c1 -= x;
		int y = min(f / s, c1);
		ans += y;
		f -= y * s;
		c1 -= y;
		int y2 = min(f / w, c2);
		ans += y2;
		f -= y2 * w;
		c2 -= y2;
		int x2 = min(p / w, c2);
		ans += x2;
		p -= x2 * w;
		c2 -= x2;
		mx = max(mx, ans);
	}
	cout << mx << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}