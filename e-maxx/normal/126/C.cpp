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


const int MAXN = 2100;


int n;
char a[MAXN][MAXN];


bool read() {
	if (! (cin >> n))
		return false;
	gets (a[0]);
	forn(i,n)
		gets (a[i]);
	return true;
}


int r1[MAXN], r2[MAXN], c1[MAXN], c2[MAXN];


void solve() {
	memset (r1, 0, sizeof r1);
	memset (r2, 0, sizeof r2);
	memset (c1, 0, sizeof c1);
	memset (c2, 0, sizeof c2);
	int ans = 0;

	for (int d=n-1; d>=1; --d)
		forn(x,n) {
			int y = d + x;
			if (y >= n)  break;
			if ((a[x][y]-'0') ^ r1[x] ^ c1[y]) {
				++ans;
				r1[x] ^= 1;
				c1[y] ^= 1;
			}
		}

	for (int d=-n+1; d<=-1; ++d)
		forn(x,n) {
			int y = d + x;
			if (y < 0)  continue;
			if ((a[x][y]-'0') ^ r2[x] ^ c2[y]) {
				++ans;
				r2[x] ^= 1;
				c2[y] ^= 1;
			}
		}

	forn(i,n)
		if ((a[i][i]-'0') ^ r1[i] ^ c1[i] ^ r2[i] ^ c2[i])
			++ans;

	cout << ans << endl;
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