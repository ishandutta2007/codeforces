/*

Code for problem F by cookiedoth
Generated 06 Sep 2022 at 11.39 AM
The Moon is Waxing Gibbous (82% of Full)


 ] 
 
Il] 


-_-
z_z
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#include <array>
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

struct SegmentTree {
	vector<int> t;
	int n;

	SegmentTree(int _n): n(_n), t(4 * _n, -1) {}

	void push(int v) {
		if (t[v] != -1) {
			t[v * 2] = t[v * 2 + 1] = t[v];
			t[v] = -1;
		}
	}

	void update(int l, int r, int val, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			t[v] = val;
		} else {
			push(v);
			int tm = (tl + tr) >> 1;
			update(l, r, val, v * 2, tl, tm);
			update(l, r, val, v * 2 + 1, tm + 1, tr);
		}
	}

	void update(int l, int r, int val) {
		// cerr << "update " << l << ' ' << r << ' ' << val << '\n';
		update(l, r, val, 1, 0, n - 1);
	}

	int get(int pos) {
		int tl = 0, tr = n - 1, v = 1;
		while (tl < tr) {
			if (t[v] != -1) {
				return t[v];
			}
			int tm = (tl + tr) >> 1;
			if (pos <= tm) {
				tr = tm;
				v *= 2;
			} else {
				tl = tm + 1;
				v = v * 2 + 1;
			}
		}
		// cerr << "get " << pos << " = " << t[v] << '\n';
		return t[v];
	}

	void to_vector(int v, int tl, int tr, vector<int>& out) {
		if (tl == tr || t[v] != -1) {
			for (int i = tl; i <= tr; ++i) {
				out.push_back(t[v]);
			}
			return;
		}
		int tm = (tl + tr) >> 1;
		to_vector(v * 2, tl, tm, out);
		to_vector(v * 2 + 1, tm + 1, tr, out);
	}

	vector<int> to_vector() {
		vector<int> res;
		to_vector(1, 0, n - 1, res);
		// cerr << "to_vector:\n";
		// output(all(res));
		return res;
	}
};

const ll INF = 1e18;
const int MAX_N = 2e5 + 228;
int n, t, g[MAX_N], c[MAX_N], d[MAX_N], lb[MAX_N], red[MAX_N];
ll ans;

void read() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> g[i] >> c[i];
	}
	int shift = 0;
	for (int i = 0; i < n; ++i) {
		int c1 = (shift + c[i]) % t;
		lb[i] = (g[i] - c1 + t) % t;
		red[i] = t - g[i];
		// cerr << "seg " << lb[i] << ' ' << red[i] << '\n';
		if (i < n - 1) {
			cin >> d[i];
			ans += d[i];
			shift = (shift + d[i]) % t;
		}
	}
}

vector<int> coords;

void compress() {
	coords = {0};
	for (int i = 0; i < n; ++i) {
		coords.push_back(lb[i]);
		coords.push_back((lb[i] + red[i]) % t);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());
	// cerr << "coords\n";
	// output(all(coords));
}

ll dp[MAX_N];

// from 0 to t-1
int dist(int from, int to) {
	return to >= from ? to - from : to - from + t;
}

void solve() {
	int cs = coords.size();
	SegmentTree T(cs);
	for (int i = n - 1; i >= 0; --i) {
		int pos_l = lower_bound(all(coords), lb[i]) - coords.begin();
		int pos_r = lower_bound(all(coords), (lb[i] + red[i]) % t) - coords.begin();
		int nxt_seg = T.get(pos_r);
		if (nxt_seg != -1) {
			dp[i] = dp[nxt_seg] + dist(coords[pos_r], (lb[nxt_seg] + red[nxt_seg]) % t);
		}
		// cerr << "dp " << i << " = " << dp[i] << '\n';
		if (pos_r > pos_l) {
			T.update(pos_l, pos_r - 1, i);
		} else {
			T.update(pos_l, cs - 1, i);
			if (pos_r) {
				T.update(0, pos_r - 1, i);
			}
		}
	}
	vector<int> vec = T.to_vector();
	ll opt = INF;
	for (int i = 0; i < (int)vec.size(); ++i) {
		if (vec[i] == -1) {
			opt = 0;
		} else {
			int coord = i == (int)vec.size() - 1 ? t - 1 : coords[i + 1] - 1;
			chkmin(opt, dp[vec[i]] + dist(coord, (lb[vec[i]] + red[vec[i]]) % t));
		}
	}
	ans += opt;
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	compress();
	solve();
}