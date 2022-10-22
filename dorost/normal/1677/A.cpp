/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
int a[N], cnt[N][N], cnt2[N][N], w[N];

void solve() {
	ll ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i <= n + 1; i++) {
		w[i] = 0;
		for (int j = 0; j <= n + 1; j++) {
			cnt[i][j] = 0;
			cnt2[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		w[a[i]] = i;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 0) {
				cnt[i][j] = 0;
			} else {
				cnt[i][j] = cnt[i][j - 1] + (w[j] < i);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n) {
				cnt2[i][j] = 0;
			} else {
				cnt2[i][j] = cnt2[i][j - 1] + (w[j] >= i);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += (cnt[i][a[j]] * cnt2[j + 1][a[i]]);
		}
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