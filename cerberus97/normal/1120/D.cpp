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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

vector<int> g[N], best_ch[N];
bool seen[N][2], ok[N];
ll dp[N][2], c[N];
int opt[N][2];

ll solve(int i, int j, int p);
void mark(int i, int j, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll ans = solve(1, 0, 0);
	memset(seen, 0, sizeof(seen));
	mark(1, 0, 0);
	vector<int> good;
	for (int i = 1; i <= n; ++i) {
		if (ok[i] or c[i] == 0) {
			good.pb(i);
		}
	}
	cout << ans << ' ' << good.size() << endl;
	for (auto &i : good) {
		cout << i << ' ';
	}
	cout << endl;
}

ll solve(int i, int j, int p) {
	if (seen[i][j]) {
		return dp[i][j];
	} else {
		seen[i][j] = true;
		ll &ans = dp[i][j];
		if (g[i].size() == 1 and g[i][0] == p) {
			ans = (j ? 0 : c[i]);
			return ans;
		}
		ll base_cost = 0;
		for (auto &v : g[i]) {
			if (v != p) {
				base_cost += solve(v, 0, i);
			}
		}
		ll max_gain = 0;
		for (auto &v : g[i]) {
			if (v != p) {
				ll gain = solve(v, 0, i) - solve(v, 1, i);
				if (gain > max_gain) {
					max_gain = gain;
					best_ch[i].clear();
					best_ch[i].pb(v);
				} else if (gain == max_gain) {
					best_ch[i].pb(v);
				}
			}
		}
		if (j == 0) {
			ans = base_cost;
			opt[i][j] = 0;
			ll cand = base_cost + c[i] - max_gain;
			if (cand < ans) {
				ans = cand;
				opt[i][j] = 1;
			} else if (cand == ans) {
				opt[i][j] = 2;
			}
		} else {
			ans = base_cost - max_gain;
		}
		return ans;
	}
}

void mark(int i, int j, int p) {
	if (seen[i][j]) {
		return;
	}
	seen[i][j] = true;
	if (g[i].size() == 1 and g[i][0] == p) {
		if (j == 0) {
			ok[i] = true;
		}
		return;
	}
	if (j == 0) {
		if (opt[i][j] != 1) {
			for (auto &v : g[i]) {
				if (v != p) {
					mark(v, 0, i);
				}
			}
		}
		if (opt[i][j] != 0) {
			ok[i] = true;
			for (auto &v : g[i]) {
				if (v != p) {
					if (best_ch[i].size() != 1 or v != best_ch[i][0]) {
						mark(v, 0, i);
					}
				}
			}
			for (auto &v : best_ch[i]) {
				mark(v, 1, i);
			}
		}
	} else {
		for (auto &v : g[i]) {
			if (v != p) {
				if (best_ch[i].size() != 1 or v != best_ch[i][0]) {
					mark(v, 0, i);
				}
			}
		}
		for (auto &v : best_ch[i]) {
			mark(v, 1, i);
		}
	}
}