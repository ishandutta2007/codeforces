/*

Code for problem C by cookiedoth
Generated 17 May 2020 at 01.00 PM



10%

30%

50%

70%

100%

o_O
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
	ld x, y;

	pt(): x(0), y(0) {}
	pt(ld _x, ld _y): x(_x), y(_y) {}
};

pt operator + (pt a, pt b) {
	return pt(a.x + b.x, a.y + b.y);
}

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

ld operator * (pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

ld operator / (pt a, pt b) {
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

const ld pi = acosl(-1);
ld SIDE = 1;
int n;
vector<pt> a;

ld get_len(ld rotation) {
	pt norm(cos(rotation), sin(rotation));
	vector<ld> val(n);
	for (int i = 0; i < n; ++i) {
		val[i] = a[i] * norm;
	}
	return (*max_element(all(val))) - (*min_element(all(val)));
}

const ld INF = 1e9;

ld ans;

ld get_square(ld rotation) {
	ld H = get_len(rotation), W = get_len(rotation + pi / 2);
	ld res = max(H, W);
	chkmin(ans, res);
	return res;
}

void solve() {
	cout << setprecision(10) << fixed;
	cin >> n;
	n *= 2;
	ld delta_angle = 2.0 * pi / (ld)n;
	ld cur_angle = 0;
	pt cur;
	a.clear();
	for (int i = 0; i < n; ++i) {
		a.push_back(cur);
		cur = cur + pt(SIDE * cos(cur_angle), SIDE * sin(cur_angle));
		cur_angle += delta_angle;
	}
	ans = INF;
	ld l = 0, r = pi / 2;
	for (int it = 0; it < 100; ++it) {
		ld m1 = (2 * l + r) / 3;
		ld m2 = (l + 2 * r) / 3;
		if (get_square(m1) < get_square(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	cout << ans << endl;
}

int T;

signed main() {
	fast_io();
	cin >> T;
	while (T--) {
		solve();
	}
}