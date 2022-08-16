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

const int N = 15e4 + 10, C = 26;

vector<int> g[N];
int par[N], upd[N], id[N], depth[N], sum[N];
int letters[N][C], ctr[N][C][2];
bool ok[N];
char act_letter[N];
set<int> depths;
int common_depth, num_ok = 0;

void dfs1(int u);
void dfs2(int u);
void update(int u, int c, int x);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	upd[1] = 1;
	for (int i = 2; i <= n; ++i) {
		int p; char c;
		cin >> p >> c;
		if (!g[p].empty()) {
			id[i] = 1;
		}
		g[p].pb(i);
		par[i] = p;
		upd[i] = i;
		if (c != '?') {
			letters[i][c - 'a']++;
		}
		act_letter[i] = c;
	}
	dfs1(1);
	if (depths.size() > 1) {
		for (int i = 0; i < q; ++i) {
			cout << "Fou\n";
		}
		return 0;
	}
	common_depth = *depths.begin();
	dfs2(1);
	// for (int i = 1; i <= n; ++i) {
	// 	if (upd[i] == i) {
	// 		cout << i << ' ' << par[i] << endl;
	// 	} else {
	// 		cout << i << ' ' << "DEL" << ' ' << upd[i] << endl;
	// 	}
	// }
	while (q--) {
		int v; char c;
		cin >> v >> c;
		int u = upd[v];
		if (act_letter[v] != '?') {
			update(u, act_letter[v] - 'a', -1);
		}
		act_letter[v] = c;
		if (act_letter[v] != '?') {
			update(u, act_letter[v] - 'a', 1);
		}
		if (num_ok == n) {
			cout << "Shi ";
			ll ans = 0;
			for (int i = 0; i < C; ++i) {
				ans += max(ctr[1][i][0], ctr[1][i][1]) * (i + 1);
			}
			int extra = common_depth - sum[1];
			for (int i = 0; i < C; ++i) {
				ans += extra * (i + 1);
			}
			cout << ans << '\n';
		} else {
			cout << "Fou\n";
		}
	}
}

void dfs1(int u) {
	if (g[u].empty()) {
		depths.insert(depth[u]);
		return;
	}
	for (auto &v : g[u]) {
		depth[v] = depth[u] + 1;
		dfs1(v);
	}
}

void dfs2(int u) {
	for (auto &v : g[u]) {
		dfs2(v);
	}
	if (upd[u] != u) {
		// cout << u << ' ' << upd[u] << endl;
		++num_ok;
		return;
	}
	int p = par[u];
	while (p > 1 and g[p].size() == 1) {
		for (int j = 0; j < C; ++j) {
			letters[u][j] += letters[p][j];
		}
		upd[p] = u;
		id[u] = id[p];
		p = par[p];
		par[u] = p;
	}
	int have = common_depth - depth[u];
	for (int j = 0; j < C; ++j) {
		sum[u] += max(ctr[u][j][0], ctr[u][j][1]);
	}
	if (sum[u] <= have) {
		ok[u] = true;
		++num_ok;
	}
	if (u == 1) {
		return;
	}
	// int p = par[u];
	for (int j = 0; j < C; ++j) {
		ctr[p][j][id[u]] = max(ctr[u][j][0], ctr[u][j][1]) + letters[u][j];
	}
}

void update(int u, int c, int x) {
	letters[u][c] += x;
	while (u != 1) {
		int p = par[u];
		// for (int j = 0; j < C; ++j) {
		sum[p] -= max(ctr[p][c][0], ctr[p][c][1]);
		ctr[p][c][id[u]] = max(ctr[u][c][0], ctr[u][c][1]) + letters[u][c];
		sum[p] += max(ctr[p][c][0], ctr[p][c][1]);
		// }
		u = p;
		int have = common_depth - depth[u];
		if (sum[u] <= have and !ok[u]) {
			ok[u] = true;
			++num_ok;
		} else if (sum[u] > have and ok[u]) {
			ok[u] = false;
			--num_ok;
		}
	}
}