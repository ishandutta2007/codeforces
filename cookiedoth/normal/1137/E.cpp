/*

Code for problem E by cookiedoth
Generated 09 Mar 2019 at 02.28 P


 ] 
 
Il] 


>_<
o_O
-_-

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

struct line {
	ll k, b, id;
};

const ll INF = 1e18;
const ld EPS = 1e-9;

ll intersect(line l1, line l2) {
	ld x = -(ld)(l1.b - l2.b) / (ld)(l1.k - l2.k);
	ll x1 = (ll)(x + EPS);
	if (l1.k * x1 + l1.b == l2.k * x1 + l2.b && l1.id > l2.id) {
		x1--;
	}
	return x1;
}

struct cht {
	vector<pair<ll, line> > st;

	void add_line(line l) {
		//cerr << "add_line " << l.k << " " << l.b << " " << l.id << endl;
		while (!st.empty()) {
			ll x = intersect(l, st.back().second);
			if (x > st.back().first) {
				st.pop_back();
				//cerr << "pop" << endl;
			}
			else {
				break;
			}
		}
		ll x = INF;
		if (!st.empty()) {
			x = intersect(l, st.back().second);
		}
		//cerr << "start from " << x << endl;
		st.push_back({x, l});
	}

	pair<int, ll> get(ll x) {
		//cerr << "get " << x << endl;
		int l = 0, r = (int)st.size() - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (st[mid + 1].first >= x) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		return {st[l].second.id, st[l].second.k * x + st[l].second.b};
	}

	void clear() {
		//cerr << "clear" << endl;
		st.clear();
	}
};

ll n, l, r, sum_s, sum_b;
int m;
vector<ll> v;
cht T;

signed main() {
	fast_io();
	cin >> n >> m;
	v.push_back(0);
	T.add_line({0, 0, 0});
	r = n - 1;
	for (int i = 0; i < m; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			ll len;
			cin >> len;
			l -= len;
			v = {l};
			T.clear();
			sum_s = 0;
			sum_b = 0;
			T.add_line({0, 0, l});
		}
		if (type == 2) {
			ll len;
			cin >> len;
			ll pos = r + 1;
			T.add_line({pos - l, -sum_b - sum_s * (pos - l), pos});
			r += len;
		}
		if (type == 3) {
			ll b, s;
			cin >> b >> s;
			sum_b += b;
			sum_s += s;
		}
		auto pp = T.get(sum_s);
		cout << (pp.first - l) + 1 << " " << pp.second + sum_b << endl;
	}
}