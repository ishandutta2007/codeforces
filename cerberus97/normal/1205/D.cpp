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

const int N = 1e3 + 10;

vector<int> g[N];
int sz[N], mul, val[N];

void dfs(int u, int p);
void dfs2(int u, int p, int x);

int main() {
	fast_cin();
	int n; cin >> n;
	if (n == 1) {
		return 0;
	}
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int rt = -1;
	for (int r = 1; r <= n; ++r) {
		dfs(r, 0);
		bool ok = true;
		for (auto &v : g[r]) {
			if (2 * sz[v] > n) {
				ok = false;
			}
		}
		if (ok) {
			rt = r;
			break;
		}
	}
	vector<pii> children;
	for (auto &v : g[rt]) {
		children.pb({sz[v], v});
	}
	sort(children.begin(), children.end(), greater<pii>());
	vector<int> l1, l2;
	int cur = 0;
	for (auto &p : children) {
		int v = p.second;
		if ((cur + sz[v]) * 3 <= 2 * n) {
			l1.pb(v);
			cur += sz[v];
		} else {
			l2.pb(v);
		}
	}
	mul = 1;
	for (auto &v : l1) {
		dfs2(v, rt, n - cur);
	}
	mul = 1;
	for (auto &v : l2) {
		dfs2(v, rt, 1);
	}
}

void dfs(int u, int p) {
	sz[u] = 1;
	for (auto &v : g[u]) {
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}

void dfs2(int u, int p, int x) {
	val[u] = x * mul;
	cout << u << ' ' << p << ' ' << x * mul - val[p] << '\n';
	++mul;
	for (auto &v : g[u]) {
		if (v != p) {
			dfs2(v, u, x);
		}
	}
}