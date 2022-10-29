#pragma comment (linker, "/STACK:200000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;


typedef long long int64;
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 1100;


struct pt {
	double x, y;

	pt() {}
	pt (double x, double y) : x(x), y(y)  { }

	pt operator- (const pt & p) const {
		return pt (x-p.x, y-p.y);
	}
};

struct line {
	double a, b, c;

	void norm() {
		double z = sqrt(a*a+b*b);
		a /= z,  b /= z,  c /= z;
		if (c > EPS) {
			a = -a;
			b = -b;
			c = -c;
		}
	}
};


int n, k;
pt p[MAXN];
double r[MAXN];


bool read() {
	if (! (cin >> n >> k))
		return false;
	forn(i,n) {
		int x, y, rr;
		scanf ("%d%d%d", &x, &y, &rr);
		p[i].x = x;
		p[i].y = y;
		r[i] = rr;
	}
	return true;
}


inline double sqr (double a) {
	return a*a;
}

inline double norm (double a) {
	while (a < -PI)
		a += 2*PI;
	while (a > PI)
		a -= 2*PI;
	return a;
}

inline void tangents (pt c, double r1, double r2, vector<line> & ans) {
	double r = r2 - r1;
	double z = sqr(c.x) + sqr(c.y);
	double d = z - sqr(r);
	if (d < -EPS)  return;
	d = sqrt (abs (d));
	line l;
	l.a = (c.x * r + c.y * d) / z;
	l.b = (c.y * r - c.x * d) / z;
	l.c = r1;
	l.norm();
	ans.pb (l);
}

vector<line> tangents (pt a, double ar, pt b, double br) {
	vector<line> ans;
	for (int i=-1; i<=1; i+=2)
		for (int j=-1; j<=1; j+=2)
			tangents (b-a, ar*i, br*j, ans);
	return ans;
}


struct event {
	double ang;
	int bal;

	event() { }
	event (double ang, int bal)
		: ang(ang), bal(bal)
	{ }

	bool operator< (const event & e) const {
		if (abs (ang - e.ang) > EPS)
			return ang < e.ang;
		return bal < e.bal;
	}
};

vector<event> e;


inline void add_events (int i, line l1, line l2) {
	double ang1 = atan2 (l1.b, l1.a),
		ang2 = atan2 (l2.b, l2.a);
	if (ang2 < ang1)
		if (ang1 - ang2 > PI)
			ang2 += 2 * PI;
		else
			swap (ang1, ang2);
	if (ang2 <= ang1 + EPS)
		throw;
	//cerr << "add: (" << norm(ang1)*180/PI << "," << norm(ang2)*180/PI << ")" << endl;

	for (int i=-1; i<=1; ++i) {
		double l = ang1 + 2*PI * i,
			r = ang2 + 2*PI * i;
		e.pb (event (l, +1));
		e.pb (event (r, -1));
	}
}

int solve_events() {
	sort (all (e));

	int ans = 0,
		bal = 0;
	forn(i,e.size()) {
		double ang = e[i].ang;
		//cerr << "ang = " << norm(ang)*180/PI << endl;
		while (i<(int)e.size() && abs (ang - e[i].ang) < EPS) {
			//cerr << "bal += " << e[i].bal << endl;
			bal += e[i++].bal;
			if (bal < 0 || bal >= n)
				throw;
		}
		--i;
		ans = max (ans, bal);
	}
	return ans + 1;
}


int64 formula (int64 k, int64 cnt) {
	if (!cnt)  return 0;
	return (1 + k * (k+1) / 2) + (cnt-1) * (k+1) + (n - cnt);
}

void solve() {
	int64 ans = 0;

	forn(i,n) {
		e.clear();
		forn(j,n)
			if (i != j) {
				vector<line> l = tangents (p[i], r[i], p[j], r[j]);
				add_events (i, l[0], l[1]);
				add_events (i, l[2], l[3]);
			}

		//cerr << "solve(" << i << "):" << endl;
		int cnt = solve_events();
		ans = max (ans, formula (k, cnt));
	}

	cout << ans << endl;
}



int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}