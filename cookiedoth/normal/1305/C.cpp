/*

Code for problem C by cookiedoth
Generated 03 Mar 2020 at 05.43 PM



10%

30%

50%

70%

100%

o_O
^_^
~_^

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

const int mx = 2e5 + 228;
int n, a[mx], m;
ll cnt[mx], C[mx];

int mul(int a, int b) {
	return (1LL * a * b) % m;
}

int power(int a, ll deg) {
	int res = 1;
	while (deg) {
		if (deg & 1LL) {
			res = mul(res, a);
		}
		a = mul(a, a);
		deg >>= 1;
	}
	return res;
}

signed main() {
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		a[i] %= m;
	}
	for (int i = 0; i < n; ++i) {
		int ptr = a[i];
		for (int it = 0; it < m; ++it) {
			C[it] += cnt[ptr];
			if (ptr == 0) {
				ptr = m - 1;
			} else {
				ptr--;
			}
		}
		cnt[a[i] % m]++;
	}
	int res = 1;
	for (int i = 0; i < m; ++i) {
		res = mul(res, power(i, C[i]));
	}
	cout << res << endl;
}