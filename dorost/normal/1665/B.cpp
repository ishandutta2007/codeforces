/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	map <int, int> cnt;
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		mx = max(mx, cnt[x]);
	}
	int ans = n - mx;
	while (mx < n) {
		mx *= 2;
		ans++;
	}
	cout << ans << '\n';
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