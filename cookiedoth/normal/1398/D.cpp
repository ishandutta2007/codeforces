/*

Code for problem D by cookiedoth
Generated 14 Aug 2020 at 05.46 PM


  !











^_^
~_^
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

const int mx = 210;
int n1, n2, n3, a1[mx], a2[mx], a3[mx];

void read() {
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < n1; ++i) {
		cin >> a1[i];
	}
	for (int i = 0; i < n2; ++i) {
		cin >> a2[i];
	}
	for (int i = 0; i < n3; ++i) {
		cin >> a3[i];
	}
	sort(a1, a1 + n1);
	sort(a2, a2 + n2);
	sort(a3, a3 + n3);
	reverse(a1, a1 + n1);
	reverse(a2, a2 + n2);
	reverse(a3, a3 + n3);
}

ll dp[mx][mx][mx];

void calc_dp() {
	ll ans = 0;
	for (int c1 = 0; c1 <= n1; ++c1) {
		for (int c2 = 0; c2 <= n2; ++c2) {
			for (int c3 = 0; c3 <= n3; ++c3) {
				if (c1 && c2) {
					chkmax(dp[c1][c2][c3], dp[c1 - 1][c2 - 1][c3] + a1[c1 - 1] * a2[c2 - 1]);
				}
				if (c1 && c3) {
					chkmax(dp[c1][c2][c3], dp[c1 - 1][c2][c3 - 1] + a1[c1 - 1] * a3[c3 - 1]);
				}
				if (c2 && c3) {
					chkmax(dp[c1][c2][c3], dp[c1][c2 - 1][c3 - 1] + a2[c2 - 1] * a3[c3 - 1]);
				}
				chkmax(ans, dp[c1][c2][c3]);
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	calc_dp();
}