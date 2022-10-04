/*

Code for problem D by savkinsd2089
Generated 25 Oct 2018 at 06.23 pm
The Moon is Waning Gibbous (99% of Full)


 ] 
 
Il] 


>_<
^_^
-_-

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
#include <numeric>
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
/*
ostream& operator << (ostream &os, __int128 a) {
	long long x = (long long)a;
	os << x;
	return os;
}

istream& operator >> (istream &is, __int128 &a) {
	long long x;
	is >> x;
	a = (__int128)x;
	return is;
}
*/
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

int n;

ll get(int l, int cnt, fenwick &f) {
	int r = l + cnt - 1;
	if (r >= n) {
		return f.get(l, n - 1) + f.get(r - n);
	}
	else {
		return f.get(l, r);
	}
}

const int mx = 2e5 + 228;
ll c[mx], t, ans;
fenwick f, f2;

signed main() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	
	f.init(n);
	f2.init(n);
	for (int i = 0; i < n; ++i) {
		f.update(i, c[i]);
		f2.update(i, 1);
	}

	ll sum = f.get(0, n - 1);
	ll sum2 = n;
	int pos = 0;
	while (sum > 0) {
		//cerr << "iteration" << endl;
		//cerr << "sum = " << sum << endl;
		//cerr << "sum2 = " << sum2 << endl;
		ll full = t / sum;
		ans += sum2 * full;
		t -= full * sum;
		ll l = 0, r = n;
		while (l < r) {
			ll mid = (l + r) >> 1;
			if (get(pos, mid + 1, f) <= t)
				l = mid + 1;
			else
				r = mid;
		}
		t -= get(pos, l, f);
		ans += get(pos, l, f2);
		pos = (pos + l) % n;
		f.update(pos, -c[pos]);
		f2.update(pos, -1);
		sum -= c[pos];
		sum2 -= 1;
	}

	cout << ans << endl;
}