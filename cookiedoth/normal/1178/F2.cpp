/*

Code for problem F2 by cookiedoth
Generated 20 Jul 2019 at 07.50 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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

const int NEUTRAL = 1e9;

struct min_rmq {
	vector<int> t;
	int n;

	void build(int *a, int v, int tl, int tr) {
		if (tl == tr)
			t[v] = a[tl];
		else {
			int tm = ((tl + tr) >> 1);
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = min(t[v * 2], t[v * 2 + 1]);
		}
	}

	min_rmq() {}

	void init(int *a, int _n) {
		n = 1;
		while (n < _n) {
			n <<= 1;
		}
		t.resize(2 * n);
		build(a, 1, 0, n - 1);
	}

	void update(int pos, int val) {
		pos += n;
		t[pos] = val;
		while (true) {
			pos >>= 1;
			if (pos > 0)
				t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
			else
				break;
		}
	}

	int get(int l, int r) {
		l += n;
		r += n;
		int res = NEUTRAL;
		while (l <= r) {
			if (l & 1) {
				chkmin(res, t[l]);
				l++;
				continue;
			}
			if ((r & 1) == 0) {
				chkmin(res, t[r]);
				r--;
				continue;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

const int mx = 1010;
const int MX = 4e6 + 228;
const ll MOD = 998244353;
int n, m, p[MX], L[mx], R[mx], poss[2 * mx][2 * mx], arr2[2 * mx];
vector<vector<int> > points;
ll dp[mx][mx];
vector<int> coords;
min_rmq T;

void check() {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (L[i] > R[j] || R[i] < L[j]) {
				continue;
			}
			if (L[i] < L[j] && R[j] < R[i]) {
				continue;
			}
			cout << 0 << endl;
			exit(0);
		}
	}
}

void read_and_compress() {
	cin >> n >> m;
	points.resize(n);
	for (int i = 0; i < n; ++i) {
		L[i] = m;
	}
	for (int i = 0; i < m; ++i) {
		cin >> p[i];
		p[i]--;
		points[p[i]].push_back(i);
		chkmin(L[p[i]], i);
		chkmax(R[p[i]], i);
	}
	T.init(p, m);
	for (int i = 0; i < n; ++i) {
		coords.push_back(L[i]);
		coords.push_back(R[i]);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());
	for (int i = 0; i < n; ++i) {
		L[i] = lower_bound(all(coords), L[i]) - coords.begin();
		R[i] = lower_bound(all(coords), R[i]) - coords.begin();
		arr2[L[i]] = i;
		arr2[R[i]] = i;
	}
	m = coords.size();
}

void chkseg() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (L[i] <= R[j]) {
				int both = NEUTRAL;
				for (int x = 0; x < n; ++x) {
					if (L[i] <= L[x] && R[x] <= R[j]) {
						chkmin(both, x);
					}
				}
				int val = T.get(coords[L[i]], coords[R[j]]);
				//cerr << L[i] << " " << R[j] << " " << both << " " << val << endl;
				if (val >= both) {
					poss[L[i]][R[j]] = 1;
				}
			}
		}
	}
}

ll w3[mx];
int w3_calced[mx];

ll get_w3(int color) {
	if (w3_calced[color]) {
		return w3[color];
	}
	w3[color] = 1;
	for (int i = 0; i < (int)points[color].size() - 1; ++i) {
		int l = points[color][i] + 1;
		int r = points[color][i + 1] - 1;
		if (l <= r) {
			int p1 = lower_bound(all(coords), l) - coords.begin();
			int p2 = upper_bound(all(coords), r) - coords.begin() - 1;
			if (p1 <= p2) {
				w3[color] = (w3[color] * dp[p1][p2]) % MOD;
			}
		}
	}
	w3_calced[color] = 1;
	return w3[color];
}

void calc_dp() {
	for (int i = 0; i < m; ++i) {
		if (poss[i][i]) {
			dp[i][i] = 1;
		}
	}
	for (int len = 2; len <= m; ++len) {
		for (int l = 0; l <= m - len; ++l) {
			int r = l + len - 1;
			if (!poss[l][r]) {
				continue;
			}
			int seg_id = (*min_element(arr2 + l, arr2 + r + 1));
			int pos_l = L[seg_id], pos_r = R[seg_id];
			//cerr << "pos " << pos_l << " " << pos_r << endl;
			ll w1 = 0, w2 = 0, cur_w3 = 0;
			if (r == pos_r) {
				w1 = 1;
			}
			else {
				for (int i = pos_r + 1; i < r; ++i) {
					w1 = (w1 + dp[pos_r + 1][i] * dp[i + 1][r]) % MOD;
				}
				w1 = (w1 + 2 * dp[pos_r + 1][r]) % MOD;
			}
			if (l == pos_l) {
				w2 = 1;
			}
			else {
				for (int i = l + 1; i < pos_l; ++i) {
					w2 = (w2 + dp[l][i - 1] * dp[i][pos_l - 1]) % MOD;
				}
				w2 = (w2 + 2 * dp[l][pos_l - 1]) % MOD;
			}
			//cerr << "w1 w2 = " << w1 << " " << w2 << endl;
			cur_w3 = get_w3(seg_id);
			dp[l][r] = (((w1 * w2) % MOD) * cur_w3) % MOD;
			//cerr << "dp " << l << " " << r << " = " << dp[l][r] << endl;
		}
	}
}

void print_ans() {
	cout << dp[0][m - 1] << endl;
}

signed main() {
	fast_io();
	read_and_compress();
	/*cerr << "rc" << endl;
	cerr << "coords" << endl;
	output(all(coords));
	cerr << "LR" << endl;
	for (int i = 0; i < n; ++i) {
		cerr << L[i] << " " << R[i] << endl;
	}
	cerr << "arr2" << endl;
	output(arr2, arr2 + m);*/
	check();
	//cerr << "check" << endl;
	chkseg();
	/*cerr << "chkseg" << endl;
	cerr << "poss" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cerr << poss[i][j] << " ";
		}
		cerr << endl;
	}*/
	calc_dp();
	//cerr << "calc_dp" << endl;
	print_ans();
}