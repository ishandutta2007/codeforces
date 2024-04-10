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


const int N = 8;


char a[N][N];

bool read() {
	forn(i,N)
		forn(j,N)
			if (! (cin >> a[i][j]))
				return false;
	return true;
}


int qh, qt;
pair < int, pair<int,int> > q[N*N*1000];
bool u[N][N][1000];

void upd (int x, int y, int t) {
	if (x<0 || y<0 || x>=N || y>=N)
		return;
	if (x-t+1<0 || a[x-t+1][y] != 'S')
		if (x==0 && y==N-1 || x-t<0 || a[x-t][y] != 'S')
			if (!u[x][y][t]) {
				u[x][y][t] = true;
				q[qt++] = mp (t, mp (x, y));
			}
}

void solve() {
	qh = qt = 0;
	memset (u, 0, sizeof u);
	q[qt++] = mp (0, mp (N-1, 0));
	u[N-1][0][0] = true;
	while (qh != qt) {
		int x = q[qh].sc.fs,
			y = q[qh].sc.sc,
			t = q[qh].fs;
		++qh;
		if (x == 0 && y == N-1) {
			puts ("WIN");
			return;
		}

		if (t != 999)
			for (int dx=-1; dx<=1; ++dx)
				for (int dy=-1; dy<=1; ++dy)
					upd (x+dx, y+dy, t+1);
	}

	puts ("LOSE");
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