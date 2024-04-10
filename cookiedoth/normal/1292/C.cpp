/*

Code for problem C by cookiedoth
Generated 19 Jan 2020 at 04.56 P



10%

30%

50%

70%

100%

=_=
\_()_/
o_O

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

const int mx = 3010;

struct edge {
	int u, v;
};

vector<edge> e;
vector<vector<int> > g;
int n;
ll dp[2 * mx][2 * mx], sz[2 * mx];

int dfs(int v, int pv) {
	int cur_sz = 1;
	for (auto en : g[v]) {
		if (e[en].v != pv) {
			int new_sz = dfs(e[en].v, v);
			sz[en] = new_sz;
			sz[en ^ 1] = n - new_sz;
			cur_sz += new_sz;
		}
	}
	return cur_sz;
}

ll calc_dp(int e1, int e2) {
	if (dp[e1][e2] != -1) {
		return dp[e1][e2];
	}
	ll delta = 0;
	for (auto en : g[e[e1].v]) {
		if (en != (e1 ^ 1)) {
			chkmax(delta, calc_dp(en, e2));
		}
	}
	for (auto en : g[e[e2].v]) {
		if (en != (e2 ^ 1)) {
			chkmax(delta, calc_dp(e1, en));
		}
	}
	dp[e1][e2] = delta + sz[e1] * sz[e2];
	return dp[e1][e2];
}

signed main() {
	fast_io();
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(e.size());
		e.push_back({u, v});
		g[v].push_back(e.size());
		e.push_back({v, u});
	}
	for (int i = 0; i < 2 * (n - 1); ++i) {
		for (int j = 0; j < 2 * (n - 1); ++j) {
			dp[i][j] = -1;
		}
	}
	dfs(0, 0);
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		calc_dp(2 * i, 2 * i + 1);
		chkmax(ans, dp[2 * i][2 * i + 1]);
	}
	cout << ans << endl;
}