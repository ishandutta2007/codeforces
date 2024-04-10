/*

Code for problem D by cookiedoth
Generated 12 Apr 2020 at 06.12 PM


 ] 
 
Il] 


~_^
=_=
\_()_/

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

struct max2 {
	int m1 = 0, m2 = 0;

	max2() {}

	void add(int x) {
		if (x > m1) {
			m2 = m1;
			m1 = x;
		} else {
			if (x > m2) {
				m2 = x;
			}
		}
	}
};

const int mx = 1e5 + 228;
int n, ans, deg[mx], dp[mx][2];
vector<vector<int> > g;

void dfs(int v, int pv) {
	dp[v][0] = deg[v] - 1;
	dp[v][1] = 1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v);
			chkmax(dp[v][0], dp[v1][0] + deg[v] - 2);
			chkmax(dp[v][0], dp[v1][1] + deg[v] - 2);
			chkmax(dp[v][1], dp[v1][0] + 1);
		}
	}
	chkmax(ans, dp[v][0] + 1);
	chkmax(ans, dp[v][1]);
	max2 zeroes, all;
	int ch_cnt = 0;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			ch_cnt++;
			zeroes.add(dp[v1][0]);
			all.add(max(dp[v1][0], dp[v1][1]));
		}
	}
	if (ch_cnt >= 2) {
		chkmax(ans, all.m1 + all.m2 + deg[v] - 2);
		chkmax(ans, zeroes.m1 + zeroes.m2 + 1);
	}
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
		deg[u]++;
		deg[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		chkmax(ans, deg[i]);
	}
	dfs(0, 0);
	cout << ans << endl;
}