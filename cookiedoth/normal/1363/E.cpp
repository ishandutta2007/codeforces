/*

Code for problem E by cookiedoth
Generated 31 May 2020 at 06.25 PM










(@)(@)(@)(@)(@)

^_^
~_^
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

const int mx = 2e5 + 228;
int n, b[mx], c[mx], f[mx][2];
ll a[mx];
vector<vector<int> > g, children;

void hang(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			hang(v1, v);
		}
	}
}

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		f[i][0] = (b[i] == 0 && c[i] == 1);
		f[i][1] = (b[i] == 1 && c[i] == 0);
	}
	// cerr << "f" << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << f[i][0] << " " << f[i][1] << endl;
	// }
	g.resize(n);
	children.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	hang(0, 0);
}

int used[mx], curF[2];
ll ans;

void collect(int v) {
	curF[0] += f[v][0];
	curF[1] += f[v][1];
	if (!used[v]) {
		used[v] = 1;
		for (auto v1 : children[v]) {
			collect(v1);
		}
	}
}

void process() {
	vector<pair<int, int> > order;
	for (int i = 0; i < n; ++i) {
		order.emplace_back(a[i], i);
	}
	sort(all(order));
	for (int i = 0; i < n; ++i) {
		int v = order[i].second;
		if (used[v]) {
			continue;
		}
		// cerr << "v = " << v << endl;
		curF[0] = 0;
		curF[1] = 0;
		collect(v);
		// cerr << "collected " << curF[0] << " " << curF[1] << endl;
		int delta = min(curF[0], curF[1]);
		ans += (ll)a[v] * (ll)(2 * delta);
		f[v][0] = curF[0] - delta;
		f[v][1] = curF[1] - delta;
	}
}

void print() {
	if (f[0][0] || f[0][1]) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}

signed main() {
	fast_io();
	read();
	process();
	print();
}