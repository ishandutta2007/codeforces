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

const int N = 2e5 + 10;

vector<int> g[N], a[N];
bool seen[N], seen_r[N];

void dfs(int u);

int main() {
	fast_cin();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++i) {
		int r, c;
		cin >> r >> c;
		a[r].pb(c);
		seen_r[r] = true;
	}
	for (int r = 1; r <= n; ++r) {
		int t = a[r].size();
		for (int i = 0; i < t - 1; ++i) {
			g[a[r][i]].pb(a[r][i + 1]);
			g[a[r][i + 1]].pb(a[r][i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (!seen[i]) {
			dfs(i);
			++ans;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!seen_r[i]) {
			++ans;
		}
	}
	cout << ans - 1;
}

void dfs(int u) {
	seen[u] = true;
	for (auto &v : g[u]) {
		if (!seen[v]) {
			dfs(v);
		}
	}
}