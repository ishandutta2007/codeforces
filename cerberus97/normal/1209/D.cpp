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

int par[N];

bool merge(int u, int v);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
	}
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		ans += merge(x, y);
	}
	cout << k - ans << endl;
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

bool merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return false;
	}
	par[u] = v;
	return true;
}