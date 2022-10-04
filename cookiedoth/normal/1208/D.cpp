/*

Code for problem D by cookiedoth
Generated 25 Aug 2019 at 05.57 P


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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
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

	fenwick(int _n) {
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
};

const int mx = 2e5 + 228;
int n;
ll a[mx], p[mx], sum;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	fenwick f(n);
	for (int i = 0; i < n; ++i) {
		f.update(i, i);
	}

	for (int i = n - 1; i >= 0; --i) {
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (f.get(mid) <= a[i]) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		p[i] = l;
		f.update(l, -l);
	}

	for (int i = 0; i < n; ++i) {
		cout << p[i] << " ";
	}
	cout << endl;
}