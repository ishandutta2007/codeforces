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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> t(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 1);
	sort(order.begin(), order.end(), [&] (int i, int j) {
		return t[i] < t[j];
	});
	for (auto& u : order) {
		set<int> s;
		for (auto& v : g[u]) {
			s.insert(t[v]);
		}
		int cur = 1;
		while (s.count(cur)) {
			++cur;
		}
		if (cur != t[u]) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (auto& u : order) {
		cout << u << ' ';
	}
	cout << endl;
}