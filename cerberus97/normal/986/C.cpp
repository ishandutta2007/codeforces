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

const int N = (1 << 22) + 10;

bool have[N], seen[N];
int a[N], comp[N];

void dfs(int u, int c, int n);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
		have[a[i]] = true;
	}
	int nxt = 0;
	for (int i = 1; i <= m; ++i) {
		if (!comp[a[i]]) {
			comp[a[i]] = ++nxt;
			dfs(a[i], nxt, n);
		}
	}
	cout << nxt;
}

void dfs(int u, int c, int n) {
	seen[u] = true;
	int v = (1 << n) - 1 - u;
	if (have[v] and !comp[v]) {
		comp[v] = c;
		if (!seen[v]) {
			dfs(v, c, n);
		}
	}
	for (int i = 0; i < n; ++i) {
		v = u | (1 << i);
		if (!seen[v]) {
			dfs(v, c, n);
		}
	}
}