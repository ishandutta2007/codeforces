/*

Code for problem D by cookiedoth
Generated 15 Dec 2019 at 01.48 P










(@)(@)(@)(@)(@)

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

const int INF = 1e9;
const int mx = 5010;
int n, m, k, a[mx], b[mx], c[mx], r[mx], guards[mx], dp[mx][mx];
vector<int> can[mx];

signed main() {
	fast_io();
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	iota(r, r + n, 0);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		chkmax(r[v], u);
	}
	for (int i = 0; i < n; ++i) {
		can[r[i]].push_back(c[i]);
	}
	for (int i = 0; i <= n; ++i) {
		if (k < a[i]) {
			cout << -1 << endl;
			exit(0);
		}
		guards[i] = k - a[i];
		k += b[i];
	}
	// cerr << "guards" << endl;
	// output(guards, guards + n + 1);
	for (int i = 0; i < n; ++i) {
		copy(dp[i], dp[i] + mx, dp[i + 1]);
		for (auto val : can[i]) {
			for (int j = mx - 2; j >= 0; --j) {
				chkmax(dp[i + 1][j + 1], dp[i + 1][j] + val);
			}
		}
		for (int j = guards[i + 1] + 1; j < mx; ++j) {
			dp[i + 1][j] = -INF;
		}
	}
	int ans = 0;
	for (int i = 0; i < mx; ++i) {
		chkmax(ans, dp[n][i]);
	}
	cout << ans << endl;
}