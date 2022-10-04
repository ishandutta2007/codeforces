/*

Code for problem F1 by cookiedoth
Generated 27 Jun 2020 at 07.53 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

=_=
>_<
o_O

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

	ll norm() {
		return x * x + y * y;
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

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

struct line {
	ll a, b, c;

	line() {}

	line(pt A, pt B) {
		a = A.y - B.y;
		b = B.x - A.x;
		c = -a * A.x - b * A.y;
		if (a < 0) {
			a = -a;
			b = -b;
			c = -c;
		}
		ll g = gcd(abs(a), gcd(abs(b), abs(c)));
		a /= g;
		b /= g;
		c /= g;
	}

	ld getY(ld x) {
		return (-(ld)a * x - c) / (ld)b;
	}
};

bool operator == (line l1, line l2) {
	return (l1.a == l2.a && l1.b == l2.b && l1.c == l2.c);
}

ld scanX;

bool operator < (line l1, line l2) {
	return l1.getY(scanX) < l2.getY(scanX);
}

struct car {
	pt from, dir;
	ll s;
	ld vx;
	line l;

	car(pt _from, pt _dir, ll _s): from(_from), dir(_dir), s(_s) {
		l = line(from, from + dir);
		vx = (ld)dir.x / sqrtl((ld)dir.norm()) * (ld)s;
	}
};

ll det(ll a, ll b, ll c, ll d) {
	return a * d - b * c;
}

bool inter(line l1, line l2, ll &D, ll &Dx, ll &Dy) {
	D = det(l1.a, l1.b, l2.a, l2.b);
	if (D == 0) {
		return 0;
	}
	Dx = -det(l1.c, l1.b, l2.c, l2.b);
	Dy = -det(l1.a, l1.c, l2.a, l2.c);
	if (D < 0) {
		D = -D;
		Dx = -Dx;
		Dy = -Dy;
	}
	return 1;
}

int n;
vector<car> a;

ll sgn(ll x) {
	return (x < 0 ? -1 : (x > 0));
}

ld norm(ld x, ld y) {
	return x * x + y * y;
}

ld sqr(ld x) {
	return x * x;
}

int intersect(int id1, int id2, ld t) {
	// cerr << "intersect " << id1 << " " << id2 << " " << t << endl;
	if (a[id1].l == a[id2].l) {
		return 1;
	}
	ll D, Dx, Dy;
	if (!inter(a[id1].l, a[id2].l, D, Dx, Dy)) {
		return 0;
	}
	if (sgn(Dx - a[id1].from.x * D) * sgn(a[id1].dir.x) == -1) {
		return 0;
	}
	if (sgn(Dx - a[id2].from.x * D) * sgn(a[id2].dir.x) == -1) {
		return 0;
	}
	// cerr << "rays intersect" << endl;
	ld x = (ld)Dx / (ld)D, y = (ld)Dy / (ld)D;
	// cerr << "xy " << x << " " << y << endl;
	ld norm1 = norm(x - (ld)a[id1].from.x, y - (ld)a[id1].from.y);
	ld norm2 = norm(x - (ld)a[id2].from.x, y - (ld)a[id2].from.y);
	if (norm1 <= sqr((ld)a[id1].s * t) && norm2 <= sqr((ld)a[id2].s * t)) {
		// cerr << "intersecting" << endl;
		return 1;
	} else {
		return 0;
	}
}

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		pt from, dir;
		ll s;
		cin >> from >> dir >> s;
		a.emplace_back(from, dir, s);
	}
}

struct event {
	ld x;
	int id, type;
};

bool operator < (event a, event b) {
	return a.x < b.x;
}

set<pair<line, int> > S;

int check(ld t) {
	S.clear();
	vector<event> ev;
	for (int i = 0; i < n; ++i) {
		ld x1 = (ld)a[i].from.x;
		ld x2 = (ld)a[i].from.x + a[i].vx * t;
		if (x1 > x2) {
			swap(x1, x2);
		}
		ev.push_back({x1, i, 0});
		ev.push_back({x2, i, 1});
	}
	sort(all(ev));
	vector<set<pair<line, int> >::iterator> rem(n);
	for (auto e : ev) {
		scanX = e.x;
		if (e.type == 0) {
			auto it = S.lower_bound({a[e.id].l, -1});
			if (it != S.end() && intersect(e.id, it->second, t)) {
				return 1;
			}
			if (it != S.begin()) {
				auto it1 = prev(it);
				if (intersect(e.id, it1->second, t) ||
					(it != S.end() && intersect(it->second, it1->second, t))) {
					return 1;
				}
			}
			rem[e.id] = S.insert({a[e.id].l, e.id}).first;
		} else {
			auto it = rem[e.id];
			if (it != S.begin() && next(it) != S.end() && intersect(it->second, next(it)->second, t)) {
				return 1;
			}
			S.erase(it);
		}
	}
	return 0;
}

void binsearch() {
	ld l = 0, r = 1e12;
	int ok = 0;
	for (int it = 0; it < 80; ++it) {
		ld mid = (l + r) / 2;
		if (check(mid)) {
			// cerr << "kek " << mid << endl;
			ok = 1;
			r = mid;
		} else {
			// cerr << "no " << mid << endl;
			l = mid;
		}
	}
	if (!ok) {
		cout << "No show :(" << endl;
		exit(0);
	}
	cout << setprecision(10) << fixed << l << endl;
}

signed main() {
	fast_io();
	cerr << setprecision(4) << fixed;
	read();
	binsearch();
	// int res = check(0.5);
	// cerr << res << endl;
}