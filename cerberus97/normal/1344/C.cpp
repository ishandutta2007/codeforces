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

const int N = 2e5 + 10;

vector<int> g1[N], g2[N];
int seen1[N], seen2[N];

bool dfs(vector<int>* g, int u, int* seen);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g1[u].pb(v);
		g2[v].pb(u);
	}
	int cnt = 0;
	string ans(n, 'E');
	for (int i = 1; i <= n; ++i) {
		if (!seen1[i] and !seen2[i]) {
			ans[i - 1] = 'A';
			++cnt;
		}
		if (!seen1[i]) {
			if (!dfs(g1, i, seen1)) {
				cout << -1 << '\n';
				return 0;
			}
		}
		if (!seen2[i]) {
			if (!dfs(g2, i, seen2)) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << cnt << '\n' << ans << endl;
}

bool dfs(vector<int>* g, int u, int* seen) {
	seen[u] = 1;
	for (auto& v : g[u]) {
		if (!seen[v]) {
			if (!dfs(g, v, seen)) {
				return false;
			}
		} else if (seen[v] == 1) {
			return false;
		}
	}
	seen[u] = 2;
	return true;
}