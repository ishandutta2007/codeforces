#pragma comment (linker, "/STACK:200000000")
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


const int MAXN = 110000;


int n, l, v1, v2, a[MAXN];
double ans[MAXN];


bool read() {
	if (! (cin >> n >> l >> v1 >> v2))
		return false;
	forn(i,n)
		scanf ("%d", &a[i]);
	return true;
}


struct event {
	double x;
	int tp, id;

	event() { }
	event (double x, int tp, int id)
		: x(x), tp(tp), id(id)
	{ }

	bool operator< (const event& e) const {
		return abs(x-e.x)<EPS ? tp<e.tp : x<e.x;
	}
};


void solve() {
	double len = l * (v2 * 1.0 / (v1 + v2));

	vector<event> e;
	forn(i,n) {
		forn(j,5) {
			double delta = l * 2.0 * j;
			e.pb (event (a[i]-len+delta, +1, i));
			e.pb (event (a[i]+delta, -1, i));
		}
	}
	sort (all (e));

	int bal = 0;
	double prev_x = -1E20;
	memset (ans, 0, sizeof ans);
	forn(i,e.size()) {
		double x = e[i].x;

		double Lx = max (prev_x, (double)l);
		double Rx = min (x, 3.0 * l);
		if (Lx < Rx - EPS)
			ans[bal] += (Rx - Lx) / (2.0 * l);

		int tp = e[i].tp;
		while (i<(int)e.size() && abs(e[i].x-x)<EPS && e[i].tp == tp) {
			bal += e[i].tp;
			++i;
		}
		--i;

		prev_x = x;
	}

	forn(i,n+1)
		printf ("%.20lf\n", ans[i]);
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