/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, K = 33;
int a[N];
pair <int, int> b[N];
int cnt[N][K];

void solve() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i <= n + 5; i++) {
		for (int j = 0; j < K; j++)
			cnt[i][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int z = a[i], y = 0;
		while (z % x == 0) {
			z /= x;
			y++;
		}
		b[i] = make_pair(z, y);
	}
	sort(b, b + n);
	int lst = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			if (b[i].F != b[i - 1].F)
				lst = i;
		}
		cnt[lst][b[i].S]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < K - 1; j++) {
			int x2 = min(cnt[i][j], cnt[i][j + 1]);
			cnt[i][j] -= x2;
			cnt[i][j + 1] -= x2;
		}
		for (int j = 0; j < K; j++) {
			ans += cnt[i][j];
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