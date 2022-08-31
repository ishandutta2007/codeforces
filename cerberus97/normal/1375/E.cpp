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

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	vector<vector<int>> b(n + 1);
	b[0] = a;
	int m = 0;
	vector<vector<int>> g(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) {
				g[i].pb(j);
				++m;
			}
		}
	}
	cout << m << '\n';
	vector<vector<pii>> ops(n + 1);
	vector<pii> extra;
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		for (auto& j : g[i]) {
			if (a[i] < a[j]) {
				extra.pb({i, j});
			} else {
				tmp.pb(j);
			}
		}
		sort(tmp.begin(), tmp.end(), [&] (int u, int v) {
			return tie(a[u], u) > tie(a[v], v);
		});
		for (auto& j : tmp) {
			ops[i + 1].pb({i, j});
			swap(a[i], a[j]);
		}
		b[i + 1] = a;
		// for (auto& i : a) {
		// 	cout << i << ' ';
		// }
		// cout << endl;
	}
	for (auto& [u, v] : extra) {
		int lo = 1, hi = n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (b[mid][u] < b[mid][v]) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		ops[hi].pb({u, v});
		// assert(b[hi][u] == b[hi][v]);
	}
	for (auto& r : ops) {
		for (auto& [u, v] : r) {
			cout << u + 1 << ' ' << v + 1 << '\n';
		}
	}
}