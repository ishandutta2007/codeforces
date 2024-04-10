/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], cnt[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m + 10; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= m;
		cnt[a[i]]++;
	}
	int ans = 0;
	if (cnt[0]) {
		ans++;
	}
	if (m % 2 == 0 && cnt[m / 2])
		ans++;
	for (int i = 1; i < (m + 1) / 2; i++) {
		int x = cnt[i], y = cnt[m - i];
		if (x + y == 0)
			continue;
		if (x && y) {
			ans++;
			ans += max(0, abs(x - y) - 1);
		} else {
			ans += max(x, y);
		}
	}
	cout << ans << '\n';
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