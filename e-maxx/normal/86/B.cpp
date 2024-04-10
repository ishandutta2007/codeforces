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


const int MAXN = 1100;
const int dxy[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };


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

void gen() {
	n = rand() % 1000 + 1;
	m = rand() % 1000 + 1;

	forn(i,n)
		forn(j,m)
			a[i][j] = rand()%100 < 2 ? '#' : '.';
}


inline bool inside (int x, int y) {
	return 0<=x && x<n && 0<=y && y<m;
}


int ans[MAXN][MAXN], id, col[MAXN][MAXN];
pair<int,int> hist[MAXN*MAXN];
int hist_sz;


bool paint (int x, int y) {
	pair<int,int> q[6];
	int qh = 0, qt = 0;
	q[qt++] = mp (x, y);
	while (qh != qt) {
		int x = q[qh].fs,
			y = q[qh].sc;
		++qh;

		forn(dir,4) {
			int nx = x + dxy[dir][0],
				ny = y + dxy[dir][1];
			if (inside (nx, ny) && ans[x][y] == ans[nx][ny] && find (q, q+qt, mp(nx,ny)) == q+qt) {
				q[qt++] = mp (nx, ny);
				if (qt > 5)
					throw;
			}
		}
	}

	bool used[10] = { 0 };
	forn(i,qt) {
		int x = q[i].fs,
			y = q[i].sc;

		forn(dir,4) {
			int nx = x + dxy[dir][0],
				ny = y + dxy[dir][1];
			if (inside (nx, ny) && ans[nx][ny] != ans[x][y] && col[nx][ny] != -1)
				used[col[nx][ny]] = true;
		}
	}

	forn(c,10)
		if (!used[c]) {

			forn(i,qt) {
				int x = q[i].fs,
					y = q[i].sc;
				col[x][y] = c;
				hist[hist_sz++] = mp (x, y);
			}

			bool ok = true;
			int old_hist = hist_sz;
			forn(i,qt) {
				int x = q[i].fs,
					y = q[i].sc;

				forn(dir,4) {
					int nx = x + dxy[dir][0],
						ny = y + dxy[dir][1];
					if (inside (nx, ny) && ans[nx][ny] != -1 && ans[nx][ny] != ans[x][y] && col[nx][ny] == -1) {
						if (! paint (nx, ny)) {
							ok = false;

							goto end;
						}
					}
				}
			}
					
end:;
			if (ok)
				return true;

			fore(i,old_hist,hist_sz) {
				int x = hist[i].fs,
					y = hist[i].sc;
				if (col[x][y] == -1)  throw;
				col[x][y] = -1;
			}

			forn(i,qt) {
				int x = q[i].fs,
					y = q[i].sc;
				col[x][y] = -1;
				--hist_sz;
			}

		}

	return false;
}

void solve() {
	memset (ans, -1, sizeof ans);

	forn(i,n)
		forn(j,m)
			if (a[i][j] == '.' && ans[i][j] == -1) {
				if (j+1 < m && a[i][j+1] == '.' && ans[i][j+1] == -1)
					ans[i][j] = ans[i][j+1] = id++;
				else if (i+1 < n && a[i+1][j] == '.' && ans[i+1][j] == -1)
					ans[i][j] = ans[i+1][j] = id++;
			}

	forn(i,n)
		forn(j,m)
			if (a[i][j] == '.' && ans[i][j] == -1) {
				int deg = 0;

				forn(dir,4) {
					int ni = i + dxy[dir][0],
						nj = j + dxy[dir][1];
					if (inside (ni, nj) && a[ni][nj] == '.') {
						++deg;

						if (ans[ni][nj] == -1)  throw;
						ans[i][j] = ans[ni][nj];
						break;
					}
				}

				if (ans[i][j] == -1) {
					if (deg > 0)  throw;
					puts ("-1");
					return;
				}
			}

	memset (col, -1, sizeof col);
	hist_sz = 0;
	forn(i,n)
		forn(j,m)
			if (ans[i][j] != -1 && col[i][j] == -1)
				if (! paint (i, j))
					throw;

	forn(i,n) {
		forn(j,m)
			if (ans[i][j] == -1)
				printf ("#");
			else
				printf ("%c", char ('0' + col[i][j]));
		puts("");
	}
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	/*
	for(;;) {
		cerr << 'x';
		gen();
		solve();
		puts("");
	}
	*/


	bool fs = true;
	while (read()) {
		if (!fs)  puts("");

		solve();
		fs = false;
	}

}