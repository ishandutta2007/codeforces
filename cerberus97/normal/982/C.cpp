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

const int N = 1e5 + 10;

vector<int> g[N];
int sz[N];
int cuts = 0;

bool dfs(int i, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	if (n % 2 == 1) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	cout << cuts;
}

bool dfs(int i, int p) {
	sz[i] = 1;
	for (auto &j : g[i]) {
		if (j != p) {
			if (dfs(j, i)) {
				sz[i] += sz[j];
			} else {
				++cuts;
			}
		}
	}
	return (sz[i] % 2);
}