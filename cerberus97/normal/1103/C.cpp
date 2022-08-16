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

const int N = 3e5 + 10;

vector<int> g[N];
bool leaf[N], seen[N];
int parent[N], d[N];

void dfs(int u);

int main() {
	srand(time(0));
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	d[1] = 1;
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		if (d[i] * ll(k) >= n) {
			cout << "PATH\n" << d[i] << '\n';
			while (i) {
				cout << i << ' ';
				i = parent[i];
			}
			cout << '\n';
			return 0;
		}
	}
	cout << "CYCLES\n";
	for (int u = 1; u <= n and k; ++u) {
		if (!leaf[u]) {
			continue;
		}
		--k;
		vector<int> cycle = {u};
		for (auto &v : g[u]) {
			if (d[v] < d[u] - 1 and (d[u] - d[v]) % 3 != 2) {
				int s = u;
				while (s != v) {
					s = parent[s];
					cycle.pb(s);
				}
				break;
			}
		}
		if (cycle.size() == 1) {
			int v1 = g[u][0];
			int v2 = g[u][1];
			if (d[v1] > d[v2]) {
				swap(v1, v2);
			}
			if (d[v2] == d[u] - 1) {
				v2 = g[u][2];
			}
			if (d[v1] > d[v2]) {
				swap(v1, v2);
			}
			cycle.pb(v2);
			while (v2 != v1) {
				v2 = parent[v2];
				cycle.pb(v2);
			}
		}
		cout << cycle.size() << '\n';
		for (auto &v : cycle) {
			cout << v << ' ';
		}
		cout << '\n';
	}
}

void dfs(int u) {
	seen[u] = true;
	leaf[u] = true;
	for (auto &v : g[u]) {
		if (!seen[v]) {
			leaf[u] = false;
			parent[v] = u;
			d[v] = d[u] + 1;
			dfs(v);
		}
	}
}