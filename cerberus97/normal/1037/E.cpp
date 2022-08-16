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

set<int> g[N];
bool deleted[N];
int eu[N], ev[N], d[N], ans[N], ctr;

void del(int u, int k);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> eu[i] >> ev[i];
		g[eu[i]].insert(ev[i]); g[ev[i]].insert(eu[i]);
		++d[eu[i]]; ++d[ev[i]];
	}
	ctr = n;
	for (int i = 1; i <= n; ++i) {
		if (d[i] < k and !deleted[i]) {
			del(i, k);
		}
	}
	for (int i = m; i >= 1; --i) {
		ans[i] = ctr;
		if (deleted[eu[i]] or deleted[ev[i]]) {
			continue;
		}
		--d[eu[i]]; --d[ev[i]];
		g[eu[i]].erase(ev[i]);
		g[ev[i]].erase(eu[i]);
		if (!deleted[eu[i]] and d[eu[i]] < k) {
			del(eu[i], k);
		}
		if (!deleted[ev[i]] and d[ev[i]] < k) {
			del(ev[i], k);
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << '\n';
	}
}

void del(int u, int k) {
	deleted[u] = true;
	--ctr;
	for (auto &v : g[u]) {
		--d[v];
		if (!deleted[v] and d[v] < k) {
			del(v, k);
		}
	}
}