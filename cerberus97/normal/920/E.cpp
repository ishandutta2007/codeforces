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

set <int> g[N], unvis;
int sz[N];

void dfs(int cur, int comp);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

	for (int i = 1; i <= n; ++i) {
		unvis.insert(i);
	}

	int ctr = 0;
	while (!unvis.empty()) {
		int cur = *unvis.begin();
		unvis.erase(unvis.begin());
		dfs(cur, ctr++);
	}

	cout << ctr << endl;
	sort(sz, sz + ctr);
	for (int i = 0; i < ctr; ++i) {
		cout << sz[i] << ' ';
	}
}

void dfs(int cur, int comp) {
	sz[comp]++;
	vector <int> temp;
	for (auto &i : unvis) {
		if (g[cur].find(i) == g[cur].end()) {
			temp.pb(i);
		}
	}

	for (auto &i : temp) {
		unvis.erase(i);
	}

	for (auto &i : temp) {
		dfs(i, comp);
	}
}