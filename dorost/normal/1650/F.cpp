/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100034;
const int INF = 1001LL * 1000LL * 1000LL;
vector <pair <pair <int, int>, int>> v[N];
int a[N];
int f[N];
int dp[N][101];
vector <bool> p[N][101];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		v[i].clear();
		for (int j = 0; j < 101; j++)
			p[i][j].clear();
	}
	for (int i = 0; i < m; i++) {
		int e, t, p;
		cin >> e >> t >> p;
		--e;
		v[e].push_back(make_pair(make_pair(t, p), i + 1));
	}
	for (int i = 0; i < n; i++) {
		if (v[i].empty()) {
			cout << -1 << '\n';
			return;
		}
		for (int j = 0; j <= v[i].size(); j++) 
			for (int k = 0; k < 101; k++) 
				p[i][k].push_back(false);
		for (int j = 0; j <= v[i].size(); j++) {
			for (int k = 0; k < 101; k++) {
				if (j == 0) {
					if (k == 0)
						dp[j][k] = 0;
					else
						dp[j][k] = INF;
				} else {
					dp[j][k] = dp[j - 1][k];
					p[i][k][j] = false;
					if (v[i][j - 1].F.S >= k) {
						dp[j][k] = min(dp[j][k], v[i][j - 1].F.F);
						if ((ll)v[i][j - 1].F.F <= dp[j][k])
							p[i][k][j] = true;
					} else {
						dp[j][k] = min(dp[j][k], v[i][j - 1].F.F + dp[j - 1][k - v[i][j - 1].F.S]);
						if (v[i][j - 1].F.F + dp[j - 1][k - v[i][j - 1].F.S] <= dp[j][k]) {
							p[i][k][j] = true;
						}
					}
				}
			}
		}
		f[i] = dp[v[i].size()][100];
	}
	ll ps = 0;
	vector <int> ans;
	for (int i = 0; i < n; i++) {
		ps += f[i];
		if (ps > a[i]) {
			cout << -1 << '\n';
			return;
		}
		int f = (int)v[i].size(), s = 100;
		while (f != 0 && s != 0) {
			if (p[i][s][f]) {
				ans.push_back(v[i][f - 1].S);
				if (v[i][f - 1].F.S >= s) {
					s = 0;
					f = 0;
				} else {
					s = s - v[i][f - 1].F.S;
					f--;
				}
			} else {
				f--;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
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