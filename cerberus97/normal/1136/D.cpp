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

const int N = 3e5 + 10;

int p[N];
vector<int> g[N];
bool good[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		if (v == p[n]) {
			good[u] = true;
		}
	}
	set<int> dead_weights;
	int ans = 0;
	for (int i = n - 1; i >= 1; --i) {
		if (!good[p[i]]) {
			dead_weights.insert(p[i]);
		} else {
			int ctr = 0;
			for (auto &v : g[p[i]]) {
				if (dead_weights.count(v)) {
					++ctr;
				}
			}
			if (ctr == (int) dead_weights.size()) {
				++ans;
			} else {
				dead_weights.insert(p[i]);
			}
		}
	}
	cout << ans << endl;
}