/*

Code for problem D by cookiedoth
Generated 23 Apr 2020 at 06.41 PM


  !











-_-
z_z
=_=

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
int n, deg[mx], par[mx];
vector<vector<int> > g, children;

void hang(int v, int pv) {
	par[v] = pv;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			hang(v1, v);
		}
	}
}

int timestamp;
vector<pair<int, int> > ans = {{0, 0}};

void go(int v) {
	int out_timer = timestamp;
	ans.emplace_back(v, ++timestamp);
	int made = 0;
	for (int i = 0; i < children[v].size(); ++i) {
		if (timestamp >= deg[v] && made == 0) {
			made = 1;
			int rem_ch = (int)children[v].size() - i;
			timestamp = out_timer - rem_ch;
			ans.emplace_back(v, timestamp);
		}
		go(children[v][i]);
	}
	if (made == 0) {
		timestamp = out_timer;
		ans.emplace_back(v, timestamp);
	}
	ans.emplace_back(par[v], ++timestamp);
}

void read() {
	cin >> n;
	g.resize(n);
	children.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	hang(0, 0);
}

signed main() {
	fast_io();
	read();
	for (auto v1 : children[0]) {
		go(v1);
	}
	cout << ans.size() << "\n";
	for (auto pp : ans) {
		cout << pp.first + 1 << " " << pp.second << "\n";
	}
}