/*

Code for problem D by cookiedoth
Generated 22 Jun 2020 at 01.51 PM


  !











o_O
^_^
~_^

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

const int mx = 1e5 + 228;
int n, m, k, used[mx], h[mx], par[mx], min_len, opt_v;
vector<vector<int> > g;
vector<pair<int, int> > e;

void read() {
	cin >> n >> m >> k;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		e.emplace_back(u, v);
	}
	min_len = n + 1;
}

void dfs(int v) {
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			used[v1] = 1;
			h[v1] = h[v] + 1;
			par[v1] = v;
			dfs(v1);
		}
	}
}

void find_min_cycle() {
	for (auto pp : e) {
		int u = pp.first, v = pp.second;
		if (h[u] < h[v]) {
			swap(u, v);
		}
		if (h[u] - h[v] != 1 && chkmin(min_len, h[u] - h[v] + 1)) {
			opt_v = u;
		}
	}
}

vector<int> v_cnt(2);

void print_ind_r2(int r) {
	int target = (k + 1) / 2;
	cout << 1 << endl;
	for (int i = 0; i < n; ++i) {
		if (h[i] % 2 == r && target) {
			cout << i + 1 << " ";
			target--;
		}
	}
	cout << endl;
}

void process_tree() {
	for (int i = 0; i < n; ++i) {
		v_cnt[h[i] % 2]++;
	}
	if (v_cnt[0] >= v_cnt[1]) {
		print_ind_r2(0);
	} else {
		print_ind_r2(1);
	}
}

void print_ind() {
	cout << 1 << endl;
	for (int i = 0; i < (k + 1) / 2; ++i) {
		cout << opt_v + 1 << " ";
		opt_v = par[par[opt_v]];
	}
	cout << endl;
}

void print_cycle() {
	cout << 2 << endl;
	cout << min_len << endl;
	for (int i = 0; i < min_len; ++i) {
		cout << opt_v + 1 << " ";
		opt_v = par[opt_v];
	}
	cout << endl;
}

void find_ans() {
	if (min_len == n + 1) {
		process_tree();
		exit(0);
	}
	if (min_len <= k) {
		print_cycle();
	} else {
		print_ind();
	}
}

signed main() {
	fast_io();
	read();
	dfs(0);
	find_min_cycle();
	find_ans();
}