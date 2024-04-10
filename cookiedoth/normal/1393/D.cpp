/*

Code for problem D by cookiedoth
Generated 07 Aug 2020 at 07.18 PM



10%

30%

50%

70%

100%

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

int n, m;
vector<string> a;

void reverse_rows_a() {
	for (int i = 0; i < n; ++i) {
		reverse(all(a[i]));
	}
}

void reverse_columns_a() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n - 1 - j; ++j) {
			swap(a[j][i], a[n - 1 - j][i]);
		}
	}
}

void reverse_rows(vector<vector<int> > &v) {
	for (int i = 0; i < n; ++i) {
		reverse(all(v[i]));
	}
}

void reverse_columns(vector<vector<int> > &v) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n - 1 - j; ++j) {
			swap(v[j][i], v[n - 1 - j][i]);
		}
	}
}

vector<vector<int> > get() {
	vector<vector<int> > dp(n, vector<int> (m));
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i - 1][j] == a[i][j] && a[i][j - 1] == a[i][j]) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
		}
	}
	return dp;
}

void process() {
	vector<vector<int> > dp1 = get();

	reverse_rows_a();

	vector<vector<int> > dp2 = get();
	reverse_rows(dp2);

	reverse_columns_a();

	vector<vector<int> > dp3 = get();
	reverse_rows(dp3);
	reverse_columns(dp3);

	reverse_rows_a();

	vector<vector<int> > dp4 = get();

	reverse_columns(dp4);

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans += min(min(dp1[i][j], dp2[i][j]), min(dp3[i][j], dp4[i][j])) + 1;
		}
	}
	cout << ans << '\n';
}

void read() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

signed main() {
	fast_io();
	read();
	process();
}