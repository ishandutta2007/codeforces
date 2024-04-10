/*

Code for problem E by cookiedoth
Generated 23 Feb 2020 at 12.16 P










(@)(@)(@)(@)(@)

z_z
>_<
\_()_/

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

struct fenwick {
	vector<ll> t;
	int n;

	fenwick() {}

	void init(int _n) {
		n = _n;
		t.resize(n);
	}

	void update(int pos, ll val) {
		while (pos < n) {
			t[pos] += val;
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

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int n, m;
string a, b, s;
vector<int> pref, suf;

void calc_ps() {
	vector<int> z = z_function(s + "#" + a);
	pref = vector<int> (z.begin() + m + 1, z.end());
	string rev_b = b, rev_s = s;
	reverse(all(rev_b));
	reverse(all(rev_s));
	z = z_function(rev_s + "#" + rev_b);
	suf = vector<int> (z.begin() + m + 1, z.end());
	reverse(all(suf));

	// cerr << "pref" << endl;
	// output(all(pref));
	// cerr << "suf" << endl;
	// output(all(suf));
}

fenwick f, f_sum;

ll ans;

void add_to_f(ll val, ll c) {
	// cerr << "add_to_f " << val << " " << c << endl;
	f.update(val, c);
	f_sum.update(val, c * val);
}

void process() {
	for (int i = n - 1; i >= 0; --i) {
		add_to_f(min(suf[i], m - 1), 1);
		if (i + m - 1 < n) {
			add_to_f(min(suf[i + m - 1], m - 1), -1);
		}
		if (pref[i]) {
			ll cur = min(pref[i], m - 1);
			// cerr << "get " << cur << endl;
			int bound = m - cur;
			ll sum = f_sum.get(bound, m - 1);
			ll cnt = f.get(bound, m - 1);
			ans += cur * cnt + sum - (ll)(m - 1) * cnt;
			// cerr << "ans = " << ans << endl;
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> m;
	cin >> a >> b >> s;
	calc_ps();
	f.init(m);
	f_sum.init(m);
	process();
	cout << ans << endl;
}