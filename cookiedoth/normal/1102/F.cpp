/*

Code for problem F by savkinsd2089
Generated 09 Jan 2019 at 06.01 pm
The Moon is Waxing Crescent (11% of Full)



10%

30%

50%

70%

100%

=_=
~_^
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

const int N = 16;
const int M = 1e4 + 228;
const int INF = 1e9;
int n, m, a[N][M], d[N][N], d2[N][N], dp[1 << N][N][N];

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int dist = INF;
			for (int x = 0; x < m; ++x) {
				chkmin(dist, abs(a[i][x] - a[j][x]));
			}
			d[i][j] = dist;
			d[j][i] = dist;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int dist = INF;
			for (int x = 0; x < m - 1; ++x) {
				chkmin(dist, abs(a[i][x] - a[j][x + 1]));
			}
			d2[i][j] = dist;
		}
	}

	/*cerr << "d" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << endl;
	}

	cerr << "d2" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cerr << d2[i][j] << " ";
		}
		cerr << endl;
	}*/

	for (int i = 0; i < n; ++i) {
		dp[1 << i][i][i] = INF;
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int s = 0; s < n; ++s) {
			for (int t = 0; t < n; ++t) {
				for (int v = 0; v < n; ++v) {
					if (((i >> v) & 1) == 0) {
						chkmax(dp[i ^ (1 << v)][s][v], min(dp[i][s][t], d[t][v]));
						//cerr << "istv " << i << " " << s << " " << t << " " << v << endl;
						//cerr << "now dp " << (i ^ (1 << v)) << " " << s << " " << v << " = " << dp[i ^ (1 << v)][s][v] << endl;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			chkmax(ans, min(dp[(1 << n) - 1][i][j], d2[j][i]));
		}
	}

	cout << ans << endl;
}