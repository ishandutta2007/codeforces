#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
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
#define mp  make_pair
#define fs  first
#define sc  second
#define pb  push_back


const int MAXN = 110000;


struct pt {
	int64 x, y;
	int id;
	bool fict;

	bool operator< (const pt & p) const {
		return mp (mp (x, y), (int)fict) < mp (mp (p.x, p.y), (int)fict);
	}
};

int test;
int n;
pt p[MAXN];
int64 v;
vector<int> ys;
int t[5*MAXN];


bool read() {
	if (! (cin >> n))  return false;
	forn(i,n) {
		int x, t;
		scanf ("%d%d", &x, &t);
		p[i].x = x;
		p[i].y = t;
		p[i].id = i;
		p[i].fict = false;
	}
	cin >> v;
	return true;
}


int get_max (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (tl == l && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return max (get_max (v*2, tl, tm, l, min(r,tm)),
			get_max (v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update (int v, int tl, int tr, int pos, int val) {
	t[v] = max (t[v], val);

	if (tl == tr)
		return;
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		update (v*2, tl, tm, pos, val);
	else
		update (v*2+1, tm+1, tr, pos, val);
}


void solve() {
	p[n].x = p[n].y = 0;
	p[n].fict = true;
	++n;

	forn(i,n) {
		int64 x = p[i].x,  t = p[i].y;
		t *= v;

		p[i].x = x - t;
		p[i].y = -x - t;
	}

	sort (p, p+n);

	ys.resize (n);
	forn(i,n)
		ys[i] = p[i].y;
	sort (all (ys));
	ys.erase (unique (all (ys)), ys.end());
	forn(i,n)
		p[i].y = int (lower_bound (all (ys), (int)p[i].y) - ys.begin());

	memset (t, 0, sizeof t);
	int ans_z = -INF,  ans = -INF;
	forn(i,n) {
		pt cur = p[i];
		int cur_d = 1 + get_max (1, 0, (int)ys.size()-1, 0, (int)cur.y);

		if (cur.fict)
			ans_z = max (ans_z, cur_d-1);
		else {
			update (1, 0, (int)ys.size()-1, (int)cur.y, cur_d);
			ans = max (ans, cur_d);
		}
	}

	cout << ans_z << ' ' << ans << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read()) {
		++test;
		solve();
	}

}