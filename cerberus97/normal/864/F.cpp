/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e3 + 10, Q = 4e5 + 10;

struct query {
	int t, k, ind;
	bool operator<(const query& rhs) const {
	    return this->t < rhs.t;
	}
};

vector <int> g[N];
vector <query> queries[N];
vector <query>::iterator st[N][N];
bool seen[N], marked[N];
int ans[Q], path[N];

void dfs(int cur, int s, int depth);
void mark(int cur);

int main() {
	fast_cin();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}
	for (int i = 1; i <= n; ++i) {
		sort(g[i].begin(), g[i].end());
	}
	for (int i = 1; i <= q; ++i) {
		int s, t, k;
		cin >> s >> t >> k;
		queries[s].pb({t, k, i});
		ans[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		if (!queries[i].empty()) {
			sort(queries[i].begin(), queries[i].end());
			for (int j = 1; j <= n; ++j) {
				st[i][j] = queries[i].end();
			}
			for (auto it = queries[i].begin(); it != queries[i].end(); ++it) {
				if (st[i][it->t] == queries[i].end()) {
					st[i][it->t] = it;
				}
			}
			memset(seen, 0, sizeof(seen));
			memset(marked, 0, sizeof(marked));
			dfs(i, i, 1);
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
}

void dfs(int cur, int s, int depth) {
	if (marked[cur]) {
		return;
	}
	path[depth] = cur;
	seen[cur] = true;
	auto it = st[s][cur];
	while (it != queries[s].end() and it->t == cur) {
		if (it->k <= depth) {
			ans[it->ind] = path[it->k];
		}
		++it;
	}
	for (auto &i : g[cur]) {
		if (marked[cur]) {
			break;
		}
		if (!seen[i]) {
			dfs(i, s, depth + 1);
		}
		else if (!marked[i]) {
			mark(i);
		}
	}
}

void mark(int cur) {
	marked[cur] = true;
	for (auto &i : g[cur]) {
		if (!marked[i]) {
			mark(i);
		}
	}
}