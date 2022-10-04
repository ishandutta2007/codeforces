/*

Code for problem F by cookiedoth
Generated 31 Jul 2020 at 01.54 PM



10%

30%

50%

70%

100%

~_^
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

struct st {
	st() {}

	vector<int> t, mod;
	int n;

	void init(int _n) {
		n = _n;
		t.resize(4 * n);
		mod.resize(4 * n);
	}

	void update(int l, int r, int val, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			mod[v] += val;
			t[v] += val;
		} else {
			int tm = (tl + tr) >> 1;
			update(l, r, val, v * 2, tl, tm);
			update(l, r, val, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]) + mod[v];
		}
	}

	void update(int l, int r, int val) {
		update(l, r, val, 1, 0, n - 1);
	}

	int get(int pos, int v, int tl, int tr) {
		if (tl == tr) {
			return t[v];
		}
		int tm = (tl + tr) >> 1;
		int res = mod[v];
		if (pos <= tm) {
			res += get(pos, v * 2, tl, tm);
		} else {
			res += get(pos, v * 2 + 1, tm + 1, tr);
		}
		return res;
	}

	void chkmax(int pos, int val) {
		int old_val = get(pos, 1, 0, n - 1);
		if (val > old_val) {
			update(pos, pos, val - old_val);
		}
	}

	int get() {
		return t[1];
	}
};

int n;

struct seg {
	int l, r, clr;
};

bool operator < (const seg &a, const seg &b) {
	return a.r < b.r;
}

vector<seg> a;
vector<int> coords = {-1};

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int l, r, clr;
		cin >> l >> r >> clr;
		clr--;
		a.push_back({l, r, clr});
		coords.push_back(l);
		coords.push_back(r);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());
	for (int i = 0; i < n; ++i) {
		a[i].l = lower_bound(all(coords), a[i].l) - coords.begin();
		a[i].r = lower_bound(all(coords), a[i].r) - coords.begin();
	}
	int C = coords.size();
	vector<vector<pair<int, int> > > vp(C);
	for (int i = 0; i < n; ++i) {
		vp[a[i].r].emplace_back(a[i].l, a[i].clr);
	}
	vector<st> T(2);
	T[0].init(C);
	T[1].init(C);
	for (int i = 0; i < C; ++i) {
		for (auto pp : vp[i]) {
			T[pp.second ^ 1].update(0, pp.first - 1, 1);
		}
		int v0 = T[0].get(), v1 = T[1].get();
		T[0].chkmax(i, v1);
		T[1].chkmax(i, v0);
	}
	int ans = max(T[0].get(), T[1].get());
	cout << ans << '\n';
}

signed main() {
	fast_io();
	solve();
}