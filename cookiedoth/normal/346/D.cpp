/*

Code for problem D by savkinsd2089
Generated 03 Sep 2018 at 06.30 pm
The Moon is Waning Crescent (44% of Full)










(@)(@)(@)(@)(@)

o_O
~_^
=_=

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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

const int mx = 1e6 + 228;
int n, m, s, t, d[mx], deg[mx];
vector<int> g[mx], g_rev[mx], q2;
queue<int> q1;

void read() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g_rev[v].push_back(u);
	}
	cin >> s >> t;
	s--;
	t--;
}

int bfs() {
	if (q1.empty())
		return 0;
	int cur_dist = d[q1.front()];
	while (!q1.empty()) {
		int v = q1.front();
		q1.pop();
		for (auto v1 : g_rev[v]) {
			deg[v1]--;
			if (d[v1] == -1) {
				if (deg[v1] == (int)g[v1].size() - 1)
					q2.push_back(v1);
				if (deg[v1] == 0) {
					d[v1] = cur_dist;
					q1.push(v1);
				}
			}
		}
	}
	for (auto v : q2) {
		if (d[v] == -1) {
			d[v] = cur_dist + 1;
			q1.push(v);
		}
	}
	q2.clear();
}

void solve() {
	memset(d, -1, n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		deg[i] = g[i].size();
	}
	d[t] = 0;
	q1.push(t);
	while (bfs()) {}
}

signed main() {
	fast_io();
	read();
	solve();
	cout << d[s] << endl;
}