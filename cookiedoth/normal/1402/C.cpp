/*

Code for problem B by cookiedoth
Generated 04 Oct 2020 at 02.52 PM










(@)(@)(@)(@)(@)

~_^
=_=
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
#include <random>
#include <utility>
#include <tuple>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

const int MOD = 1e9 + 7;
const int _2 = (MOD + 1) / 2;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

const int mx = 2e3 + 10;
int n, m, cs, used[mx];
vector<vector<int> > g;
vector<int> a;

void read() {
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int dfs(int v) {
	int res = 1;
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			res += dfs(v1);
		}
	}
	return res;
}

void find_cycles() {
	used[0] = 1;
	for (auto v : g[0]) {
		if (used[v] == 0) {
			int len = dfs(v);
			a.push_back(len + 1);
		}
	}
}

int dp[mx][2 * mx], dpPref[mx][2 * mx], dpSuf[mx][2 * mx];
int dpPrefObl[mx][2 * mx], dpSufObl[mx][2 * mx];

void update_dp(int len, int idx, int stay) {
	fill(dp[idx + 1], dp[idx + 1] + m + 1, 0);
	for (int delta = 0; delta <= m; ++delta) {
		if (dp[idx][delta]) {
			add(dp[idx + 1][delta + len], dp[idx][delta]);
			add(dp[idx + 1][abs(delta - len)], dp[idx][delta]);
			if (stay) {
				add(dp[idx + 1][delta], dp[idx][delta]);
			}
		}
	}
}

void calc_dp(int stay) {
	// cerr << "calc_dp" << endl;
	// cerr << "a:" << endl;
	// output(all(a));
	// cerr << "stay = " << stay << endl;
	fill(dp[0], dp[0] + m + 1, 0);
	dp[0][0] = 1;
	for (int i = 0; i < cs; ++i) {
		update_dp(a[i], i, stay);
		// cerr << "finished_update_dp " << i << endl;
		// output(dp[i + 1], dp[i + 1] + m + 1);
	}
}

void process() {
	cs = a.size();
	calc_dp(1);
	for (int i = 0; i <= cs; ++i) {
		copy(dp[i], dp[i] + m + 1, dpPref[i]);
	}
	calc_dp(0);
	for (int i = 0; i <= cs; ++i) {
		copy(dp[i], dp[i] + m + 1, dpPrefObl[i]);
	}
	reverse(all(a));
	calc_dp(1);
	for (int i = 0; i <= cs; ++i) {
		copy(dp[i], dp[i] + m + 1, dpSuf[i]);
	}
	calc_dp(0);
	for (int i = 0; i <= cs; ++i) {
		copy(dp[i], dp[i] + m + 1, dpSufObl[i]);
	}
	reverse(all(a));
}

int ans;

int convert(int val, int pos) {
	return (pos == 0 ? val : mul(val, _2));
}

int merge(int pos, int sum) {
	int res = 0;
	for (int delta1 = -m; delta1 <= m; ++delta1) {
		int delta2 = sum - delta1;
		if (abs(delta2) <= m) {
			add(res, mul(
				convert(dpPref[pos][abs(delta1)], delta1), 
				convert(dpSuf[cs - 1 - pos][abs(delta2)], delta2)));
		}
	}
	// output(dpPref[pos], dpPref[pos] + m + 1);
	// output(dpSuf[cs - 1 - pos], dpSuf[cs - 1 - pos] + m + 1);
	// cerr << "merge " << pos << " " << sum << " = " << res << endl;
	return res;
}

int merge_obl(int pos, int sum) {
	int res = 0;
	for (int delta1 = -m; delta1 <= m; ++delta1) {
		int delta2 = sum - delta1;
		if (abs(delta2) <= m) {
			add(res, mul(
				convert(dpPrefObl[pos][abs(delta1)], delta1), 
				convert(dpSufObl[cs - 1 - pos][abs(delta2)], delta2)));
		}
	}
	return res;
}

void mergeAns() {
	add(ans, dpPrefObl[cs][0]);
	for (int i = 0; i < cs; ++i) {
		add(ans, mul(merge_obl(i, a[i] - 1), 4));
		for (int diff = 2 - a[i]; diff <= a[i] - 2; ++diff) {
			add(ans, mul(merge(i, diff), 2));
		}
	}
}

signed main() {
	fast_io();
	read();
	find_cycles();
	// cerr << "a" << endl;
	// output(all(a));
	process();
	mergeAns();
	cout << ans << '\n';
}