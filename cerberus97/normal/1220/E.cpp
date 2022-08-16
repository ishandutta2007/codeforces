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

vector<int> g[N];
int deg[N];
bool del[N];
ll w[N], best[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		sum += w[i];
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u]; ++deg[v];
	}
	int s; cin >> s;
	stack<int> stk;
	for (int i = 1; i <= n; ++i) {
		if (i != s and deg[i] == 1) {
			stk.push(i);
		}
	}
	while (!stk.empty()) {
		int u = stk.top();
		stk.pop();
		del[u] = true;
		sum -= w[u];
		w[u] += best[u];
		int v = -1;
		for (auto &t : g[u]) {
			if (!del[t]) {
				v = t;
				break;
			}
		}
		best[v] = max(best[v], w[u]);
		--deg[v];
		if (deg[v] == 1 and v != s) {
			stk.push(v);
		}
	}
	ll max_best = 0;
	for (int i = 1; i <= n; ++i) {
		if (!del[i]) {
			max_best = max(max_best, best[i]);
		}
	}
	cout << sum + max_best << endl;
}