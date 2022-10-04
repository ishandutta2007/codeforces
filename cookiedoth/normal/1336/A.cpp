/*

Code for problem A by cookiedoth
Generated 15 Apr 2020 at 05.38 PM










(@)(@)(@)(@)(@)

z_z
>_<
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
int n, k, h[mx], sz[mx];
vector<vector<int> > g;

void dfs(int v, int pv, int cur_h) {
	h[v] = cur_h;
	sz[v] = 1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v, cur_h + 1);
			sz[v] += sz[v1];
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> k;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0, 0);
	vector<int> chels;
	for (int i = 0; i < n; ++i) {
		chels.push_back(h[i] - (sz[i] - 1));
	}
	sort(rall(chels));
	ll ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += chels[i];
	}
	cout << ans << endl;
}