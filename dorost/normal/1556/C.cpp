/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012;
int a[N];

void solve() {
	int n;
	cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2)
			continue;
		pair <int, int> p = {1, a[i]};
		int t = 1;
		for (int j = i + 1; j < n; j++) {
			if (j % 2 == 0) {
				t += a[j];
				continue;
			}
			t -= a[j];
			if (t <= 0) {
				ans += max(0LL, min((-t + 1), p.S) - (p.F - 1));
//				cout << i << ' ' << j << ' ' << max(0LL, min(-t + 1, p.S) - (p.F - 1)) << ' ' << t << ' ' << p.S << ' ' << p.F << '\n';
			}
			p.F = max(p.F, (min(p.S + 1, (-t) + 1)));
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}