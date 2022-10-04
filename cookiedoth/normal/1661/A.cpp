/*

Code for problem A by cookiedoth
Generated 09 Apr 2022 at 10.35 AM



10%

30%

50%

70%

100%

\_()_/
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

const ll INF = 1e18;
const int MAX_N = 26;
int n, a[MAX_N], b[MAX_N];
ll dp[MAX_N][2];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 1; i < n; ++i) {
		fill(dp[i], dp[i] + 2, INF);
		for (int s1 = 0; s1 < 2; ++s1) {
			for (int s2 = 0; s2 < 2; ++s2) {
				int v1 = a[i - 1], v2 = b[i - 1];
				int w1 = a[i], w2 = b[i];
				if (s1) {
					swap(v1, v2);
				}
				if (s2) {
					swap(w1, w2);
				}
				chkmin(dp[i][s2], dp[i - 1][s1] + (ll)abs(v1 - w1) + (ll)abs(v2 - w2));
			}
		}
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}