/*

Code for problem E by cookiedoth
Generated 04 Jun 2020 at 07.20 PM



10%

30%

50%

70%

100%

=_=
\_()_/
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
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

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

//to_change
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mx = 1e5 + 228;
int n, m;
vector<vector<int> > g;

void read() {
	cin >> n >> m;
	g.assign(n, vector<int> ());
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
}

vector<vector<int> > children;
int root, used[mx], par[mx];

void dfs(int v) {
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			children[v].push_back(v1);
			par[v1] = v;
			dfs(v1);
		}
	}
}

int tin[mx], _tin[mx], tout[mx], timer;

void pre_tree(int v) {
	_tin[timer] = v;
	tin[v] = timer++;
	for (auto v1 : children[v]) {
		pre_tree(v1);
	}
	tout[v] = timer - 1;
}

int upper(int u, int v) {
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int try_tree(int v) {
	// cerr << "try_tree " << v << endl;
	for (int i = 0; i < n; ++i) {
		children[i].clear();
	}
	fill(used, used + n, 0);
	dfs(v);
	timer = 0;
	pre_tree(v);
	for (int i = 0; i < n; ++i) {
		for (auto v : g[i]) {
			if (par[v] != i && !upper(v, i)) {
				return 0;
			}
		}
	}
	root = v;
	// cerr << "root = " << v << endl;
	// cerr << "children" << endl;
	// for (int i = 0; i < n; ++i) {
	// 	if (!children[i].empty()) {
	// 		cerr << i << ":";
	// 		for (auto v : children[i]) {
	// 			cerr << " " << v;
	// 		}
	// 		cerr << endl;
	// 	}
	// }
	// cerr << "tin" << endl;
	// output(tin, tin + n);
	// cerr << "tout" << endl;
	// output(tout, tout + n);
	// cerr << "_tin" << endl;
	// output(_tin, _tin + n);
	return 1;
}

int process() {
	for (int it = 0; it < 100; ++it) {
		int v = rng() % n;
		if (try_tree(v)) {
			root = v;
			return 1;
		}
	}
	return 0;
}

const int INF = 1e9;
pair<int, int> dp[mx];

void update(pair<int, int> &pp, int x) {
	vector<int> kek = {pp.first, pp.second, x};
	sort(all(kek));
	pp = {kek[0], kek[1]};
}

void update(pair<int, int> &pp, const pair<int, int> &pp1) {
	vector<int> kek = {pp.first, pp.second, pp1.first, pp1.second};
	sort(all(kek));
	pp = {kek[0], kek[1]};
}

void calc_dp(int v) {
	for (auto v1 : children[v]) {
		calc_dp(v1);
		update(dp[v], dp[v1]);
	}
}

int is_good[mx];

void calc_good(int v) {
	if (v != root) {
		if (dp[v].first != INF && dp[v].second >= tin[v] && is_good[_tin[dp[v].first]]) {
			is_good[v] = 1;
		}
	}
	for (auto v1 : children[v]) {
		calc_good(v1);
	}
}

const int MULT = 5;

void solve_tree() {
	for (int i = 0; i < n; ++i) {
		dp[i] = {INF, INF};
	}
	for (int i = 0; i < n; ++i) {
		for (auto v : g[i]) {
			update(dp[i], tin[v]);
		}
	}
	calc_dp(root);
	// cerr << "dp" << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << dp[i].first << " " << dp[i].second << endl;
	// }
	fill(is_good, is_good + n, 0);
	is_good[root] = 1;
	calc_good(root);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (is_good[i]) {
			ans.push_back(i);
		}
	}
	if (MULT * ans.size() >= n) {
		for (auto x : ans) {
			cout << x + 1 << " ";
		}
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
}

void solve() {
	read();
	children.assign(n, vector<int> ());
	if (!process()) {
		cout << -1 << '\n';
		return;
	}
	solve_tree();
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}