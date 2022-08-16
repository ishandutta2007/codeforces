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

const int N = 5e5 + 10;

vector<int> g[N];
int l[N], r[N], nxt = 1;

void solve(int u, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	l[1] = nxt++;
	solve(1, 0);
	for (int i = 1; i <= n; ++i) {
		cout << l[i] << ' ' << r[i] << '\n';
	}
}

void solve(int u, int p) {
	for (auto &v : g[u]) {
		if (v != p) {
			l[v] = nxt++;
		}
	}
	r[u] = nxt++;
	reverse(g[u].begin(), g[u].end());
	for (auto &v : g[u]) {
		if (v != p) {
			solve(v, u);
		}
	}
}