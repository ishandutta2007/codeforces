/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
vector <int> v[N];
int a[N], cnt[N];
bool is[N][N];
int dp[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n + 5; i++) {
		dp[i] = 0;
		a[i] = 0;
		v[i].clear();
		for (int j = 0; j <= n; j++) {
			is[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++)
			cnt[j] = 0;
		int c = 0, mx = 0;
		for (int j = i; j < n; j++) {
			cnt[a[j]]++;
			c++;
			mx = max(mx, cnt[a[j]]);
			is[i][j] = ((mx * 2 <= c) && (c % 2 == 0));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		v[i].push_back(-1);
		for (int j = 0; j <= n; j++)
			dp[j] = N;
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				if (a[j] == i)
					dp[j] = 0;
				else
					dp[j] = N;
			} else {
				for (int k : v[i]) {
					if (k + 1 <= j) {
						if (is[k + 1][j]) {
							dp[j] = min(dp[j], dp[k] + (j - (k + 1) + 1));
						}
					}
				}
				if (a[j] == i) {
					dp[j] = min(dp[j], dp[j - 1]);
				}
			}
		}
		ans = max(ans, n - dp[n - 1]);
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