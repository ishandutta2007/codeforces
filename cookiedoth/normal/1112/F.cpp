#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <random>
#include <numeric>
#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(). a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T &x, ostream &out = cerr) {
	output(x.begin(), x.end(), out);
}

template<class T> int chkmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmax(T &a, const T &b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 2e5 + 228;
int n, able[mx];
ll a[mx], dp[2][mx];
vector<int> g[mx], children[mx], g1[2 * mx];

void dfs(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			dfs(v1, v);
		}
	}

	if (children[v].empty()) {
		dp[0][v] = 0;
		dp[1][v] = a[v];
		able[v] = 1;
		return;
	}

	vector<pair<ll, int> > dp0, dp1, diff;
	for (auto v1 : children[v]) {
		dp0.push_back({dp[0][v1], v1});
		dp1.push_back({dp[1][v1], v1});
		diff.push_back({dp[1][v1] - dp[0][v1], v1});
	}

	sort(all(dp0));
	sort(all(dp1));
	sort(all(diff));
	ll sum_dp1 = 0;
	for (auto pp : dp1) {
		sum_dp1 += pp.first;
	}
	vector<int> useful;
	int sz = children[v].size();
	for (int i = sz - 1; i >= 0; --i) {
		if (diff[i].first == diff.back().first) {
			useful.push_back(diff[i].second);
		}
	}

	for (int i = 0; i < sz - 1; ++i) {
		g1[v].push_back(diff[i].second + n);
	}
	for (auto v1 : useful) {
		g1[v].push_back(v1);
	}
	if (useful.size() > 1) {
		for (auto v1 : useful) {
			g1[v].push_back(v1 + n);
		}
	}

	dp[0][v] = sum_dp1 - diff.back().first;

	ll val1 = sum_dp1;
	ll val2 = sum_dp1 - diff.back().first + a[v];
	if (val1 <= val2) {
		for (auto v1 : children[v]) {
			g1[v + n].push_back(v1 + n);
		}
	}
	if (val2 <= val1) {
		able[v] = 1;
		for (int i = 0; i < sz - 1; ++i) {
			g1[v + n].push_back(diff[i].second + n);
		}
		for (auto v1 : useful) {
			g1[v + n].push_back(v1);
		}
		if (useful.size() > 1) {
			for (auto v1 : useful) {
				g1[v + n].push_back(v1 + n);
			}
		}
	}
	dp[1][v] = min(val1, val2);
}

int used[2 * mx];
vector<int> ans;

void restore(int v) {
	if (v >= n && able[v - n]) {
		ans.push_back(v - n);
	}
	used[v] = 1;
	for (auto v1 : g1[v]) {
		if (used[v1] == 0) {
			restore(v1);
		}
	}
}

int main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	dfs(0, 0);

	/*cerr << "able" << endl;
	output(able, able + n);*/

	restore(n);
	sort(all(ans));
	cout << dp[1][0] << " " << ans.size() << endl;
	for (auto x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}