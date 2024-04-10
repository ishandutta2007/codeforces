/*

Code for problem E by cookiedoth
Generated 20 Jul 2020 at 03.16 PM










(@)(@)(@)(@)(@)

\_()_/
o_O
-_-

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

int get_minimal(int t) {
	return (__builtin_popcount(t + 1) > 1);
}

vector<int> ans = {-1};

void build_minimal(int t, int s) {
	queue<int> q;
	q.push(s);
	for (int it = 0; it < t; ++it) {
		int v = q.front();
		q.pop();
		q.push(ans.size());
		ans.push_back(v);
		q.push(ans.size());
		ans.push_back(v);
	}
}

const int T = 200;
int dp[T][T + 1];

void calc_dp() {
	dp[0][0] = 1;
	for (int i = 1; i < T; ++i) {
		for (int s1 = 0; s1 <= i - 1; ++s1) {
			int s2 = i - 1 - s1, w1 = 2 * s1 + 1, w2 = 2 * s2 + 1;
			int add = (w2 >= 2 * w1 || w1 >= 2 * w2);
			for (int j1 = 0; j1 <= s1; ++j1) {
				for (int j2 = 0; j2 <= s2; ++j2) {
					if (dp[s1][j1] && dp[s2][j2]) {
						dp[i][j1 + j2 + add] = 1;
					}
				}
			}
		}
	}
	// for (int i = 0; i < T; ++i) {
	// 	for (int j = 1; j < i; ++j) {
	// 		if (dp[i][j] == 0) {
	// 			cerr << i << " " << j << endl;
	// 		}
	// 	}
	// }
}

int can(int t, int k) {
	if (t < T) {
		return dp[t][k];
	}
	if (k < get_minimal(t)) {
		return 0;
	}
	if (k == 1 && t >= 3 && get_minimal(t) == 0) {
		return 0;
	}
	if (k >= t) {
		return 0;
	}
	return 1;
}

void build(int v, int t, int k) {
	if (t == 0) {
		assert(k == 0);
		return;
	}
	cerr << "build " << v << " " << t << " " << k << endl;
	if (t < T) {
		int v1 = ans.size();
		ans.push_back(v);
		int v2 = ans.size();
		ans.push_back(v);
		for (int s1 = 0; s1 <= t - 1; ++s1) {
			int s2 = t - 1 - s1, w1 = 2 * s1 + 1, w2 = 2 * s2 + 1;
			int add = (w2 >= 2 * w1 || w1 >= 2 * w2);
			for (int j1 = 0; j1 <= s1; ++j1) {
				for (int j2 = 0; j2 <= s2; ++j2) {
					if (dp[s1][j1] && dp[s2][j2] && j1 + j2 + add == k) {
						build(v1, s1, j1);
						build(v2, s2, j2);
						return;
					}
				}
			}
		}
	}
	if (k == get_minimal(t)) {
		build_minimal(t, v);
		return;
	}
	int v1 = ans.size();
	ans.push_back(v);
	int v2 = ans.size();
	ans.push_back(v);
	if (k > 2) {
		build(v2, t - 1, k - 1);
		return;
	}
	for (int s1 = 0; s1 <= t - 1; ++s1) {
		int s2 = t - 1 - s1, w1 = 2 * s1 + 1, w2 = 2 * s2 + 1;
		int add = (w2 >= 2 * w1 || w1 >= 2 * w2);
		for (int j1 = 0; j1 <= min(s1, k); ++j1) {
			for (int j2 = 0; j2 <= min(s2, k); ++j2) {
				if (j1 + j2 + add == k && can(s1, j1) && can(s2, j2)) {
					build(v1, s1, j1);
					build(v2, s2, j2);
					return;
				}
			}
		}
	}
	assert(0);
}

signed main() {
	fast_io();
	calc_dp();
	int n, k;
	cin >> n >> k;
	if (n % 2 == 0) {
		cout << "NO\n";
		exit(0);
	}
	int t = (n - 1) / 2;
	if (can(t, k) == 0) {
		cout << "NO\n";
		exit(0);
	}
	build(0, t, k);
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
}