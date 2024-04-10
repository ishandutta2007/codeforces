/*

Code for problem D by cookiedoth
Generated 11 Apr 2021 at 05.53 PM



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
#include <chrono>
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

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

struct st {
	vector<int> a, t;
	int n;

	st() {}

	void build(int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			int tm = (tl + tr) >> 1;
			build(v * 2, tl, tm);
			build(v * 2 + 1, tm + 1, tr);
			t[v] = gcd(t[v * 2], t[v * 2 + 1]);
		}
	}

	st(int *_a, int _n) {
		// cerr << "build\n";
		n = _n;
		t.resize(4 * n);
		a = vector<int> (_a, _a + n);
		build(1, 0, n - 1);
	}

	int descent(int pos, int val, int v, int tl, int tr) {
		if (tl == tr) {
			if (t[v] % val == 0) {
				return tl + 1;
			} else {
				return tl;
			}
		}
		int tm = (tl + tr) >> 1;
		if (pos > tm || t[v * 2] % val == 0) {
			return descent(pos, val, v * 2 + 1, tm + 1, tr);
		}
		int res = descent(pos, val, v * 2, tl, tm);
		if (res == tm + 1) {
			return descent(pos, val, v * 2 + 1, tm + 1, tr);
		} else {
			return res;
		}
	}

	int get(int pos) {
		int res = descent(pos, a[pos], 1, 0, n - 1);
		return res - pos - 1;
	}
};

const int mx = 2e5 + 228;
int n, a[mx], p;
set<int> rem;
st T1, T2;

int join(int l, int r) {
	int res = 0;
	while (true) {
		auto it = rem.lower_bound(l);
		if (it == rem.end()) {
			break;
		}
		if (*it < r) {
			res++;
			rem.erase(it);
		} else {
			break;
		}
	}
	return res;
}

void solve() {
	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	T1 = st(a, n);
	// output(a, a + n);
	// for (int i = 0; i < n; ++i) {
	// 	cerr << "get " << i << ' ' << T1.get(i) << '\n';
	// }
	reverse(a, a + n);
	T2 = st(a, n);
	// output(a, a + n);
	// for (int i = 0; i < n; ++i) {
	// 	cerr << "get " << i << ' ' << T2.get(i) << '\n';
	// }
	reverse(a, a + n);
	rem.clear();
	for (int i = 0; i < n - 1; ++i) {
		rem.insert(i);
	}
	vector<pair<int, int>> vp;
	for (int i = 0; i < n; ++i) {
		vp.emplace_back(a[i], i);
	}
	sort(all(vp));
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		// cerr << "i = " << i << '\n';
		if (vp[i].first < p) {
			int pos = vp[i].second;
			int c1 = T1.get(pos);
			int c2 = T2.get(n - 1 - pos);
			// cerr << "c1, c2 = " << c1 << ' ' << c2 << '\n';
			ll v1 = join(pos, pos + c1);
			ll v2 = join(pos - c2, pos);
			ans += v1 * (ll)vp[i].first;
			ans += v2 * (ll)vp[i].first;
		}
		// cerr << "done\n";
	}
	ans += p * (ll)rem.size();
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}