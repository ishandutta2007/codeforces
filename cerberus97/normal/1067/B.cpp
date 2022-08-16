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

const int N = 1e5 + 10;

vector<int> g[N];
int deg[N];

bool check(int u, int p, int k);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u];
		++deg[v];
	}
	vector<int> cur, nxt;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			cur.pb(i);
		}
	}
	while (!cur.empty()) {
		nxt.clear();
		for (auto &u : cur) {
			for (auto &v : g[u]) {
				--deg[v];
				if (deg[v] == 1) {
					nxt.pb(v);
				}
			}
		}
		swap(cur, nxt);
	}
	int root = (nxt.empty() ? 1 : nxt[0]);
	if (check(root, 0, k)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

bool check(int u, int p, int k) {
	int ch = (g[u].size() - (p != 0));
	if (k == 0) {
		return ch == 0;
	} else if (ch < 3) {
		return false;
	} else {
		for (auto &v : g[u]) {
			if (v != p and !check(v, u, k - 1)) {
				return false;
			}
		}
		return true;
	}
}