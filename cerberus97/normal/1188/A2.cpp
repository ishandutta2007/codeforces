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

vector<pair<pii, int>> ans;
vector<pii> g[N];
int deg[N], val[N];

bool solve(int u, int p);
void process(pii u, pii v, int p, int val);
int apply(int u, int p, int x);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v >> val[i];
		g[u].pb({v, i});
		g[v].pb({u, i});
		++deg[u]; ++deg[v];
	}
	if (n == 2) {
		cout << "YES\n" << 1 << '\n';
		cout << 1 << ' ' << 2 << ' ' << val[g[1][0].second] << '\n';
		return 0;
	}
	int root = 1;
	while (deg[root] == 1) {
		++root;
	}
	if (solve(root, 0)) {
		cout << "YES\n" << ans.size() << '\n';
		for (auto &p : ans) {
			cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
		}
	} else {
		cout << "NO\n";
	}
}

bool solve(int u, int p) {
	vector<pii> children;
	for (auto &e : g[u]) {
			children.pb(e);
	}
	if (children.empty()) {
		return true;
	} else if (children.size() == 1) {
		return true;
	} else if (children.size() == 2) {
		if (val[children[0].second] != val[children[1].second]) {
			return false;
		} else {
			process(children[0], children[1], u, val[children[0].second]);
		}
	} else {
		int k = children.size();
		for (int i = 1; i < k; ++i) {
			process(children[0], children[i], u, val[children[i].second]);
		}
		int x = val[children[0].second] / 2;
		process(children[0], children[1], u, x);
		process(children[0], children[2], u, x);
		process(children[1], children[2], u, -x);
	}
	for (auto &e : children) {
		if (e.first != p and !solve(e.first, u)) {
			return false;
		}
	}
	return true;
}

void process(pii e1, pii e2, int p, int x) {
	int u = e1.first, v = e2.first;
	int l1 = apply(u, p, x);
	int l2 = apply(v, p, x);
	val[e1.second] -= x;
	val[e2.second] -= x;
	ans.pb({{l1, l2}, x});
	// cout << l1 << ' ' << l2 << ' ' << val << endl;
}

int apply(int u, int p, int x) {
	for (auto &e : g[u]) {
		if (e.first != p) {
			val[e.second] -= x;
			return apply(e.first, u, x);
		}
	}
	return u;
}