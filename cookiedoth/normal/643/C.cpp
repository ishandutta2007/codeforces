/*

Code for problem C by cookiedoth
Generated 11 Dec 2020 at 07.18 PM



10%

30%

50%

70%

100%

^_^
~_^
=_=

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

const ld INF = 1e18;
const ld EPS = 1e-9;

struct line {
	ld k, b, x;
};

ld intersect(const line &a, const line &b) {
	if (fabsl(a.k - b.k) < EPS) {
		if (a.b > b.b) {
			return -INF;
		} else {
			return INF;
		}
	}
	return -(a.b - b.b) / (a.k - b.k);
}

struct cht {
	vector<line> st;

	void clear() {
		// cerr << "clear\n";
		st.clear();
	}

	// k decreases
	void add_line(ld k, ld b) {
		// cerr << "add_line " << k << ' ' << b << '\n';
		k = -k;
		line L = {k, b, -INF};
		while (!st.empty() && intersect(L, st.back()) <= st.back().x) {
			st.pop_back();
		}
		if (!st.empty()) {
			L.x = intersect(L, st.back());
		}
		st.push_back(L);
	}

	// x decreases
	ld get(ld x) {
		x = -x;
		if (st.empty()) {
			return INF;
		}
		int l = 0, r = (int)st.size() - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (st[mid + 1].x > x) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		// cerr << "get " << x << " " << st[l].k * x + st[l].b << '\n';
		return st[l].k * x + st[l].b;
	}
};

const int mx = 2e5 + 228;
const int K = 55;
int n, k;
ll arr[mx];

void read() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

ll pref[mx];
ld coeff[mx];

void calc() {
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + arr[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		coeff[i] = coeff[i + 1] + 1.0 / (ld)arr[i];
	}
}

ld dp[mx], _dp[mx];

void init() {
	fill(dp + 1, dp + n + 1, -INF);
}

cht T;

void recalc_layer() {
	// cerr << "recalc_layer" << '\n';
	T.clear();
	fill(_dp, _dp + n + 1, -INF);
	for (int i = 0; i < n; ++i) {
		T.add_line(-pref[i], dp[i]);
		ld Tg = T.get(coeff[i + 1]);
		// cerr << "Tg = " << Tg << '\n';
		chkmax(_dp[i + 1], Tg + pref[i + 1] * coeff[i + 1]);
		// cerr << "_dp " << i + 1 << " = " << _dp[i + 1] << '\n';
	}
	swap(dp, _dp);
}

void calc_dp() {
	init();
	for (int i = 0; i < k; ++i) {
		recalc_layer();
	}
	ld ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (ld)arr[i] * coeff[i];
	}
	// cerr << "ans = " << ans << '\n';
	cout << setprecision(10) << fixed << ans - dp[n] << '\n';
}

signed main() {
	fast_io();
	read();
	calc();
	calc_dp();
}