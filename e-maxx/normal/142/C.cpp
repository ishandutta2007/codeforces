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


const int MAXN = 9;


int n, m;


bool read() {
	return !! (cin >> n >> m);
}


int d[MAXN+1][MAXN][1<<MAXN][1<<MAXN], iter;
char ans[MAXN+1][MAXN+1];

int get_d (int x, int y, int m1, int m2) {
	if (x >= n)  return 0;
	if (y >= m)  return get_d (x+1, 0, m1, m2);

	int & my = d[x][y][m1][m2];
	if (my != -1)  return my;

	int bit = 1<<y,
		bit1 = bit<<1,
		bit2 = bit<<2,
		lbit = bit>>1;
	int b1 = m1 & bit,
		b2 = m2 & bit;
	int n1 = m1 - b1 + b2,
		n2 = m2 - b2;
	my = get_d (x, y+1, n1, n2);

	if (x >= 2 && y+2 < m) {

		if (! b1 && ! b2 && ! (m2 & bit1) && ! (m2 & bit2)) // right
			my = max (my, 1 + get_d (x, y+1, n1 | bit, n2 | bit | bit1 | bit2));

		if (! b1 && ! (m1 & bit1) && ! (m2 & bit1) && ! (m1 & bit2)) // down
			my = max (my, 1 + get_d (x, y+3, n1 | bit1 | (n2 & bit2), (n2 | bit1) & ~bit2));

	}

	if (x >= 2 && y >= 1 && y+1 < m) {

		if (! (m1 & lbit) && ! b2 && ! (m1 & bit1) && ! (m2 & bit1))  // left
			my = max (my, 1 + get_d (x, y+2, n1 | lbit | bit | bit1, n2 | bit1));

		if (! (m1 & bit) && ! (m2 & bit) && ! (m2 & lbit)) // up
			my = max (my, 1 + get_d (x, y+2, n1 | bit, n2 | lbit | bit | bit1));

	}

	return my;
}

void restore (int x, int y, int m1, int m2) {
	if (x >= n)  return;
	if (y >= m)  return restore (x+1, 0, m1, m2);

	int my = d[x][y][m1][m2];

	int bit = 1<<y,
		bit1 = bit<<1,
		bit2 = bit<<2,
		lbit = bit>>1;
	int b1 = m1 & bit,
		b2 = m2 & bit;
	int n1 = m1 - b1 + b2,
		n2 = m2 - b2;
	
	if (my == get_d (x, y+1, n1, n2))
		return restore (x, y+1, n1, n2);

	if (x >= 2 && y+2 < m) {

		if (! b1 && ! b2 && ! (m2 & bit1) && ! (m2 & bit2)) // right
			if (my == 1 + get_d (x, y+1, n1 | bit, n2 | bit | bit1 | bit2)) {
				ans[x][y] = ans[x-1][y] = ans[x-2][y] = ans[x-1][y+1] = ans[x-1][y+2] = char ('A' + iter++ % 26);
				return restore (x, y+1, n1 | bit, n2 | bit | bit1 | bit2);
			}

		if (! b1 && ! (m1 & bit1) && ! (m2 & bit1) && ! (m1 & bit2)) // down
			if (my == 1 + get_d (x, y+3, n1 | bit1, (n2 | bit1) & ~bit2)) {
				ans[x][y+1] = ans[x-1][y+1] = ans[x-2][y] = ans[x-2][y+1] = ans[x-2][y+2] = char ('A' + iter++ % 26);
				return restore (x, y+3, n1 | bit1 | (n2 & bit2), (n2 | bit1) & ~bit2);
			}

	}

	if (x >= 2 && y >= 1 && y+1 < m) {

		if (! (m1 & lbit) && ! b2 && ! (m1 & bit1) && ! (m2 & bit1))  // left
			if (my == 1 + get_d (x, y+2, n1 | lbit | bit | bit1, n2 | bit1)) {
				ans[x][y+1] = ans[x-1][y-1] = ans[x-1][y] = ans[x-1][y+1] = ans[x-2][y+1] = char ('A' + iter++ % 26);
				return restore (x, y+2, n1 | lbit | bit | bit1, n2 | bit1);
			}

		if (! (m1 & bit) && ! (m2 & bit) && ! (m2 & lbit)) // up
			if (my == 1 + get_d (x, y+2, n1 | bit, n2 | lbit | bit | bit1)) {
				ans[x][y] = ans[x][y-1] = ans[x][y+1] = ans[x-1][y] = ans[x-2][y] = char ('A' + iter++ % 26);
				return restore (x, y+2, n1 | bit, n2 | lbit | bit | bit1);
			}

	}

	throw;
}


void solve() {
	memset (d, -1, sizeof d);
	cout << get_d (0, 0, 0, 0) << endl;

	iter = 0;
	memset (ans, 0, sizeof ans);
	forn(i,n)
		forn(j,m)
			ans[i][j] = '.';
	restore (0, 0, 0, 0);
	forn(i,n) {
		forn(j,m)
			cout << ans[i][j];
		cout << endl;
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