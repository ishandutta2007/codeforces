/*

Code for problem D by savkinsd2089
Generated 09 Jan 2019 at 05.47 pm
The Moon is Waxing Crescent (11% of Full)










(@)(@)(@)(@)(@)

>_<
-_-
-_-

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

const int mx = 3e5 + 228;
const int C = 3;
const int INF = 1e9;
int n, n3, a[mx], b[mx], suf[mx][C], pref[C];

int get(int pos) {
	int res = 0;
	vector<int> cur(C);
	for (int i = 0; i < C; ++i) {
		cur[i] = n3 - pref[i];
		if (cur[i] < 0) {
			return INF;
		}
	}
	for (int i = 0; i < C; ++i) {
		res += abs(cur[i] - suf[pos][i]);
	}
	return res / 2;
}

signed main() {
	cin >> n;
	n3 = n / C;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < C; ++j) {
			suf[i][j] = suf[i + 1][j];
		}
		suf[i][a[i]]++;
	}

	int k = get(0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < C; ++j) {
			pref[j]++;
			int res = get(i + 1);
			if (a[i] != j) {
				res++;
			}
			if (res == k) {
				b[i] = j;
				break;
			}
			pref[j]--;
		}
		if (a[i] != b[i]) {
			k--;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << b[i];
	}
	cout << endl;
}