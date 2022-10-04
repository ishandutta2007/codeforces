/*

Code for problem C by savkinsd2089
Generated 16 Dec 2018 at 05.14 pm
The Moon is Waxing Gibbous (61% of Full)



10%

30%

50%

70%

100%

o_O
>_<
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

const ll MOD = 998244353;

const int mx = 2010;
ll C[mx][mx], n, m, k, ans;

void calc_C() {
	for (int i = 0; i < mx; ++i) {
		for (int j = 0; j < mx; ++j) {
			if (j > i) {
				C[i][j] = 0;
				continue;
			}
			if (i == 0 || j == 0) {
				C[i][j] = 1;
				continue;
			}
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
}

signed main() {
	calc_C();
	cin >> n >> m >> k;
	ans = 1;
	ans *= m;
	n--;
	ans = (ans * C[n][k]) % MOD;
	for (int i = 0; i < k; ++i) {
		ans = (ans * (m - 1)) % MOD;
	}
	cout << ans << endl;
}