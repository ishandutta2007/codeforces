/*

Code for problem B by cookiedoth
Generated 07 Jun 2019 at 03.22 P



10%

30%

50%

70%

100%

=_=
>_<
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

const ll MOD = 998244353;
const int mx = 2e5 + 228;
int n;
vector<vector<int> > g;
ll dp[mx], fact[mx];

void dfs(int v, int pv) {
	dp[v] = 1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v);
			dp[v] = (dp[v] * dp[v1]) % MOD;
		}
	}
	if (v != pv) {
		dp[v] = (dp[v] * fact[g[v].size()]) % MOD;
	}
	else {
		dp[v] = (dp[v] * fact[(int)g[v].size()]) % MOD;
		dp[v] = (dp[v] * (ll)n) % MOD;
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
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fact[0] = 1;
	for (int i = 1; i <= mx; ++i) {
		fact[i] = (fact[i - 1] * (ll)i) % MOD;
	}
	dfs(0, 0);
	cout << dp[0] << endl;
}