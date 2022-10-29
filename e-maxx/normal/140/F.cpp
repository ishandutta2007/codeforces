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
#define mp  make_pair


const int MAXN = 210000;


struct pt {
	int x, y, id;

	bool operator< (const pt & p) const {
		return mp (x, y) < mp (p.x, p.y);
	}
};


int n, k;
pt a[MAXN], b[MAXN];


bool read() {
	if (! (cin >> n >> k))
		return false;
	forn(i,n) {
		scanf ("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	return true;
}


int killed[MAXN], cu;


inline void skip (pt p[], int & ptr) {
	while (ptr < n && killed[ p[ptr].id ] == cu)
		++ptr;
}

bool check (pt delta) {
	++cu;

	int already = 0;
	int pa = 0,
		pb = 0;
	for(;;) {
		skip (a, pa);
		skip (b, pb);
		if (pa == n && pb == n)  break;

		if (pa == n) {
			++pb;
			if (++already > k)  return false;
			continue;
		}
		if (pb == n) {
			++pa;
			if (++already > k)  return false;
			continue;
		}

		pt tmp = b[pb];
		tmp.x += delta.x;
		tmp.y += delta.y;
		if (tmp.x == a[pa].x && tmp.y == a[pa].y) {
			++pa;
			++pb;
			continue;
		}

		if (++already > k)  return false;

		if (tmp < a[pa]) {
			killed[b[pb].id] = cu;
			++pb;
		}
		else {
			killed[a[pa].id] = cu;
			++pa;
		}
	}
	return already <= k;
}


void solve() {
	if (k >= n) {
		puts ("-1");
		return;
	}

	forn(i,n) {
		b[i] = a[i];
		b[i].x *= -1;
		b[i].y *= -1;
	}
	sort (a, a+n);
	sort (b, b+n);

	set<pt> ans;
	forn(c1,min(n,k+13))
		forn(c2,min(n,k+13)) {
			pt delta;
			delta.x = a[c2].x - b[c1].x;
			delta.y = a[c2].y - b[c1].y;
			
			if (! ans.count (delta))
				if (check (delta))
					ans.insert (delta);
		}

	printf ("%d\n", ans.size());
	for (set<pt>::iterator i=ans.begin(); i!=ans.end(); ++i) {
		pt p = *i;
		printf ("%.1lf %.1lf\n", p.x/2.0, p.y/2.0);
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