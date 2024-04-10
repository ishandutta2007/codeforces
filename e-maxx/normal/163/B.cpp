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


int n, k, h;
pair < pair<int,int>, int > a[MAXN];


bool read() {
	if (! (cin >> n >> k >> h))
		return false;
	forn(i,n) {
		scanf ("%d", &a[i].fs.fs);
		a[i].sc = i;
	}
	forn(i,n)
		scanf ("%d", &a[i].fs.sc);
	return true;
}


int ans[MAXN];

bool can (double t) {
	int ptr = 0;
	for (int j=1; j<=k; ++j) {
		double v_lim = j * h * 1.0 / t;
		while (ptr<n && a[ptr].fs.sc < v_lim)
			++ptr;
		if (ptr == n)  return false;
		ans[j-1] = a[ptr].sc;
		++ptr;
	}

	return true;
}


void solve() {
	sort (a, a+n);

	double lt = 0,
		rt = 1E10;
	forn(iter,100) {
		double mid = (lt + rt) / 2;
		if (can (mid))
			rt = mid;
		else
			lt = mid;
	}

	if (! can (rt))
		throw;

	forn(i,k)
		printf ("%d ", ans[i]+1);
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