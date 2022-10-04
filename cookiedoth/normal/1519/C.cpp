/*

Code for problem C by cookiedoth
Generated 29 Apr 2021 at 05.45 PM










(@)(@)(@)(@)(@)

o_O
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
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

const int mx = 2e5 + 228;
int n, u[mx], s[mx];
ll pref[mx];
vector<vector<int>> a;

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> u[i];
		u[i]--;
	}
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	a.assign(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		a[u[i]].push_back(s[i]);
	}
	sort(rall(a), [] (const vector<int>& a, const vector<int>& b) { return a.size() < b.size(); });
	for (int i = 0; i < n; ++i) {
		sort(all(a[i]));
	}
	vector<ll> ans(n + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			pref[j + 1] = pref[j] + a[i][j];
		}
		for (int k = 1; k <= a[i].size(); ++k) {
			ans[k] += pref[a[i].size()] - pref[a[i].size() % k];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}