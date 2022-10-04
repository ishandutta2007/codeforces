#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <numeric>
#include <random>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(const T &x, ostream &out = cerr) {
	output(all(x), out);
}

template<class T> int chkmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmax(T &a, const T &b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 1e6 + 228;
const ll INF = 1e18;

struct st {
	vector<ll> t, mod;
	int n;

	st() {}

	void build(ll *a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			int tm = (tl + tr) >> 1;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]);
		}
	}

	void build(ll *a, int _n) {
		n = _n;
		t.resize(4 * n);
		mod.resize(4 * n);
		build(a, 1, 0, n - 1);
	}

	void add(int l, int r, ll val, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			mod[v] += val;
			t[v] += val;
		} else {
			int tm = (tl + tr) >> 1;
			add(l, r, val, v * 2, tl, tm);
			add(l, r, val, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]) + mod[v];
		}
	}

	void add(int l, int r, ll val) {
		add(l, r, val, 1, 0, n - 1);
	}

	int cnt = 0;

	ll get() {
		return t[1];
	}
};

st t;
int n, m, p;
ll w_price[mx], a_price[mx];
vector<pair<int, ll> > monsters[mx];

signed main() {
	fast_io();
	cin >> n >> m >> p;
	fill(w_price, w_price + mx, -INF);
	fill(a_price, a_price + mx, -INF);
	for (int i = 0; i < n; ++i) {
		ll a, ca;
		cin >> a >> ca;
		chkmax(w_price[a - 1], -ca);
	}
	for (int i = 0; i < m; ++i) {
		ll b, cb;
		cin >> b >> cb;
		chkmax(a_price[b - 1], -cb);
	}
	t.build(a_price, mx);
	for (int i = 0; i < p; ++i) {
		ll x, y, z;
		cin >> x >> y >> z;
		monsters[x].emplace_back(y, z);
	}
	ll ans = -INF;
	for (int i = 0; i < mx; ++i) {
		for (auto pp : monsters[i]) {
			t.add(pp.first, mx - 1, pp.second);
		}
		ll res = t.get();
		chkmax(ans, res + w_price[i]);
	}
	cout << ans << endl;
}