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


const int MAXN = 1001000;
const int MAXT = 4*MAXN;


int n, m, s[MAXN];


bool read() {
	if (! (cin >> n >> m))
		return false;
	forn(i,n) {
		char x;
		scanf (" %c", &x);
		s[i] = x=='4' ? 0 : 1;
	}
	return true;
}


bool inv[MAXT];
int ans1[MAXT], ans2[MAXT], c0[MAXT], c1[MAXT];

inline void push (int v, int tl, int tr) {
	if (inv[v]) {
		inv[v] = false;
		swap (c0[v], c1[v]);
		swap (ans1[v], ans2[v]);
		if (tl != tr) {
			inv[v*2] ^= true;
			inv[v*2+1] ^= true;
		}
	}
}

inline void recalc (int v) {
	c0[v] = c0[v*2] + c0[v*2+1];
	c1[v] = c1[v*2] + c1[v*2+1];
	ans1[v] = max (ans1[v*2]+c1[v*2+1], c0[v*2]+ans1[v*2+1]);
	ans2[v] = max (ans2[v*2]+c0[v*2+1], c1[v*2]+ans2[v*2+1]);
}

void build (int v, int tl, int tr) {
	inv[v] = false;
	if (tl == tr) {
		c0[v] = s[tl]==0;
		c1[v] = s[tl]==1;
		ans1[v] = ans2[v] = 1;
	}
	else {
		int tm = (tl + tr) >> 1;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		recalc (v);
	}
}

void do_inv (int v, int tl, int tr, int l, int r) {
	push (v, tl, tr);
	if (l > r)  return;

	if (l == tl && tr == r) {
		inv[v] = true;
		push (v, tl, tr);
		return;
	}

	int tm = (tl + tr) >> 1;
	do_inv (v*2, tl, tm, l, min(r,tm));
	do_inv (v*2+1, tm+1, tr, max(l,tm+1), r);
	recalc (v);
}


void solve() {
	build (1, 0, n-1);
	forn(i,m) {
		static char buf[10];
		scanf (" %s", buf);
	
		if (buf[0] == 'c')
			printf ("%d\n", ans1[1]);
		else {
			int l, r;
			scanf ("%d%d", &l, &r);
			--l, --r;
			do_inv (1, 0, n-1, l, r);
		}
	}
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