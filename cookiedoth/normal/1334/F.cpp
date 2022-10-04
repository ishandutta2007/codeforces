/*

Code for problem F by cookiedoth
Generated 10 Apr 2020 at 06.44 PM


 ] 
 
Il] 


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

const ll INF = 1e18;

struct st {
	int n;
	vector<ll> t;

	st(int _n) {
		n = 1;
		while (n < _n) {
			n <<= 1;
		}
		t.resize(2 * n);
		t[1] = INF;
	}

	void update(int l, int r, ll val) {
		l += n;
		r += n;
		while (l <= r) {
			if (l & 1) {
				t[l] += val;
				l++;
			}
			if ((r & 1) == 0) {
				t[r] += val;
				r--;
			}
			l >>= 1;
			r >>= 1;
		}
	}

	ll get(int pos) {
		pos += n;
		ll res = 0;
		while (pos) {
			res += t[pos];
			pos >>= 1;
		}
		return res;
	}

	void chkmin_pos(int pos, ll val) {
		ll cur_val = get(pos);
		if (val < cur_val) {
			update(pos, pos, val - cur_val);
		}
	}
};

const int mx = 5e5 + 228;
int n, m, a[mx], b[mx], id[mx];
ll p[mx];

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i + 1];
	}
	for (int i = 0; i < n; ++i) {
		cin >> p[i + 1];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i + 1];
	}
	a[n + 1] = n + 1;
	b[m + 1] = n + 1;
	n += 2;
	m += 2;

	// cerr << "a, b, p" << endl;
	// output(a, a + n);
	// output(b, b + m);
	// output(p, p + n);
}

void solve() {
	st T(m);
	fill(id, id + n, -1);
	for (int i = 0; i < m; ++i) {
		id[b[i]] = i;
	}
	T.chkmin_pos(0, 0);
	for (int i = 1; i < n; ++i) {
		// cerr << "i = " << i << endl;
		ll dp_val;
		if (id[a[i]] != -1) {
			dp_val = T.get(id[a[i]] - 1);
		}
		if (p[i] >= 0) {
			int pos = lower_bound(b, b + m, a[i]) - b - 1;
			if (pos >= 0) {
				// cerr << "update " << 0 << " " << pos << " " << p[i] << endl;
				T.update(0, pos, p[i]);
			}
		} else {
			T.update(0, m - 1, p[i]);
		}
		if (id[a[i]] != -1) {
			// cerr << "chkmin_pos " << id[a[i]] << " " << dp_val << endl;
			T.chkmin_pos(id[a[i]], dp_val);
		}
	}
	ll ans = T.get(m - 1);
	if (ans >= INF / 2) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		cout << ans << endl;
	}
}

signed main() {
	fast_io();
	read();
	solve();
}