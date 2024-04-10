/*

Code for problem A by cookiedoth
Generated 19 Nov 2019 at 05.32 P


  !











\_()_/
o_O
-_-

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

const int mx = 110;
int n, m, k, a[mx][mx], id[mx][mx];
vector<pair<int, int> > vp;

void solve() {
	cin >> n >> m >> k;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == 'R') {
				a[i][j] = 1;
				cnt++;
			} else {
				a[i][j] = 0;
			}
		}
	}
	vp.clear();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; ++j) {
				vp.emplace_back(i, j);
			}
		} else {
			for (int j = m - 1; j >= 0; --j) {
				vp.emplace_back(i, j);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			id[i][j] = k - 1;
		}
	}
	int len = cnt / k, cntp1 = cnt % k, ptr = 0;
	for (int i = 0; i < k; ++i) {
		int cur_len = (i < cntp1 ? len + 1 : len);
		int cur_sum = 0;
		while (cur_sum < cur_len) {
			id[vp[ptr].first][vp[ptr].second] = i;
			cur_sum += a[vp[ptr].first][vp[ptr].second];
			ptr++;
		}
	}
	string ch;
	for (int i = 0; i < 10; ++i) {
		ch.push_back('0' + i);
	}
	for (char c = 'a'; c <= 'z'; ++c) {
		ch.push_back(c);
	}
	for (char c = 'A'; c <= 'Z'; ++c) {
		ch.push_back(c);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ch[id[i][j]];
		}
		cout << "\n";
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
}