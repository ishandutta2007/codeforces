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


int n;
int tp[MAXN], num[MAXN];


bool read() {
	if (! (cin >> n))  return false;
	forn(i,n) {
		char buf[10];
		scanf (" %s", buf);
		if (buf[0] == 'a') {
			tp[i] = +1;
			scanf ("%d", &num[i]);
		}
		else if (buf[0] == 'd') {
			tp[i] = -1;
			scanf ("%d", &num[i]);
		}
		else
			tp[i] = 0;
	}
	return true;
}


vector<int> v;
int sz;
int64 t[MAXN*4][5];
int tadd[MAXN*4], tcnt[MAXN*4];

inline void push (int v, int tl, int tr) {
	if (tadd[v] == 0)  return;
	tadd[v] %= 5;
	if (tadd[v] < 0)  tadd[v] += 5;
	if (tadd[v] == 0)  return;

	rotate (t[v], t[v]+(5-tadd[v])%5, t[v]+5);
	if (tl != tr) {
		tadd[v*2] += tadd[v];
		tadd[v*2+1] += tadd[v];
	}
	tadd[v] = 0;
}

inline void upd (int v, int tl, int tr) {
	if (tl != tr) {
		int tm = (tl + tr) / 2;
		push (v*2, tl, tm);
		push (v*2+1, tm+1, tr);

		forn(i,5)
			t[v][i] = t[v*2][i] + t[v*2+1][i];
		tcnt[v] = tcnt[v*2] + tcnt[v*2+1];
	}
}

void rotate (int v, int tl, int tr, int l, int r, int cnt) {
	push (v, tl, tr);
	upd (v, tl, tr);

	if (l > r)  return;
	
	if (l == tl && tr == r) {
		tadd[v] += cnt;
	}
	else {
		int tm = (tl + tr) >> 1;
		rotate (v*2, tl, tm, l, min(r,tm), cnt);
		rotate (v*2+1, tm+1, tr, max(l,tm+1), r, cnt);
	}

	push (v, tl, tr);
	upd (v, tl, tr);
}

int get_count (int v, int tl, int tr, int l, int r) {
	push (v, tl, tr);
	upd (v, tl, tr);

	if (l > r)  return 0;
	
	int res;
	if (l == tl && tr == r)
		res = tcnt[v];
	else {
		int tm = (tl + tr) >> 1;
		res = get_count (v*2, tl, tm, l, min(r,tm)) + get_count (v*2+1, tm+1, tr, max(l,tm+1), r);
	}

	push (v, tl, tr);
	upd (v, tl, tr);

	return res;
}

void increase (int v, int tl, int tr, int pos, int mod, int val) {
	push (v, tl, tr);
	upd (v, tl, tr);

	if (tl == tr) {
		t[v][mod] += val;
		
		if (val > 0)
			++tcnt[v];
		else
			--tcnt[v];
	}
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm)
			increase (v*2, tl, tm, pos, mod, val);
		else
			increase (v*2+1, tm+1, tr, pos, mod, val);
	}

	push (v, tl, tr);
	upd (v, tl, tr);
}

void solve() {
	v.clear();
	forn(i,n)
		if (tp[i])
			v.pb (num[i]);
	sort (all (v));
	v.erase (unique (all (v)), v.end());
	sz = (int) v.size();

	memset (t, 0, sizeof t);
	memset (tadd, 0, sizeof tadd);
	memset (tcnt, 0, sizeof tcnt);
	forn(i,n) {
		if (tp[i] == 0) {
			push (1, 0, sz-1);
			printf ("%I64d\n", t[1][2]);
			continue;
		}
		
		int x = int (lower_bound (all (v), num[i]) - v.begin());
		int mod = get_count (1, 0, sz-1, 0, x-1) % 5;

		if (tp[i] == +1) {
			rotate (1, 0, sz-1, x+1, sz-1, +1);
			increase (1, 0, sz-1, x, mod, num[i]);
		}
		else {
			rotate (1, 0, sz-1, x+1, sz-1, -1);
			increase (1, 0, sz-1, x, mod, -num[i]);
		}
	}
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}