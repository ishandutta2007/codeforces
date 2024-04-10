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


const int MAXN = 310000;


int n, m, c, x[MAXN], a[MAXN], b[MAXN], p[MAXN];


bool read() {
	if (! (cin >> n >> m >> c))
		return false;
	forn(i,n)
		scanf ("%d", &x[i]);
	forn(i,n-1)
		scanf ("%d", &p[i]);
	forn(i,m) {
		scanf ("%d%d", &a[i], &b[i]);
		--a[i], --b[i];
	}
	return true;
}


struct val {
	double sum, pref, suff, ans;

	val() { }
	val (double x) {
		sum = x;
		pref = suff = ans = max (0.0, x);
	}
};

double tval[MAXN];
val t[4*MAXN];
 
val unite (val l, val r) {
	val res;
	res.sum = l.sum + r.sum;
	res.pref = max (l.pref, l.sum + r.pref);
	res.suff = max (r.suff, r.sum + l.suff);
	res.ans = max (max (l.ans, r.ans), l.suff + r.pref);
	return res;
}
 
void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = val (tval[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = unite (t[v*2], t[v*2+1]);
	}
}
 
val get (int v, int tl, int tr, int l, int r) {
	if (l == tl && tr == r)
		return t[v];
	int tm = (tl + tr) / 2;
	if (r <= tm)
		return get (v*2, tl, tm, l, r);
	if (l > tm)
		return get (v*2+1, tm+1, tr, l, r);
	return unite (
		get (v*2, tl, tm, l, tm),
		get (v*2+1, tm+1, tr, tm+1, r)
	);
}


void solve() {
	forn(i,n-1)
		tval[i] = (x[i+1] - x[i]) / 2.0 - c * (p[i] / 100.0);
	build (1, 0, n-2);

	double ans = 0;
	forn(i,m) {
		double cbest = get (1, 0, n-2, a[i], b[i]-1) .ans;
		if (cbest < -EPS)
			throw;
		ans += cbest;
	}
	printf ("%.20lf\n", ans);
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