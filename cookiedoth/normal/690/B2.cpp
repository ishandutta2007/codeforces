/*

Code for problem B2 by cookiedoth
Generated 21 Mar 2021 at 10.49 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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

struct pt {
	ll x, y;

	pt(): x(0), y(0) {}
	pt(ll _x, ll _y): x(_x), y(_y) {}
};

pt operator + (pt a, pt b) {
	return pt(a.x + b.x, a.y + b.y);
}

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

ll operator * (pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

ll operator / (pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

istream& operator >> (istream &is, pt &p) {
	is >> p.x >> p.y;
	return is;
}

ostream& operator << (ostream &os, const pt &p) {
	os << p.x << " " << p.y;
	return os;
}

bool operator < (pt a, pt b) {
	return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

bool operator == (pt a, pt b) {
	return !(a < b) && !(b < a);
}

int half_plane(pt a) {
	return (a.y > 0 || (a.y == 0 && a.x > 0)) ^ 1;
}

bool polar_cmp(pt a, pt b) {
	int ha = half_plane(a), hb = half_plane(b);
	if (ha < hb) {
		return 1;
	}
	if (ha > hb) {
		return 0;
	}
	return (a / b > 0);
}

pt base;

ll len(pt a) {
	return a * a;
}

bool base_polar_cmp(pt a, pt b) {
	ll cross = (a - base) / (b - base);
	return (cross > 0 || (cross == 0 && len(a - base) < len(b - base)));
}

vector<pt> convex_hull(vector<pt> &a) {
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	base = a[0];
	sort(a.begin() + 1, a.end(), base_polar_cmp);
	vector<pt> st;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		while (st.size() >= 2) {
			pt last = st.back() - st[st.size() - 2];
			pt next_vect = a[i] - st.back();
			if (last / next_vect <= 0) {
				st.pop_back();
			}
			else {
				break;
			}
		}
		st.push_back(a[i]);
	}
	return st;
}

const int mx = 510;
int n, in[mx][mx];
vector<string> field;

void solve() {
	cin >> n;
	if (n == 0) {
		exit(0);
	}
	field.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> field[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			in[i + 1][j + 1] = (field[i][j] - '0') - in[i][j] - in[i + 1][j] - in[i][j + 1];
		}
	}
	vector<pt> poly;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (in[i][j]) {
				poly.emplace_back(j, n - i);
			}
		}
	}
	poly = convex_hull(poly);
	reverse(all(poly));
	int opt = 0;
	for (int i = 1; i < (int)poly.size(); ++i) {
		if (tie(poly[i].x, poly[i].y) < tie(poly[opt].x, poly[opt].y)) {
			opt = i;
		}
	}
	rotate(poly.begin(), poly.begin() + opt, poly.end());
	cout << poly.size() << '\n';
	for (auto [x, y] : poly) {
		cout << x << ' ' << y << '\n';
	}
}

signed main() {
	fast_io();
	while (true) {
		solve();
	}
}