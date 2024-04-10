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


const int MAXN = 210*1000;


int n, m, cost[MAXN];
vector < pair<int,int> > a[MAXN];


bool read() {
	if (! (cin >> n >> m))  return false;
	forn(i,n)
		scanf ("%d", &cost[i]);
	forn(i,n)
		a[i].clear();
	forn(i,m) {
		int l, r, x;
		scanf ("%d%d%d", &l, &r, &x);
		--l, --r;
		a[l].pb (mp (r, x));
	}
	return true;
}


int64 d[MAXN], t[MAXN*4], tadd[MAXN*4];

inline void push (int v, int tl, int tr) {
	if (tl != tr) {
		tadd[v*2] += tadd[v];
		tadd[v*2+1] += tadd[v];
	}
	t[v] += tadd[v];
	tadd[v] = 0;
}

int64 tree_max (int v, int tl, int tr, int l, int r) {
	push (v, tl, tr);
	if (l > r)  return -INF64;
	if (l == tl && tr == r)  return t[v];
	int tm = (tl + tr) >> 1;
	return max (
		tree_max (v*2, tl, tm, l, min(r,tm)),
		tree_max (v*2+1, tm+1, tr, max(l,tm+1), r)
	);
}

inline int64 get (int v) {
	return t[v] + tadd[v];
}

void tree_add (int v, int tl, int tr, int l, int r, int64 val) {
	push (v, tl, tr);
	if (l > r)  return;
	if (l == tl && tr == r)
		tadd[v] += val;
	else {
		int tm = (tl + tr) >> 1;
		tree_add (v*2, tl, tm, l, min(r,tm), val);
		tree_add (v*2+1, tm+1, tr, max(l,tm+1), r, val);
		t[v] = max (get(v*2), get(v*2+1));
	}
	push (v, tl, tr);
}

void tree_set (int v, int tl, int tr, int pos, int64 val) {
	push (v, tl, tr);
	if (tl == tr)
		t[v] = val;
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm)
			tree_set (v*2, tl, tm, pos, val);
		else
			tree_set (v*2+1, tm+1, tr, pos, val);
		t[v] = max (get(v*2), get(v*2+1));
	}
}

void solve() {
	memset (t, 0, sizeof t);
	memset (tadd, 0, sizeof tadd);
	memset (d, 0, sizeof d);
	int64 maxd = -INF64;
	ford(i,n) {
		tree_add (1, 0, n, i+1, n, -cost[i]);
		forn(j,a[i].size())
			tree_add (1, 0, n, a[i][j].fs+1, n, a[i][j].sc);
		
		maxd = d[i] = max (0ll, max (maxd, tree_max (1, 0, n, i+1, n)));
		tree_set (1, 0, n, i, d[i]);
	}

	cout << * max_element (d, d+n) << endl;
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