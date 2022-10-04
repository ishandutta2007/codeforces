/*

Code for problem E by cookiedoth
Generated 08 May 2022 at 11.02 PM










(@)(@)(@)(@)(@)

-_-
z_z
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

struct SegTree {
	vector<ll> tk, tb, sumk, sumb;
	int n;

	SegTree() {}
	SegTree(int _n): n(_n) {
		tk.resize(4 * n);
		tb.resize(4 * n);
		sumk.resize(4 * n);
		sumb.resize(4 * n);
	}

	void update(int l, int r, ll k, ll b, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			tk[v] += k;
			tb[v] += b;
			sumk[v] += (ll)(tr - tl + 1) * k;
			sumb[v] += (ll)(tr - tl + 1) * b;
			// cerr << "v = " << v << '\n';
			return;
		}
		int tm = (tl + tr) >> 1;
		update(l, r, k, b, v * 2, tl, tm);
		update(l, r, k, b, v * 2 + 1, tm + 1, tr);
		sumk[v] = sumk[v * 2] + sumk[v * 2 + 1] + (ll)(tr - tl + 1) * tk[v];
		sumb[v] = sumb[v * 2] + sumb[v * 2 + 1] + (ll)(tr - tl + 1) * tb[v];
	}

	void update(int l, int r, ll k, ll b) {
		// cerr << "update " << l << ' ' << r << ' ' << b << '\n';
		update(l, r, k, b, 1, 0, n - 1);
	}

	ll get(int l, int r, ll x, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return 0;
		}
		if (l <= tl && tr <= r) {
			return sumk[v] * x + sumb[v];
		}
		int tm = (tl + tr) >> 1;
		ll res_l = get(l, r, x, v * 2, tl, tm);
		ll res_r = get(l, r, x, v * 2 + 1, tm + 1, tr);
		ll overlap = min(tr, r) - max(tl, l) + 1;
		return res_l + res_r + tk[v] * overlap * x + tb[v] * overlap;
	}

	ll get(int l, int r, ll x) {
		ll res = get(l, r, x, 1, 0, n - 1);
		// cerr << "get " << l << ' ' << r << ' ' << x << " = " << res << '\n';
		return res;
	}
};

const int MAX_N = 2e5 + 228;
int n, q, p[MAX_N], _p[MAX_N], grL[MAX_N], grR[MAX_N];
vector<array<int, 6>> events;

void calc_gr() {
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && p[i] > p[st.back()]) {
			st.pop_back();
		}
		grL[i] = st.empty() ? -1 : st.back();
		st.push_back(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && p[i] > p[st.back()]) {
			st.pop_back();
		}
		grR[i] = st.empty() ? n : st.back();
		st.push_back(i);
	}
}

void read() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		_p[p[i]] = i;
	}
}

void add_rectangle(int x1, int y1, int x2, int y2) {
	// cerr << "add_rectangle " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	events.push_back({{x1, 0, y1, y2, 1, -x1 + 1}});
	events.push_back({{x2 + 1, 0, y1, y2, -1, x2}});
}

void add_events() {
	vector<vector<pair<int, int>>> mseg(n + 1);
	for (int d1 = 1; d1 * d1 <= n; ++d1) {
		for (int d2 = d1 + 1; d1 * d2 <= n; ++d2) {
			int seg_min = min(min(_p[d1], _p[d2]), _p[d1 * d2]);
			int seg_max = max(max(_p[d1], _p[d2]), _p[d1 * d2]);
			if (seg_min <= grL[_p[d1 * d2]] || seg_max >= grR[_p[d1 * d2]]) {
				continue;
			}
			mseg[d1 * d2].emplace_back(seg_min, seg_max);
		}
	}
	for (int M = 1; M <= n; ++M) {
		// cerr << "M = " << M << '\n';
		sort(all(mseg[M]), [] (const pair<int, int>& a, const pair<int, int>& b) { return tie(b.first, a.second) < tie(a.first, b.second); });
		int rb = n, lb = -1;
		for (auto [l, r] : mseg[M]) {
			// cerr << "lr = " << l << ' ' << r << '\n';
			if (r < rb) {
				if (lb != -1) {
					add_rectangle(l + 1, rb, lb, grR[_p[M]] - 1);
				}
				rb = r;
				lb = l;
			}
		}
		if (lb != -1 && grL[_p[M]] + 1 <= lb) {
			add_rectangle(grL[_p[M]] + 1, rb, lb, grR[_p[M]] - 1);
		}
	}
}

const int MAX_Q = 1e6 + 228;
ll ans[MAX_Q];

void scanline() {
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		events.push_back({l - 1, 1, l, r, i, -1});
		events.push_back({r, 1, l, r, i, 1});
	}
	sort(all(events));
	SegTree T(n);
	for (auto [x, type, y1, y2, k, b] : events) {
		if (type == 0) {
			T.update(y1, y2, k, b);
		} else {
			ans[k] += b * T.get(y1, y2, x);
		}
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}

signed main() {
	fast_io();
	read();
	calc_gr();
	add_events();
	scanline();
}