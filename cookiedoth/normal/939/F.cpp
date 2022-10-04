/*

Code for problem D by cookiedoth
Generated 01 Apr 2020 at 11.03 AM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
\_()_/
^_^

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

const int INF = 1e9 + 228;
const int mx = 5e5 + 228;
const int K = 110;
int n, k, seg_l[K], seg_r[K], dp[2][mx], _dp[2][mx];
deque<int> D;

void clear() {
	D.clear();
}

void push(int x) {
	while (!D.empty() && x < D.back()) {
		D.pop_back();
	}
	D.push_back(x);
}

void pop(int x) {
	if (D.front() == x) {
		D.pop_front();
	}
}

int get_min() {
	return D.front();
}

void recalc_dp(int len1, int len2) {
	// cerr << "recalc_dp " << len1 << " " << len2 << endl;

	for (int i = 0; i <= n; ++i) {
		chkmin(dp[1][i], dp[0][i] + 1);
		chkmin(dp[0][i], dp[1][i] + 1);
	}

	copy(dp[0], dp[0] + n + 1, _dp[0]);
	fill(_dp[1], _dp[1] + n + 1, INF);
	for (int i = len1 + len2; i <= n; ++i) {
		_dp[1][i] = dp[1][i - len1 - len2];
	}
	clear();
	for (int i = len2; i <= n; ++i) {
		push(dp[0][i - len2]);
		chkmin(_dp[1][i], get_min() + 1);
		if (i >= len1 + len2) {
			pop(dp[0][i - len1 - len2]);
		}
	}
	clear();
	for (int i = 0; i <= n; ++i) {
		push(dp[1][i]);
		chkmin(_dp[0][i], get_min() + 1);
		if (i >= len1) {
			pop(dp[1][i - len1]);
		}
	}
	swap(dp, _dp);
}

signed main() {
	fast_io();
	cin >> n >> k;
	assert(k <= 50);
	for (int i = 0; i < k; ++i) {
		cin >> seg_l[i] >> seg_r[i];
	}
	seg_l[k] = 2 * n;
	fill(dp[0], dp[0] + n + 1, INF);
	fill(dp[1], dp[1] + n + 1, INF);
	dp[0][0] = 0;
	for (int i = 0; i < k; ++i) {
		recalc_dp(seg_r[i] - seg_l[i], seg_l[i + 1] - seg_r[i]);
		// output(dp[0], dp[0] + n + 1, cout);
		// output(dp[1], dp[1] + n + 1, cout);
	}
	if (dp[0][n] == INF && dp[1][n] == INF) {
		cout << "Hungry" << endl;
	} else {
		cout << "Full" << endl;
		cout << min(dp[0][n], dp[1][n]) << endl;
	}
}