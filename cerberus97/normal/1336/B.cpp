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

const int N = 1e5 + 10;
const ll inf = 9e18 + 42;

inline ll eval(ll x, ll y, ll z);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int m = 3;
		vector<vector<int>> w(m);
		vector<int> sz(m);
		for (int i = 0; i < m; ++i) {
			cin >> sz[i];
		}
		for (int i = 0; i < m; ++i) {
			w[i].resize(sz[i]);
			for (auto& j : w[i]) {
				cin >> j;
			}
			sort(w[i].begin(), w[i].end());
		}
		vector<int> ids = {0, 1, 2};
		ll best = inf;
		do {
			vector<int> p(3, 0);
			for (p[0] = 0; p[0] < sz[ids[0]]; ++p[0]) {
				while (p[1] < sz[ids[1]] - 1 and w[ids[0]][p[0]] >= w[ids[1]][p[1] + 1]) {
					++p[1];
				}
				while (p[2] < sz[ids[2]] - 1 and w[ids[0]][p[0]] > w[ids[2]][p[2]]) {
					++p[2];
				}
				best = min(best, eval(w[ids[0]][p[0]], w[ids[1]][p[1]], w[ids[2]][p[2]]));
			}
		} while (next_permutation(ids.begin(), ids.end()));
		cout << best << '\n';
	}
}

inline ll eval(ll x, ll y, ll z) {
	ll t1 = (x - y), t2 = (y - z), t3 = (z - x);
	return t1 * t1 + t2 * t2 + t3 * t3;
}