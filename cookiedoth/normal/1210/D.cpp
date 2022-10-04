/*

Code for problem D by cookiedoth
Generated 22 Sep 2019 at 12.57 P



10%

30%

50%

70%

100%

^_^
-_-
z_z

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
int n, m;
ll ans, out_deg[mx];
vector<vector<int> > in_edges;

signed main() {
	fast_io();
	cin >> n >> m;
	in_edges.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		if (u > v) {
			swap(u, v);
		}
		out_deg[v]++;
		in_edges[u].push_back(v);
	}
	for (int i = 0; i < n; ++i) {
		ans += out_deg[i] * (ll)in_edges[i].size();
	}
	cout << ans << '\n';
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int v;
		cin >> v;
		v--;
		ans -= (ll)in_edges[v].size() * out_deg[v];
		out_deg[v] += (ll)in_edges[v].size();
		for (auto u : in_edges[v]) {
			out_deg[u]--;
			ans += out_deg[u];
			ans -= (ll)in_edges[u].size();
			in_edges[u].push_back(v);
		}
		in_edges[v].clear();
		cout << ans << '\n';
	}
}