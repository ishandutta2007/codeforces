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

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> g(n + 1);
		vector<int> deg(n + 1, 0);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
			++deg[u]; ++deg[v];
		}
		if ((ll(k) * (k - 1)) / 2 > m) {
			cout << -1 << '\n';
			continue;
		}
		priority_queue<pii, vector<pii>, greater<pii>> all_deg;
		for (int i = 1; i <= n; ++i) {
			sort(g[i].begin(), g[i].end());
			all_deg.push({deg[i], i});
		}
		vector<bool> exists(n + 1, true);
		int tans = 0;
		vector<int> ans;
		while (!all_deg.empty()) {
			auto cur = all_deg.top();
			all_deg.pop();
			int u = cur.second;
			if (deg[u] != cur.first) {
				continue;
			}
			if (tans == 1) {
				ans.pb(u);
				continue;
			}
			if (deg[u] >= k) {
				tans = 1;
				ans.pb(u);
				continue;
			} else if (deg[u] == k - 1) {
				vector<int> cand;
				for (auto& v : g[u]) {
					if (exists[v]) {
						cand.pb(v);
					}
				}
				bool ok = true;
				for (int i = 0; i < k - 1 and ok; ++i) {
					for (int j = i + 1; j < k - 1 and ok; ++j) {
						if (!binary_search(g[cand[i]].begin(), g[cand[i]].end(), cand[j])) {
							ok = false;
						}
					}
				}
				if (ok) {
					cand.pb(u);
					ans = cand;
					tans = 2;
					break;
				}
			}
			for (auto& v : g[u]) {
				if (exists[v]) {
					--deg[v];
					all_deg.push({deg[v], v});
				}
			}
			exists[u] = 0;
		}
		if (tans) {
			cout << tans;
			if (tans == 1) {
				cout << ' ' << ans.size();
			}
			cout << '\n';
			for (auto& u : ans) {
				cout << u << ' ';
			}
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}