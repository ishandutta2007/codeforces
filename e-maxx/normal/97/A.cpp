#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 35;


int n, m;
char a[MAXN][MAXN];


bool read() {
	if (! (cin >> n >> m))
		return false;
	forn(i,n)
		forn(j,m)
			cin >> a[i][j];
	return true;
}


bool inside (int x, int y) {
	return 0<=x && x<n && 0<=y && y<m;
}


int sq[MAXN][MAXN], sqs, sx[MAXN], sy[MAXN];
pair<int,int> mt[MAXN][MAXN];
int ans, cnt[7], col[MAXN];
bool u[7][7];
char ans_s[MAXN][MAXN];

bool check (int sx, int sy, int type) {
	int here = 0;
	
	static pair<int,int> q[4];
	int qs = 0;

	forn(dx,2)
		forn(dy,2) {
			int x=sx+dx,  y=sy+dy;
			if (! inside (x, y) || a[x][y] == '.')  throw;

			pair<int,int> neigh = mt[x][y];
			int x2 = neigh.fs,
				y2 = neigh.sc;

			if (sq[x][y] == sq[x2][y2] && neigh < mp(x,y))
				continue;

			int c1 = col[sq[x][y]],
				c2 = col[sq[x2][y2]];
			if (c1 == -1 || c2 == -1)  continue;
			if (c2 < c1)  swap (c1, c2);
			
			if (type == 0 && u[c1][c2]) {
				forn(i,qs)
					u[q[i].fs][q[i].sc] = false;
				return false;
			}
			if (type == 0) {
				q[qs++] = mp (c1, c2);
				u[c1][c2] = true;
			}
			if (type == -1)
				u[c1][c2] = false;
		}
	if (type == 0 && here > 2)  return false;
	return true;
}

void brute (int id) {
	if (id == sqs) {
		++ans;

		forn(i,7)
			forn(j,i+1)
				if (!u[j][i])
					throw;

		if (ans == 1) {
			forn(i,n)
				forn(j,m)
					ans_s[i][j] = a[i][j]=='.' ? '.' : char('0' + col[sq[i][j]]);
		}

		return;
	}

	forn(cur,7) {
		if (cnt[cur] == 2)  continue;

		++cnt[cur];
		col[id] = cur;

		if (check (sx[id], sy[id], 0)) {
			brute (id+1);
			
			check (sx[id], sy[id], -1);
		}

		--cnt[cur];
		col[id] = -1;
	}
}


void solve() {
	sqs = 0;
	memset (sq, -1, sizeof sq);
	forn(i,n)
		forn(j,m)
			if (a[i][j] != '.' && sq[i][j] == -1) {
				sx[sqs] = i;
				sy[sqs] = j;
				forn(di,2)
					forn(dj,2) {
						int x=i+di, y=j+dj;
						if (!inside(x,y) || a[x][y] == '.' || sq[x][y] != -1)  throw;
						sq[x][y] = sqs;
					}
				++sqs;
			}
	if (sqs != 14)  throw;

	forn(i,n)
		forn(j,m)
			if (a[i][j] != '.') {
				bool f = false;
				for (int ii=i-1; ii<=i+1; ++ii)
					for (int jj=j-1; jj<=j+1; ++jj)
						if (inside (ii, jj) && a[ii][jj] == a[i][j] && mp(i,j) != mp(ii,jj)) {
							if (f)  throw;
							f = true;
							mt[i][j] = mp (ii, jj);
						}
				if (!f)  throw;
			}

	ans = 0;
	memset (col, -1, sizeof col);
	memset (ans_s, 0, sizeof ans_s);
	brute (0);
	
	cout << ans << endl;
	forn(i,n)
		puts (ans_s[i]);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}