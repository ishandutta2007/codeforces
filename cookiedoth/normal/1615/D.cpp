/*

Code for problem D by cookiedoth
Generated 24 Dec 2021 at 07.05 PM


  !











>_<
o_O
^_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX_N = 2e5 + 228;
int n, m, val[MAX_N];
vector<vector<pair<int, int>>> g;
vector<pair<int, int>> Q;
vector<vector<int>> edges;

// void dfs(int v, int pv) {
// 	for (auto [v1, p] : g[v]) {
// 		if (v1 == pv) {
// 			continue;
// 		}
// 		if (p == -1) {
// 			p = 0;
// 		}
// 		val[v1] = val[v] ^ p;
// 		dfs(v1, v);
// 	}
// }

bool dfs(int v) {
	for (auto [v1, p] : g[v]) {
		if (p == -1) {
			continue;
		}
		if (val[v1] == -1) {
			val[v1] = val[v] ^ p;
			if (!dfs(v1)) {
				return false;
			}
		}
		if (!(val[v1] == (val[v] ^ p))) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> n >> m;
	edges.clear();
	g.assign(n, vector<pair<int, int>>());
	Q.resize(m);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		edges.push_back({u, v, w});
		if (w >= 0) {
			w = __builtin_popcount(w) % 2;
		}
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	for (int i = 0; i < m; ++i) {
		int a, b, p;
		cin >> a >> b >> p;
		a--;
		b--;
		// cerr << "add " << a << ' ' << b << ' ' << p << '\n';
		g[a].push_back({b, p});
		g[b].push_back({a, p});
	}
	fill(val, val + n, -1);
	for (int i = 0; i < n; ++i) {
		if (val[i] == -1) {
			val[i] = 0;
			if (!dfs(i)) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	for (auto e : edges) {
		cout << e[0] + 1 << ' ' << e[1] + 1 << ' ' << (e[2] == -1 ? (val[e[0]] ^ val[e[1]]) : e[2]) << '\n';
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}