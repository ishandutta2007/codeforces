/*

Code for problem  by cookiedoth
Generated 03 Mar 2020 at 06.43 PM


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

const int INF = 1e9;
const int mx = 5010;
int n, m, a[mx], cnt[mx];

signed main() {
	fast_io();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
	}
	int all_cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (i + j <= n) {
				cnt[i + j]++;
				all_cnt++;
			}
		}
	}
	if (m > all_cnt) {
		cout << -1 << endl;
		exit(0);
	}
	int cur_INF = INF;
	for (int i = n; i >= 1; --i) {
		if (all_cnt - cnt[i] >= m) {
			a[i] = cur_INF;
			cur_INF -= mx;
			all_cnt -= cnt[i];
		} else {
			int need_len = m - (all_cnt - cnt[i]);
			int val = (i - 1) + (i - 1 - need_len * 2 + 1);
			a[i] = val;
			break;
		}
	}
	output(a + 1, a + n + 1, cout);
}