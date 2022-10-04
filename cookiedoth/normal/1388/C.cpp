/*

Code for problem C by cookiedoth
Generated 01 Aug 2020 at 10.23 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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

const int mx = 1e5 + 228;
int n, m, h[mx], p[mx];
vector<vector<int> > g;

void dfs(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v);
			p[v] += p[v1];
		}
	}
}

int check(int v, int pv) {
	int sum_h = 0;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			sum_h += h[v1];
		}
	}
	if (sum_h > h[v]) {
		return 1;
	}
	for (auto v1 : g[v]) {
		if (v1 != pv && check(v1, v)) {
			return 1;
		}
	}
	return 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	g.assign(n, vector<int> ());
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	for (int i = 0; i < n; ++i) {
		if ((h[i] + p[i]) & 1) {
			cout << "NO\n";
			return;
		}
		h[i] = (h[i] + p[i]) / 2;
		if (h[i] > p[i]) {
			cout << "NO\n";
			return;
		}
	}
	int bad = check(0, 0);
	cout << (bad ? "NO" : "YES") << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}