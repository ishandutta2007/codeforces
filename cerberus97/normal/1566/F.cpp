/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;
const ll inf = 1e15 + 42;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n + 2);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		a[0] = -inf;
		a[n + 1] = inf;
		sort(a.begin(), a.end());
		vector<vector<pll>> groups(n + 2);
		while (m--) {
			int l, r;
			cin >> l >> r;
			int i = (upper_bound(a.begin(), a.end(), l) - 1) - a.begin();
			if (a[i] >= l or a[i + 1] <= r) {
				continue;
			}
			groups[i + 1].pb({l, r});
		}
		for (int i = 1; i <= n + 1; ++i) {
			groups[i].pb({a[i - 1], a[i - 1]});
			groups[i].pb({a[i], a[i]});
			sort(groups[i].begin(), groups[i].end());
			vector<pll> tmp;
			for (auto& [l, r] : groups[i]) {
				while (!tmp.empty() and tmp.back().second >= r) {
					tmp.pop_back();
				}
				tmp.pb({l, r});
			}
			groups[i] = tmp;
		}
		vector<vector<ll>> dp(n + 2, vector<ll>(2, inf));
		dp[0][0] = dp[0][1] = 0;
		for (int i = 1; i <= n + 1; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					int sz = groups[i].size();
					for (int x = 0; x < sz - 1; ++x) {
						ll cand = (j + 1) * (a[i] - groups[i][x + 1].second)
								+ (2 - k) * (groups[i][x].first - a[i - 1]);
						dp[i][j] = min(dp[i][j], cand + dp[i - 1][k]);
					}
				}
			}
		}
		cout << min(dp[n + 1][0], dp[n + 1][1]) << '\n';
	}
}