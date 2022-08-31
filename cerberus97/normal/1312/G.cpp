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

const int N = 1e6 + 10;

vector<pii> g[N];
bool imp[N];
int ans[N];

void dfs(int u, int val, int& offset);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p; char c;
		cin >> p >> c;
		g[p].pb({int(c), i});
	}
	int k; cin >> k;
	vector<int> special(k);
	for (auto& a : special) {
		cin >> a;
		imp[a] = true;
	}
	for (int i = 0; i <= n; ++i) {
		sort(g[i].begin(), g[i].end());
	}
	int offset = 0;
	dfs(0, n, offset);
	for (auto& a : special) {
		cout << ans[a] << ' ';
	}
	cout << endl;
}

void dfs(int u, int val, int& offset) {
	if (imp[u]) {
		ans[u] = min(ans[u], val + offset + 1);
	}
	offset += imp[u];
	val = min(val, ans[u] + imp[u] - offset);
	for (auto& e : g[u]) {
		int v = e.second;
		ans[v] = ans[u] + 1;
		dfs(v, val, offset);
	}
}