// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<ll>> here(n, vector<ll>(m));
	vector<vector<vector<pii>>> prev_h(n, vector<vector<pii>>(m)), prev_v(n, vector<vector<pii>>(m));
	for (int i = 0; i < k; ++i) {
		int x, y, d, t, e;
		cin >> x >> y >> d >> t >> e;
		vector<pii> positions = {{x, y}, {x + d, y - d}, {x + d, y}, {x, y + d}};
		for (int j = 0; j < 4; ++j) {
			auto [cx, cy] = positions[j];
			if ((t + j) % 4 == (cx + cy) % 4 && t + j <= cx + cy) {
				here[cx][cy] += e;
			}
		}
		if (d % 4 == 1) {
			if ((t + 2) % 4 == (x + d + y) % 4 && t + 1 <= x + d + y - d) {
				prev_h[x + d][y].push_back({d, e});
			}
		} else if (d % 4 == 2) {
			if ((t + 2) % 4 == (x + d + y) % 4 && t <= x + y) {
				prev_v[x + d][y].push_back({d, e});
			}
		} else if (d % 4 == 3) {
			if ((t + 3) % 4 == (x + y + d) % 4 && t <= x + y) {
				prev_h[x][y + d].push_back({d, e});
			}
		}
	}

	vector<vector<vector<vector<ll>>>> dp(2, vector<vector<vector<ll>>>(2, vector<vector<ll>>(m, vector<ll>(max(n, m) + 1, INFL))));

	dp[0][0][0][0] = 0;
	dp[1][0][0][0] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 && j == 0) {
				continue;
			}
			if (i > 0) {
				sort(prev_v[i][j].begin(), prev_v[i][j].end());
				ll sum = 0;
				int cnt = 0;
				for (int k = 0; k < i; ++k) {
					while (cnt < szof(prev_v[i][j]) && prev_v[i][j][cnt].ff <= k + 1) {
						sum += prev_v[i][j][cnt++].ss;
					}
					ll val = dp[0][1 - i % 2][j][k] + here[i][j] - sum;
					dp[0][i % 2][j][k + 1] = val;
				}
			}
			if (j > 0) {
				sort(prev_h[i][j].begin(), prev_h[i][j].end());
				ll sum = 0;
				int cnt = 0;
				for (int k = 0; k < j; ++k) {
					while (cnt < szof(prev_h[i][j]) && prev_h[i][j][cnt].ff <= k + 1) {
						sum += prev_h[i][j][cnt++].ss;
					}
					ll val = dp[1][i % 2][j - 1][k] + here[i][j] - sum;
					dp[1][i % 2][j][k + 1] = val;
				}
			}
			if (j) {
				dp[0][i % 2][j][0] = *min_element(dp[1][i % 2][j].begin() + 1, dp[1][i % 2][j].begin() + j + 1);
			} else {
				dp[0][i % 2][j][0] = INFL;
			}
			if (i) {
				dp[1][i % 2][j][0] = *min_element(dp[0][i % 2][j].begin() + 1, dp[0][i % 2][j].begin() + i + 1);
			} else {
				dp[1][i % 2][j][0] = INFL;
			}
		}
	}

	ll ans = INFL;
	ans = min(ans, *min_element(dp[0][(n - 1) % 2][m - 1].begin(), dp[0][(n - 1) % 2][m - 1].begin() + n));
	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}