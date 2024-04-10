/*

Code for problem C by cookiedoth
Generated 06 May 2020 at 06.12 PM


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

int n, m;
vector<vector<int> > g, _g;

void read() {
	cin >> n >> m;
	g.resize(n);
	_g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		_g[v].push_back(u);
	}
}

const int mx = 2e5 + 228;
vector<int> topsort, _topsort;
int used[mx], dp[mx], _dp[mx];

void dfs(int v) {
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			dfs(v1);
		}
	}
	topsort.push_back(v);
}

void check_no_cycles() {
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			dfs(i);
		}
	}
	reverse(all(topsort));
	_topsort.resize(n);
	for (int i = 0; i < n; ++i) {
		_topsort[topsort[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (auto v : g[i]) {
			if (_topsort[v] < _topsort[i]) {
				cout << -1 << endl;
				exit(0);
			}
		}
	}
}

void dp_dfs(int v) {
	used[v] = 1;
	dp[v] = v;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			dp_dfs(v1);
		}
		chkmin(dp[v], dp[v1]);
	}
}

void dp_dfs2(int v) {
	used[v] = 1;
	_dp[v] = v;
	for (auto v1 : _g[v]) {
		if (used[v1] == 0) {
			dp_dfs2(v1);
		}
		chkmin(_dp[v], _dp[v1]);
	}
}

void calc_dp() {
	fill(used, used + n, 0);
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			dp_dfs(i);
		}
	}
	fill(used, used + n, 0);
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			dp_dfs2(i);
		}
	}
}

int ans[mx];

void print_ans() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int can = (i <= dp[i] && i <= _dp[i]);
		ans[i] = can;
		sum += can;
	}
	cout << sum << endl;
	for (int i = 0; i < n; ++i) {
		cout << (ans[i] ? 'A' : 'E');
	}
	cout << endl;
}

signed main() {
	fast_io();
	read();
	check_no_cycles();
	calc_dp();
	print_ans();
}