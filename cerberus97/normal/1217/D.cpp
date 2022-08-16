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
 
const int N = 5e3 + 10;
 
vector<int> g[N];
vector<pii> edges;
int color[N];

bool cycle(int u);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		edges.pb({u, v});
	}
	bool dag = true;
	for (int i = 1; i <= n; ++i) {
		if (!color[i] and cycle(i)) {
			dag = false;
			break;
		}
	}
	if (dag) {
		cout << 1 << '\n';
		for (int i = 1; i <= m; ++i) {
			cout << 1 << ' ';
		}
	} else {
		cout << 2 << '\n';
		for (auto &e : edges) {
			if (e.first < e.second) {
				cout << 1 << ' ';
			} else {
				cout << 2 << ' ';
			}
		}
	}
}

bool cycle(int u) {
	color[u] = 1;
	for (auto &v : g[u]) {
		if (color[v] == 1) {
			return true;
		} else if (color[v] == 0 and cycle(v)) {
			return true;
		}
	}
	color[u] = 2;
	return false;
}