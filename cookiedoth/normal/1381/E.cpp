/*

Code for problem E by cookiedoth
Generated 21 Jul 2020 at 06.42 PM


  !
 
                                    
                          
                  




















o_O
-_-
~_^

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

bool ycmp(pt a, pt b) {
	return make_pair(a.y, b.x) < make_pair(b.y, b.x);
}

int n;
vector<pt> a;

void rearrange() {
	int pos = min_element(all(a), ycmp) - a.begin();
	rotate(a.begin(), a.begin() + pos, a.end());
}

void make_good() {
	rearrange();
	if (!polar_cmp(a.back() - a[0], a[1] - a[0])) {
		reverse(all(a));
		rearrange();
	}
}

int q, max_pos;

void read() {
	cin >> n >> q;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	make_good();
	// cerr << "a" << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << a[i] << endl;
	// }
	max_pos = max_element(all(a), ycmp) - a.begin();
	// cerr << "max_pos = " << max_pos << endl;
}

vector<pair<int, int> > events;

void build_events() {
	for (int i = 1; i <= max_pos; ++i) {
		events.emplace_back(a[i].y, 0);
	}
	for (int i = n - 1; i >= max_pos; --i) {
		events.emplace_back(a[i].y, 1);
	}
	sort(all(events));
}

const ld EPS = 1e-10;

struct event {
	ld x, a, b, c;
	int type, id;
};

bool operator < (const event &a, const event &b) {
	return (a.x < b.x);
}

vector<event> E;

void increase(ld l, ld r, ld a, ld b, ld c) {
	E.push_back({l, a, b, c, 0, 0});
	E.push_back({r, -a, -b, -c, 0, 0});
}

void S_triangle(ld x1, ld x2, ld H1, ld H2, ld x, ld &a, ld &b, ld &c) {
	// cerr << "S_triangle " << x1 << " " << x2 << " " << H1 << " " << H2 << " " << x << endl;
	if (fabsl(x2 - x1) < EPS) {
		return;
	}
	if (x < x1) {
		return;
	}
	if (x > x2) {
		c += (x2 - x1) * (H1 + H2) / 2.0;
		return;
	}
	ld incl = (H2 - H1) / (x2 - x1);
	// cerr << "incl = " << incl << endl;
	// cerr << "d = " << d << endl;
	b += H1;
	c -= x1 * H1;
	a += incl / 2.0;
	b -= incl * x1;
	c += incl / 2.0 * x1 * x1;
}

void S_trapezoid(ld H, ld L1, ld R1, ld L2, ld R2, ld x, ld &a, ld &b, ld &c) {
	if (L1 > L2) {
		swap(L1, L2);
	}
	if (R1 > R2) {
		swap(R1, R2);
	}
	ld rect;
	if (x >= L1) {
		if (x <= R2) {
			b += H;
			c -= L1 * H;
		} else {
			c += (R2 - L1) * H;
		}
	}
	ld a1 = 0, b1 = 0, c1 = 0;
	S_triangle(L1, L2, H, 0, x, a1, b1, c1);
	S_triangle(R1, R2, 0, H, x, a1, b1, c1);
	a -= a1;
	b -= b1;
	c -= c1;
}

void fold_trapezoid(ld H, ld L1, ld R1, ld L2, ld R2, ld x, ld &a, ld &b, ld &c) {
	ld S = (R1 + R2 - L1 - L2) * H / 2.0;
	c += S;
	ld a1 = 0, b1 = 0, c1 = 0;
	S_trapezoid(H, L1, (L1 + R1) / 2.0, L2, (L2 + R2) / 2.0, x, a1, b1, c1);
	S_trapezoid(H, (L1 + R1) / 2.0, R1, (L2 + R2) / 2.0, R2, x, a, b, c);
	a -= a1;
	b -= b1;
	c -= c1;
}

const ld INF = 1e9;

void handle_trapezoid(ld y_min, ld y_max, ld L1, ld R1, ld L2, ld R2) {
	ld H = y_max - y_min;
	vector<ld> x = {-INF, L1, R1, L2, R2, (L1 + R1) / 2.0, (L2 + R2) / 2.0, INF};
	sort(all(x));
	for (int i = 0; i < (int)x.size() - 1; ++i) {
		ld target_x = (x[i] + x[i + 1]) / 2.0;
		ld a = 0, b = 0, c = 0;
		fold_trapezoid(H, L1, R1, L2, R2, target_x, a, b, c);
		increase(x[i], x[i + 1], a, b, c);
	}

}

ld getX(pair<pt, pt> seg, ld y) {
	// cerr << "getX " << y << endl;
	// cerr << seg.first << " " << seg.second << endl;
	return (ld)seg.first.x + (ld)(seg.second.x - seg.first.x) * (y - (ld)seg.first.y) / (ld)(seg.second.y - seg.first.y);
}

void scanline() {
	int ptr_l = 0, ptr_r = 0;
	ld y = a[0].y;
	for (int i = 0; i < (int)events.size(); ++i) {
		ld y1 = events[i].first;
		pair<pt, pt> seg1 = {a[ptr_l], a[(ptr_l + 1) % n]};
		pair<pt, pt> seg2 = {a[ptr_r], a[(ptr_r - 1 + n) % n]};
		handle_trapezoid(y, y1, getX(seg1, y), getX(seg2, y), getX(seg1, y1), getX(seg2, y1));
		y = y1;
		if (events[i].second == 0) {
			ptr_l = (ptr_l + 1) % n;
		} else {
			ptr_r = (ptr_r - 1 + n) % n;
		}
	}
}

void read_queries() {
	for (int i = 0; i < q; ++i) {
		ld x;
		cin >> x;
		E.push_back({x + EPS, 0, 0, 0, 1, i});
	}
}

const int mx = 1e5 + 228;
ld ans[mx];

void final_scanline() {
	ld a = 0, b = 0, c = 0;
	sort(all(E));
	for (auto e : E) {
		if (e.type == 0) {
			a += e.a;
			b += e.b;
			c += e.c;
		} else {
			ld x = e.x;
			ans[e.id] = a * x * x + b * x + c;
		}
	}
}

void print_ans() {
	cout << setprecision(10) << fixed;
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}

signed main() {
	cerr << setprecision(4) << fixed;
	fast_io();
	read();
	build_events();
	scanline();
	read_queries();
	final_scanline();
	print_ans();
}