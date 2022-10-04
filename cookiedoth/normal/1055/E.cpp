/*

Code for problem E by savkinsd2089
Generated 10 Nov 2018 at 06.45 pm
The Moon is Waxing Crescent (9% of Full)



10%

30%

50%

70%

100%

^_^
z_z
~_^

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

const int mx = 1528;
int n, s, m, k, a[mx], b[mx], pref[mx], pr[mx], dp[mx][mx];
vector<pair<int, int> > seg;

int check(int val) {
	for (int i = 0; i < n; ++i) {
		if (a[i] <= val) {
			b[i] = 1;
		}
		else {
			b[i] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + b[i - 1];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j] = 0;
		}
	}

	for (auto pp : seg) {
		int l = pp.first;
		int r = pp.second;
		chkmax(dp[r][1], pref[r + 1] - pref[l]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			chkmax(dp[pr[i]][j + 1], dp[i][j] + pref[pr[i] + 1] - pref[i + 1]);
			if (i < n - 1) {
				chkmax(dp[i + 1][j], dp[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		chkmax(ans, dp[i][m]);
	}

	return (ans >= k);
}

signed main() {
	cin >> n >> s >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pr[i] = i;
	}
	for (int i = 0; i < s; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		seg.push_back({l, r});
		for (int j = max(l - 1, 0); j < r; ++j) {
			pr[j] = max(pr[j], r); 
		}
	}

	int l = 0, r = 1e9 + 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	if (l == 1e9 + 1)
		l = -1;
	cout << l << endl;
}