/*

Code for problem B by cookiedoth
Generated 03 Apr 2020 at 06.01 PM



10%

30%

50%

70%

100%

~_^
=_=
>_<

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

const int B = 30;
int d, m, cnt[B], dp[B + 1];

int mul(int a, int b) {
	return (1LL * a * b) % m;
}

void add(int &a, int b) {
	a = (a + b) % m;
}

void solve() {
	cin >> d >> m;
	for (int i = 0; i < B; ++i) {
		cnt[i] = min(1 << (i + 1), d + 1);
	}
	int sum = 1;
	for (int i = 0; i < B; ++i) {
		cnt[i] -= sum;
		sum += cnt[i];
	}
	fill(dp, dp + B, 0);
	int sum_dp = 0;
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < i; ++j) {
			add(dp[i], dp[j]);
		}
		add(dp[i], 1);
		dp[i] = mul(dp[i], cnt[i]);
		add(sum_dp, dp[i]);
	}
	cout << sum_dp << "\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}