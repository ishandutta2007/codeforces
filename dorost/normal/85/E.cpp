/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012, M = 1000 * 1000 * 1000 + 7;
int x[N], y[N], n;
vector <int> g[N];
bool vis[N], a[N];

bool dfs(int v) {
	vis[v] = true;
	for (auto u : g[v]) {
		if (vis[u]) {
			if (a[u] == a[v]) 
				return false;
		} else {
			a[u] = 1 - a[v];
			if (!dfs(u)) {
				return false;
			}
		}
	}
	return true;
}

pair <bool, int> is_valid (int x2) {
	if (x2 == -1)
		return {false, 1};
	for (int i = 0; i < n; i++)
		g[i].clear(), vis[i] = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > x2) {
				g[i].push_back(j);
			}
		}
	}
	int x3 = 1;
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			a[i] = false;
			f &= dfs(i);
			x3 *= 2;
			x3 %= M;
		}
	}
	return {f, x3};
}

int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> x[i] >> y[i];
	int l = -1, r = N * 2;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid).F) 
			r = mid;
		else
			l = mid;
	}
	cout << r << ' ' << is_valid(r).S;
}