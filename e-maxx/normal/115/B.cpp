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


const int MAXN = 160;


int n, m;
char a[MAXN][MAXN];


bool read() {
	if (! (cin >> n >> m))
		return false;
	forn(i,n)
		forn(j,m)
			scanf (" %c", &a[i][j]);
	return true;
}


int d[MAXN][MAXN][2], l[MAXN], r[MAXN], last_x;

int get_d (int x, int y, int dir) {
	if (x > last_x)  return 0;

	int & my = d[x][y][dir];
	if (my != -1)  return my;
	my = INF;

	int cy = y;
	for (int cnt=0; 0<=cy && cy<m; ++cnt, cy+=(dir==0?+1:-1)) {
		if (min(cy,y) <= l[x] && max(cy,y) >= r[x]) {
			int nd;
			if (x == last_x)
				nd = 0;
			else
				nd = 1 + get_d (x+1, cy, 1-dir);
			my = min (my, cnt + nd);
		}
	}

	return my;
}

void solve() {
	last_x = -1;
	forn(i,n) {
		l[i] = INF;
		r[i] = -INF;
		forn(j,m)
			if (a[i][j] == 'W') {
				l[i] = min (l[i], j);
				r[i] = max (r[i], j);
			}
		if (l[i] != INF)
			last_x = i;
	}

	memset (d, -1, sizeof d);
	cout << get_d (0, 0, 0) << endl;
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