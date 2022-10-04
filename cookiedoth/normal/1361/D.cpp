/*

Code for problem D by cookiedoth
Generated 04 Jun 2020 at 06.45 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

^_^
-_-
z_z

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

struct pt {
	ll x, y;

	pt(): x(0), y(0) {}
	pt(ll _x, ll _y): x(_x), y(_y) {}

	ld len() {
		return sqrtl((ld)(x * x + y * y));
	}
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

int n, k;
vector<vector<ld> > a;
vector<pt> points;

void read() {
	cin >> n >> k;
	points.resize(n);
	int zero_coord = -1;
	for (int i = 0; i < n; ++i) {
		cin >> points[i];
		if (points[i].x == 0 && points[i].y == 0) {
			zero_coord = i;
		}
	}
	points.erase(points.begin() + zero_coord);
	sort(all(points), polar_cmp);
	for (int i = 0; i < n - 1; ++i) {
		if (i == 0 || polar_cmp(points[i - 1], points[i])) {
			a.push_back(vector<ld> ());
		}
		a.back().push_back(points[i].len());
	}
	a[0].push_back(0);
	for (auto &v : a) {
		sort(all(v));
	}
	// cerr << "a" << endl;
	// for (auto v : a) {
	// 	output(all(v));
	// }
}

void solve() {
	// cerr << "k = " << k << endl;
	vector<ld> additions;
	cerr << setprecision(4) << fixed;
	for (auto v : a) {
		// cerr << "v" << endl;
		// output(all(v));
		int len = v.size();
		int e = k - 1;
		ld sum = 0;
		int ptr = 0;
		for (int it = 0; it < len; ++it) {
			if (e > 0) {
				additions.push_back((ld)e * v.back());
				// cerr << "pb " << (ld)e * v.back() << endl;
				v.pop_back();
				e -= 2;
			} else {
				additions.push_back((ld)e * v[ptr] - 2 * sum);
				// cerr << "pb " << ptr << " " << (ld)e * v[ptr] - 2 * sum << endl;
				sum += v[ptr];
				ptr++;
			}
		}
	}
	sort(rall(additions));
	ld ans = 0;
	for (int i = 0; i < k; ++i) {
		// cerr << "add " << additions[i] << endl;
		ans += additions[i];
	}
	cout << setprecision(10) << fixed << ans << endl;
}

signed main() {
	fast_io();
	read();
	solve();
}