/*

Code for problem E by cookiedoth
Generated 31 Mar 2020 at 06.07 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

^_^
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

const int MOD = 998244353;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

int power(int a, int deg) {
	int res = 1;
	while (deg) {
		if (deg & 1) {
			res = mul(a, res);
		}
		a = mul(a, a);
		deg >>= 1;
	}
	return res;
}

vector<vector<int> > mul(vector<vector<int> > a, vector<vector<int> > b) {
	vector<vector<int> > c(2, vector<int> (2));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int pos = 0; pos < 2; ++pos) {
				add(c[i][j], mul(a[i][pos], b[pos][j]));
			}
		}
	}
	return c;
}

vector<vector<int> > power(vector<vector<int> > a, int deg) {
	vector<vector<int> > res = {
		{1, 0},
		{0, 1}
	};
	while (deg) {
		if (deg & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		deg >>= 1;
	}
	return res;
}

int n, m, L, R;

signed main() {
	fast_io();
	cin >> n >> m >> L >> R;
	int even = R / 2 - (L - 1) / 2;
	int odd = (R - L + 1) - even;
	int ans;
	if (n % 2 == 0 || m % 2 == 0) {
		vector<vector<int> > matrix = {
			{even, odd},
			{odd, even}
		};
		matrix = power(matrix, n);
		matrix = power(matrix, m);
		ans = matrix[0][0] % MOD;
	} else {
		ans = power(odd + even, n);
		ans = power(ans, m);
	}
	cout << ans << endl;
}