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

const int N = 2e3 + 10;

vector<int> g[N];
int p[N], c[N], sz[N], a[N];

void dfs(int u);
bool solve(int u, vector<int> ids);

int main() {
	fast_cin();
	int n; cin >> n;
	int root = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i] >> c[i];
		if (p[i] == 0) {
			root = i;
		} else {
			g[p[i]].pb(i);
		}
	}
	dfs(root);
	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 1);
	if (!solve(root, ids)) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}

void dfs(int u) {
	sz[u] = 1;
	for (auto& v : g[u]) {
		dfs(v);
		sz[u] += sz[v];
	}
}

bool solve(int u, vector<int> ids) {
	if (c[u] >= sz[u]) {
		return false;
	}
	a[u] = ids[c[u]];
	int j = 0;
	for (auto& v : g[u]) {
		vector<int> temp(sz[v]);
		for (auto& i : temp) {
			if (j == c[u]) {
				++j;
			}
			i = ids[j++];
		}
		if (!solve(v, temp)) {
			return false;
		}
	}
	return true;
}