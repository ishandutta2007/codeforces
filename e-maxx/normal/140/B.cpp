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


const int MAXN = 310;


int n, a[MAXN][MAXN];


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n+1)
		forn(j,n) {
			scanf ("%d", &a[i][j]);
			--a[i][j];
		}
	return true;
}


pair<int,int> mx[MAXN];

int find (int man, int card) {
	forn(i,n)
		if (a[man][i] == card)
			return i;
	return INF;
}

void solve() {
	forn(i,n) {
		mx[i] = i ? mx[i-1] : mp(-1,-1);
		if (find (n, i) < find (n, mx[i].fs)) {
			mx[i].sc = mx[i].fs;
			mx[i].fs = i;
		}
		else
			if (find (n, i) < find (n, mx[i].sc))
				mx[i].sc = i;
	}

	forn(who,n) {
		int sel = -1;
		forn(time,n) {
			pair<int,int> cur = mx[time];
			if (cur.fs != who) {
				if (find (who, cur.fs) < find (who, sel))
					sel = cur.fs;
			}
			else
				if (find (who, cur.sc) < find (who, sel))
					sel = cur.sc;
		}
		printf ("%d ", sel+1);
	}
	puts("");
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