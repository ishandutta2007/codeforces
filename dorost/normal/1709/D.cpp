/* 	* In the name of GOD  */

#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, LG = 18;
int rmq[N][LG], a[N], n, m;

void sp() {
	for (int i = 0; i < n; i++) {
		rmq[i][0] = a[i];
	}
	for (int i = 1; i < LG; i++) {
		for (int j = 0; j < n; j++) {
			if (j + (1 << i) > n + 1)
				break;
			rmq[j][i] = max(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
		}
	}
}

int ask(int l, int r) { 
	int mn;
	int sz = (r - l + 1);
	if (sz == 1) {
		mn = rmq[l][0];
	} else {
		int x = 1, y = 0;
		while (x <= sz) {
			x *= 2;
			y++;
		}
		y--;
		mn = max(rmq[l][y], rmq[r - (1 << y) + 1][y]);
	}
	return mn;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n >> m;
	swap(n, m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sp();
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		b--, d--;
		if (abs(a - c) % k || abs(b - d) % k) {
			cout << "NO\n";
			continue;
		} 
		ll mx = ask(min(b, d), max(b, d));
		ll l = 0, r = 2000000000;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if ((ll)a + mid * (ll)k <= m) {
				l = mid;
			} else {
				r = mid;
			}
		}
		ll go = (l * k) + a;
		cout << (mx < go ? "YES" : "NO") << '\n';
	}
}