/*

Code for problem E by cookiedoth
Generated 13 Feb 2020 at 05.46 P



10%

30%

50%

70%

100%

=_=
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

const int mx = 510;
const int lg = 10;
int n, m, q, dp[4][mx][mx], sq[mx][mx], pw2[mx], scp[mx][mx][lg][lg];
vector<string> S;

void calc_scp() {
	pw2[1] = 0;
	for (int i = 2; i < mx; ++i) {
		pw2[i] = pw2[i / 2] + 1;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			scp[i][j][0][0] = sq[i][j];
			for (int it = 1; it < lg; ++it) {
				scp[i][j][0][it] = scp[i][j][0][it - 1];
				int j1 = j + (1 << (it - 1));
				if (j1 < m) {
					chkmax(scp[i][j][0][it], scp[i][j1][0][it - 1]);
				}
			}
			for (int pi = 1; pi < lg; ++pi) {
				for (int pj = 0; pj < lg; ++pj) {
					scp[i][j][pi][pj] = scp[i][j][pi - 1][pj];
					int i1 = i + (1 << (pi - 1));
					if (i1 < n) {
						chkmax(scp[i][j][pi][pj], scp[i1][j][pi - 1][pj]);
					}
				}
			}
		}
	}
}

int get(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) {
		return 0;
	}
	int pw_x = pw2[x2 - x1 + 1], pw_y = pw2[y2 - y1 + 1];
	int _x = x2 - (1 << pw_x) + 1, _y = y2 - (1 << pw_y) + 1;
	int res = max(max(scp[x1][y1][pw_x][pw_y], scp[_x][y1][pw_x][pw_y]), max(scp[x1][_y][pw_x][pw_y], scp[_x][_y][pw_x][pw_y]));
	// cerr << "get " << x1 << " " << y1 << " " << x2 << " " << y2 << " = " << res << endl;
	return res;
}

int calc_dp(int id, int x, int y, int dx, int dy, char c) {
	if (dp[id][x][y] != -1) {
		return dp[id][x][y];
	}
	dp[id][x][y] = 0;
	if (S[x][y] == c) {
		dp[id][x][y] = 1;
		int _x = x + dx;
		int _y = y + dy;
		if (_x >= 0 && _x < n && _y >= 0 && _y < m) {
			int v1 = calc_dp(id, x, _y, dx, dy, c);
			int v2 = calc_dp(id, _x, y, dx, dy, c);
			int v3 = calc_dp(id, _x, _y, dx, dy, c);
			dp[id][x][y] += min(min(v1, v2), v3);
		}
	}
	return dp[id][x][y];
}

void calc_dp() {
	for (int it = 0; it < 4; ++it) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				dp[it][i][j] = -1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			calc_dp(0, i, j, -1, -1, 'R');
			calc_dp(1, i, j, -1, 1, 'G');
			calc_dp(2, i, j, 1, -1, 'Y');
			calc_dp(3, i, j, 1, 1, 'B');
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			sq[i][j] = min(min(dp[0][i][j], dp[1][i][j + 1]), min(dp[2][i + 1][j], dp[3][i + 1][j + 1]));
		}
	}
	calc_scp();
}

int check(int x1, int y1, int x2, int y2, int len) {
	if (len == 0) {
		return 1;
	}
	int res = get(x1 + len - 1, y1 + len - 1, x2 - len, y2 - len);
	return (res >= len);
}

void process() {
	for (int i = 0; i < q; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		int l = 0, r = min(n, m);
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(x1, y1, x2, y2, mid + 1)) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		cout << 4 * l * l << "\n";
	}
}

signed main() {
	fast_io();
	cin >> n >> m >> q;
	S.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}
	calc_dp();
	// cerr << "sq" << endl;
	// for (int i = 0; i < n - 1; ++i) {
	// 	for (int j = 0; j < m - 1; ++j) {
	// 		cerr << sq[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
	calc_scp();
	process();
}