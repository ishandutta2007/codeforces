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

int query(int u, int v);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<vector<int>> g(n + 1);
	vector<int> deg(n + 1, 0);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u]; ++deg[v];
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			q.push(i);
		}
	}
	vector<bool> ok(n + 1, 1);
	while (q.size() >= 2) {
		int u = q.front(); q.pop();
		int v = q.front(); q.pop();
		int l = query(u, v);
		if (l == u or l == v) {
			cout << "! " << l << endl;
			return 0;
		}
		for (auto& x : g[u]) {
			--deg[x];
			if (deg[x] == 1) {
				q.push(x);
			}
		}
		for (auto& x : g[v]) {
			--deg[x];
			if (deg[x] == 1) {
				q.push(x);
			}
		}
	}
	cout << "! " << q.front() << endl;
}

int query(int u, int v) {
	cout << "? " << u << ' ' << v << endl;
	int l; cin >> l;
	return l;
}