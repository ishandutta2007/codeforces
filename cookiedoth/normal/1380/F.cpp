/*

Code for problem F by cookiedoth
Generated 12 Jul 2020 at 07.19 PM



10%

30%

50%

70%

100%

=_=
>_<
o_O

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
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

struct node {
	int dp[2][2], first_digit;

	node() {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				dp[i][j] = (i == j);
			}
		}
		first_digit = -1;
	}

	node(int digit) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = digit + 1;
		if (digit == 1) {
			dp[0][1] = 1;
		}
		dp[1][0] = 1;
		first_digit = digit;
	}
};

node combine(const node &a, const node &b) {
	if (a.first_digit == -1) {
		return b;
	}
	if (b.first_digit == -1) {
		return a;
	}
	node res;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			res.dp[i][j] = 0;
		}
	}
	res.first_digit = a.first_digit;
	for (int i1 = 0; i1 < 2; ++i1) {
		for (int j1 = 0; j1 < 2; ++j1) {
			for (int j2 = 0; j2 < 2; ++j2) {
				int coeff = (j1 ? 9 - b.first_digit : 1);
				add(res.dp[i1][j2], mul(coeff, mul(a.dp[i1][j1], b.dp[j1][j2])));
			}
		}
	}
	return res;
}

struct st {
	vector<node> t;
	int n;

	void build(const vector<int> &a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = node(a[tl]);
		} else {
			int tm = (tl + tr) >> 1;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = combine(t[v * 2], t[v * 2 + 1]);
		}
		// cerr << "segment " << tl << " " << tr << endl;
		// t[v].print();
	}

	void init(const vector<int> &a) {
		n = a.size();
		t.resize(4 * n);
		build(a, 1, 0, n - 1);
	}

	void update(int pos, int val, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = node(val);
		} else {
			int tm = (tl + tr) >> 1;
			if (pos <= tm) {
				update(pos, val, v * 2, tl, tm);
			} else {
				update(pos, val, v * 2 + 1, tm + 1, tr);
			}
			t[v] = combine(t[v * 2], t[v * 2 + 1]);
		}
	}

	node get(int l, int r, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return node();
		}
		if (l <= tl && tr <= r) {
			return t[v];
		}
		int tm = (tl + tr) >> 1;
		node res_l = get(l, r, v * 2, tl, tm);
		node res_r = get(l, r, v * 2 + 1, tm + 1, tr);
		return combine(res_l, res_r);
	}

	void update(int pos, int val) {
		// cerr << "update " << pos << " " << val << endl;
		update(pos, val, 1, 0, n - 1);
	}

	int get(int l, int r) {
		node nd = get(l, r, 1, 0, n - 1);
		return nd.dp[0][0];
	}
};

int n, m;
string s;

void solve() {
	cin >> n >> m;
	cin >> s;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = s[i] - '0';
	}
	st T;
	T.init(v);
	for (int i = 0; i < m; ++i) {
		int pos, val;
		cin >> pos >> val;
		pos--;
		T.update(pos, val);
		int res = T.get(0, n - 1);
		cout << res << '\n';
	}
}

signed main() {
	fast_io();
	solve();
}