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

map<vector<int>, bool> mp;
vector<int> g[N];
bool seen[N], good[N], good2[N];

bool get_path(int s, int t, vector<int>& path);
int get_depth(int u, int len);
void dfs(int hp, int hd, int tp, int td, int len, vector<int>& depth);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
			seen[i] = 0;
			good[i] = 0;
			good2[i] = 0;
		}
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		vector<int> path;
		get_path(a, b, path);
		for (int i = 1; i <= n; ++i) {
			seen[i] = false;
		}
		for (auto& u : path) {
			seen[u] = true;
		}
		int len = path.size();
		vector<int> depth(len, 0);
		for (int i = 0; i < len; ++i) {
			depth[i] = get_depth(path[i], len);
			good2[i] = good[path[i]];
		}
		mp.clear();
		dfs(0, 0, len - 1, 0, len, depth);
		if (mp.count({len - 1, 0, 0, 0})) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

bool get_path(int s, int t, vector<int>& path) {
	path.pb(s);
	seen[s] = true;
	if (s == t) {
		return true;
	}
	for (auto& u : g[s]) {
		if (!seen[u]) {
			if (get_path(u, t, path)) {
				return true;
			}
		}
	}
	path.pop_back();
	return false;
}

int get_depth(int u, int len) {
	seen[u] = true;
	int ans = 1, cnt = 0;
	for (auto& v : g[u]) {
		if (!seen[v]) {
			int d = get_depth(v, len);
			good[u] |= good[v];
			ans = max(ans, d + 1);
			if (d >= len - 1) {
				++cnt;
			}
		}
	}
	good[u] |= (cnt >= 2);
	return ans;
}

void dfs(int hp, int hd, int tp, int td, int len, vector<int>& depth) {
	if (mp.count({hp, hd, tp, td})) {
		return;
	}
	mp[{hp, hd, tp, td}] = true;
	if (tp == hp and good2[hp]) {
		dfs(tp, td, hp, hd, len, depth);
	}
	if (hd < depth[hp] - 1) {
		if (tp == hp) {
			if (max(hd, td) < depth[tp] - 1) {
				dfs(hp, hd + 1, tp, td + 1, len, depth);
			}
		} else if (td > 0) {
			dfs(hp, hd + 1, tp, td - 1, len, depth);
		} else if (tp > hp) {
			dfs(hp, hd + 1, tp - 1, td, len, depth);
		} else {
			dfs(hp, hd + 1, tp + 1, td, len, depth);
		}
	}
	if (td < depth[tp] - 1) {
		if (hp == tp) {
			if (max(hd, td) < depth[tp] - 1) {
				dfs(hp, hd + 1, tp, td + 1, len, depth);
			}
		} else if (hd > 0) {
			dfs(hp, hd - 1, tp, td + 1, len, depth);
		} else if (hp > tp) {
			dfs(hp - 1, hd, tp, td + 1, len, depth);
		} else {
			dfs(hp + 1, hd, tp, td + 1, len, depth);
		}
	}
	if (hd == 0) {
		if (hp > 0 and hp <= tp) {
			if (td == 0) {
				dfs(hp - 1, hd, tp - 1, td, len, depth);
			} else {
				dfs(hp - 1, hd, tp, td - 1, len, depth);
			}
		}
		if (hp < len - 1 and hp >= tp) {
			if (td == 0) {
				dfs(hp + 1, hd, tp + 1, td, len, depth);
			} else {
				dfs(hp + 1, hd, tp, td - 1, len, depth);
			}
		}
	}
	if (td == 0) {
		if (tp > 0 and tp <= hp) {
			if (hd == 0) {
				dfs(hp - 1, hd, tp - 1, td, len, depth);
			} else {
				dfs(hp, hd - 1, tp - 1, td, len, depth);
			}
		}
		if (tp < len - 1 and tp >= hp) {
			if (hd == 0) {
				dfs(hp + 1, hd, tp + 1, td, len, depth);
			} else {
				dfs(hp, hd - 1, tp + 1, td, len, depth);
			}
		}
	}
}