/*

Code for problem F by cookiedoth
Generated 31 Mar 2020 at 05.44 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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

const int MOD = 998244353;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

int sum(int a, int b) {
	return (a + b) % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

const int mx = 3e5 + 228;
int n, dp[mx][2][2], _dp[2][2];
vector<vector<int> > g;

void dfs(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v);
		}
	}
	dp[v][0][0] = 1;
	dp[v][1][0] = 1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			for (int d1 = 0; d1 < 2; ++d1) {
				for (int d2 = 0; d2 < 2; ++d2) {
					_dp[d1][d2] = 0;
				}
			}
			for (int our = 0; our < 2; ++our) {
				for (int from = 0; from < 2; ++from) {
					for (int d1 = 0; d1 < 2; ++d1) {
						for (int d2 = 0; d2 < 2; ++d2) {
							for (int edge = 0; edge < 2; ++edge) {
								if (our == 0 && d1 == 0 && edge == 0) {
									continue;
								}
								if (d1 == 1 && d2 == 0 && edge == 0) {
									continue;
								}
								add(_dp[our][max(from, edge)], mul(dp[v][our][from], dp[v1][d1][d2]));
							}
						}
					}
				}
			}
			swap(dp[v], _dp);
		}
	}
	// cerr << "dp " << v << endl;
	// for (int i = 0; i < 2; ++i) {
	// 	for (int j = 0; j < 2; ++j) {
	// 		cerr << dp[v][i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
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
	dfs(0, 0);
	int ans = sum(sum(dp[0][0][0], dp[0][0][1]), dp[0][1][1]);
	ans = (ans - 1 + MOD) % MOD;
	cout << ans << endl;
}