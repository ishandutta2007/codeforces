#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 1000000;


int n, m, k;
vector<int> g[MAXN];
bool u[MAXN];


bool read() {
	if (! (cin >> n >> m >> k))  return false;
	for (int i=0; i<n; ++i)
		g[i].clear();
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf ("%d%d", &a, &b);
		--a, --b;
		g[a].push_back (b);
		g[b].push_back (a);
	}
	return true;
}


int dfs (int v) {
	u[v] = true;
	int res = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!u[to])
			res += dfs (to);
	}
	return res;
}

void solve() {
	memset (u, 0, sizeof u);
	vector<int> comp;
	for (int i=0; i<n; ++i)
		if (!u[i])
			comp.push_back (min (k, dfs (i)));

	int sz = (int) comp.size();
	int sum = 0;
	for (int i=0; i<sz; ++i)
		sum += comp[i];

	int ans = 0;
	int csz = sz;
	while (sum < 2 * csz - 2) {
		--csz;
		++ans;
	}

	if (k == 1)
		ans = max (0, sz - 2);

	cout << ans << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}