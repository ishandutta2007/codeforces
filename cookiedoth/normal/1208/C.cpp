/*

Code for problem C by cookiedoth
Generated 25 Aug 2019 at 05.51 P



10%

30%

50%

70%

100%

^_^
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

vector<vector<int> > v0 = {
	{8, 9, 1, 13},
	{3, 12, 7, 5},
	{0, 2, 4, 11},
	{6, 10, 15, 14}
};

int n;

signed main() {
	fast_io();
	cin >> n;
	vector<vector<int> > ans(n, vector<int> (n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int i0 = i / 4, j0 = j / 4, id = i0 * (n / 4) + j0;
			ans[i][j] = id * 16 + v0[i % 4][j % 4];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}