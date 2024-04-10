/*

Code for problem A by cookiedoth
Generated 27 Jul 2020 at 11.41 AM


  !











-_-
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

const int K = 20;
int n;
string s, t;
vector<vector<int> > g;

void add_edge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

vector<int> used;

int dfs(int v) {
	used[v] = 1;
	int res = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			res += dfs(v1);
		}
	}
	return res;
}

void solve() {
	cin >> n >> s >> t;
	g.assign(K, vector<int> ());
	for (int i = 0; i < n; ++i) {
		if (t[i] < s[i]) {
			cout << -1 << '\n';
			return;
		}
		add_edge(s[i] - 'a', t[i] - 'a');
	}
	used.assign(K, 0);
	int ans = 0;
	for (int i = 0; i < K; ++i) {
		if (used[i] == 0) {
			ans += dfs(i) - 1;
		}
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}