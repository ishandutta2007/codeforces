/*

Code for problem F1 by savkinsd2089
Generated 04 Oct 2018 at 07.12 pm
The Moon is Waning Crescent (25% of Full)



10%

30%

50%

70%

100%

~_^
-_-
>_<

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

const ll MOD = 1e9 + 7;

struct data {
	ll val, cnt, sum;
	data(): val(0), cnt(0), sum(0) {}
	data(ll _x): val(0), cnt(1), sum(_x) {}
	data(ll _val, ll _cnt, ll _sum): val(_val), cnt(_cnt), sum(_sum) {}
};

data merge(data a, data b) {
	return data((a.val + b.val + b.sum * a.cnt) % MOD, a.cnt + b.cnt, (a.sum + b.sum) % MOD);
}

struct st {
	vector<data> t;
	int n;

	void init(int _n) {
		n = _n;
		t.resize(4 * n);
	}

	void update(int pos, ll val, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = data(val);
		}
		else {
			int tm = (tl + tr) >> 1;
			if (pos <= tm)
				update(pos, val, v * 2, tl, tm);
			else
				update(pos, val, v * 2 + 1, tm + 1, tr);
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
		}
	}

	void output(int v, int tl, int tr) {
		cerr << tl << ".." << tr << ": " << t[v].val << " " << t[v].cnt << " " << t[v].sum << endl;
		if (tl < tr) {
			int tm = (tl + tr) >> 1;
			output(v * 2, tl, tm);
			output(v * 2 + 1, tm + 1, tr);
		}
	}

	data get(int l, int r, int v, int tl, int tr) {
		if (l > r)
			return data();
		if (l == tl && r == tr)
			return t[v];
		int tm = (tl + tr) >> 1;
		data res_l = get(l, min(r, tm), v * 2, tl, tm);
		data res_r = get(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
		return merge(res_l, res_r);
	}

	void update(int pos, ll val) {
		update(pos, val, 1, 0, n - 1);
	}

	ll get(int l, int r) {
		data x = get(l, r, 1, 0, n - 1);
		return x.val;
	}
};

struct fenwick_mod {
	vector<ll> t;
	int n;

	void init(int _n) {
		n = _n;
		t.resize(n);
	}

	void update(int pos, ll val) {
		while (pos < n) {
			t[pos] = (t[pos] + val) % MOD;
			pos = (pos | (pos + 1));
		}
	}

	ll get(int r) {
		ll res = 0;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res % MOD;
	}

	ll get(int l, int r) {
		return (get(r) - get(l - 1) + MOD) % MOD;
	}
};

struct fenwick {
	vector<ll> t;
	int n;

	void init(int _n) {
		n = _n;
		t.resize(n);
	}

	void update(int pos, ll val) {
		while (pos < n) {
			t[pos] = (t[pos] + val);
			pos = (pos | (pos + 1));
		}
	}

	ll get(int r) {
		ll res = 0;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	ll get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

const int mx = 2e5 + 228;
int n, q;
ll a[mx], w[mx];
fenwick_mod f_aw;
fenwick f_w;
st t, t_rev;

void update_index(int pos, ll new_w, ll old_w) {
	//cerr << ">>>> updating index " << pos << " " << new_w << " " << old_w << endl;
	ll diff = (new_w - old_w + MOD) % MOD;
	f_w.update(pos, new_w - old_w);
	f_aw.update(pos, (a[pos] * diff) % MOD);
	t.update(pos, new_w);
	t_rev.update(n - pos - 1, new_w);
}

void init() {
	f_w.init(n);
	f_aw.init(n);
	t.init(n);
	t_rev.init(n);
	for (int i = 0; i < n; ++i) {
		update_index(i, w[i], 0);
	}
}

void update_query(int pos, ll new_w) {
	update_index(pos, new_w, w[pos]);
	w[pos] = new_w;
}

int get_max_left_pos(int l0, int r0, ll L) {
	int l = l0 - 1, r = r0;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (a[mid + 1] < L + (ll)(mid + 1 - l0)) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l;
}

int get_min_right_pos(int l0, int r0, ll L) {
	int l = l0, r = r0 + 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (a[mid] > L + (ll)(mid - l0))
			r = mid;
		else
			l = mid + 1;
	}
	//cerr << "min_right_pos " << l0 << " " << r0 << " " << L << " is " << l << endl;
	return l;
}

ll to_mod(ll x) {
	return (x % MOD + MOD) % MOD;
}

ll get_l(int l0, int r0, ll R) {
	ll res = to_mod(R * (f_w.get(l0, r0) % MOD) - f_aw.get(l0, r0) - t_rev.get(n - 1 - r0, n - 1 - l0));
	//cerr << "get_l " << l0 << " " << r0 << " " << R << " = " << res << endl;
	return res;
}

ll get_r(int l0, int r0, ll L) {
	ll res = to_mod(f_aw.get(l0, r0) - (f_w.get(l0, r0) % MOD) * L - t.get(l0, r0));
	//cerr << "get_r " << l0 << " " << r0 << " " << L << " = " << res << endl;
	//cerr << f_aw.get(l0, r0) << endl;
	//cerr << -f_w.get(l0, r0) * L << endl;
	//cerr << -t.get(l0, r0) << endl;
	return res;
}

ll get(int l0, int r0, ll L) {
	int mid_pos = get_max_left_pos(l0, r0, L);
	ll res = to_mod(get_l(l0, mid_pos, L + mid_pos - l0) + get_r(mid_pos + 1, r0, L + mid_pos + 1 - l0));
	return res;
}

ll get_query(int l0, int r0) {
	/*cerr << "--------------------------" << endl;
	cerr << "get_query " << l0 << " " << r0 << endl;
	cerr << "aw" << endl;
	output(a, a + n);
	output(w, w + n);*/
	ll len = (ll)(r0 - l0 + 1), L = a[l0], R = a[r0] - len + 1;
	/*cerr << "array" << endl;
	for (ll i = a[l0]; i <= a[r0] - len + 1; ++i) {
		cerr << get(l0, r0, i) << " ";
	}
	cerr << endl;*/
	while (R > L) {
		//cerr << "segment " << L << ".." << R << endl;
		ll MID = (L + R) >> 1;
		//cerr << "MID = " << MID << endl;
		int max_left_pos = get_max_left_pos(l0, r0, MID), min_right_pos = get_min_right_pos(l0, r0, MID);
		//cerr << "pos " << max_left_pos << " " << min_right_pos << endl;
		ll wl = f_w.get(l0, max_left_pos), wr = f_w.get(min_right_pos, r0), wm = f_w.get(max_left_pos + 1, min_right_pos - 1), diff_to_next = wl - wr + wm;
		//cerr << "wl = " << wl << ", wr = " << wr << endl;
		//cerr << "trying " << MID << ", " << diff_to_next << endl;
		//cerr << "wl, wr = " << wl << " " << wr << endl;
		if (diff_to_next >= 0)
			R = MID;
		else
			L = MID + 1;
	}
	//cerr << "L = " << L << endl;
	//cerr << "R = " << R << endl;
	ll ans = get(l0, r0, L);
	return ans % MOD;
}
/*
void check_st() {
	st t;
	t.init(5);
	for (int i = 0; i < 4; ++i) {
		t.update(i, 1);
	}
	t.update(4, 2);
	t.output(1, 0, 4);
	t.update(2, 5);
	cerr << "out2" << endl;
	t.output(1, 0, 4);
	t.update(0, 10);
	cout << t.get(0, 3) << endl;
}
*/
signed main() {
	//check_st();
	fast_io();
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	init();
	for (int i = 0; i < q; ++i) {
		int id;
		ll val;
		cin >> id >> val;
		if (id < 0) {
			update_query(-id - 1, val);
		}
		else {
			cout << get_query(id - 1, (int)val - 1) << endl;
		}
	}
}