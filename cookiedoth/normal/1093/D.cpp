/*

Code for problem D by savkinsd2089
Generated 15 Dec 2018 at 05.49 pm
The Moon is Waxing Gibbous (51% of Full)










(@)(@)(@)(@)(@)

~_^
=_=
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
#include <numeric>
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

const int mx = 3e5 + 228;
const ll MOD = 998244353;
int n, m, clr[mx];
ll pw2[mx];
vector<int> g[mx];

int dfs(int v, int cur_clr, vector<int> &a) {
	if (clr[v] != -1) {
		if (cur_clr != clr[v]) {
			return 1;
		}
		else {
			return 0;
		}
	}

	clr[v] = cur_clr;
	a[clr[v]]++;

	for (auto v1 : g[v]) {
		if (dfs(v1, 1 - cur_clr, a)) {
			return 1;
		}
	}

	return 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		clr[i] = -1;
	}

	ll ans = 1;

	pw2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw2[i] = (pw2[i - 1] << 1) % MOD;
	}

	for (int i = 0; i < n; ++i) {
		if (clr[i] == -1) {
			vector<int> tmp = {0, 0};
			int res = dfs(i, 0, tmp);
			if (res) {
				ans = 0;
				break;
			}
			ll upd = (pw2[tmp[0]] + pw2[tmp[1]]) % MOD;
			ans = (ans * upd) % MOD;
		}
	}

	cout << ans << endl;

	for (int i = 0; i < n; ++i) {
		g[i].clear();
	}
}

signed main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}