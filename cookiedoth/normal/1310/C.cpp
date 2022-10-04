/*

Code for problem C by cookiedoth
Generated 24 Feb 2020 at 07.49 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

const int mx = 1010;
int n, m, lcp[mx][mx];
vector<pair<int, int> > substr;
ll k;
string s;

void sort_substr() {
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			substr.emplace_back(i, j);
		}
	}
	auto cmp = [] (pair<int, int> a, pair<int, int> b) -> bool {
		int common = lcp[a.first][b.first];
		int pos1 = a.first + common, pos2 = b.first + common;
		if (pos1 <= a.second && pos2 <= b.second) {
			return (s[pos1] < s[pos2]);
		} else {
			return (a.second - a.first < b.second - b.first);
		}
	};
	sort(all(substr), cmp);
	// cerr << "sorted_substr" << endl;
	// for (auto pp : substr) {
	// 	cerr << s.substr(pp.first, pp.second - pp.first + 1) << endl;
	// }
}

ll dp[mx][mx], suf[mx][mx];

int bigger_or_eq_pos(int l, int r, int i) {
	int common = lcp[l][i];
	if (l + common > r) {
		return i + (r - l);
	}
	if (i + common >= n) {
		return n;
	}
	if (s[i + common] > s[l + common]) {
		return i + common;
	} else {
		return n;
	}
}

ll F(int l, int r) {
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = 0;
			suf[i][j] = 0;
		}
	}
	dp[0][n] = 1;
	for (int i = n; i >= 0; --i) {
		suf[0][i] = 1;
	}
	for (int cnt = 1; cnt <= m; ++cnt) {
		for (int i = n - 1; i >= 0; --i) {
			int pos = bigger_or_eq_pos(l, r, i);
			dp[cnt][i] = suf[cnt - 1][pos + 1];
			suf[cnt][i] = min(k, dp[cnt][i] + suf[cnt][i + 1]);
		}
	}
	return dp[m][0];
}

signed main() {
	fast_io();
	cin >> n >> m >> k;
	cin >> s;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
		}
	}
	sort_substr();
	int l = 0, r = (int)substr.size() - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (F(substr[mid + 1].first, substr[mid + 1].second) >= k) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << s.substr(substr[l].first, substr[l].second - substr[l].first + 1) << endl;
}