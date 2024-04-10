/*

Code for problem B by savkinsd2089
Generated 09 Jan 2019 at 06.36 pm
The Moon is Waxing Crescent (11% of Full)










(@)(@)(@)(@)(@)

~_^
\_()_/
z_z

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

const int mx = 1e5 + 228;
int n, k, ans[mx];
vector<pair<int, int> > v;
vector<int> clr[mx];

signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		v.push_back({val, i});
	}

	sort(all(v));
	int cur_clr = 0, clr_cnt = 0;
	for (int i = 0; i < n; ++i) {
		clr[cur_clr].push_back(v[i].second);
		chkmax(clr_cnt, cur_clr + 1);
		cur_clr++;
		if (i < n - 1 && v[i].first != v[i + 1].first) {
			cur_clr = 0;
		}
	}

	if (clr_cnt > k) {
		cout << "NO" << endl;
		return 0;
	}

	int ptr = 0, kek = k - clr_cnt;
	for (int i = 0; i < kek; ++i) {
		while (clr[ptr].size() == 1) {
			ptr++;
		}
		clr[clr_cnt++].push_back(clr[ptr].back());
		clr[ptr].pop_back();
	}

	for (int i = 0; i < k; ++i) {
		for (auto id : clr[i]) {
			ans[id] = i;
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
}