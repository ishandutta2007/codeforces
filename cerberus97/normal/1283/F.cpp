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

const int N = 2e5 + 10;

int a[N], par[N];
bool vis[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
	}
	int root = a[1];
	vis[root] = true;
	int p = 1;
	for (int val = n; val >= 1; --val) {
		if (vis[val]) {
			continue;
		}
		vis[val] = true;
		int prv = a[p];
		for (p = p + 1; p < n; ++p) {
			int u = a[p];
			if (vis[u] == true) {
				break;
			} else {
				par[u] = prv;
				vis[u] = true;
				prv = u;
			}
		}
		par[val] = prv;
	}
	cout << root << '\n';
	for (int i = 1; i <= n; ++i) {
		if (i != root) {
			cout << i << ' ' << par[i] << '\n';
		}
	}
}