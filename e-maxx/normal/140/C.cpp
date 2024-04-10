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


int n, a[MAXN];


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n)
		scanf ("%d", &a[i]);
	return true;
}


map<int,int> b;
int ans[MAXN][3];

bool can (int cnt) {
	int sum = 0;
	for (map<int,int>::iterator it=b.begin(); it!=b.end(); ++it) {
		int cur = min (it->sc, cnt);
		sum += cur;
	}

	if (sum < cnt * 3)  return false;

	int ptr = 0;
	for (map<int,int>::iterator it=b.begin(); it!=b.end(); ++it) {
		int cur = min (it->sc, cnt);
		forn(i,cur)
			if (ptr < cnt * 3) {
				ans[ptr%cnt][ptr/cnt] = it->fs;
				++ptr;
			}
	}
	return true;
}


void solve() {
	b.clear();
	forn(i,n)
		++b[a[i]];

	int l = 0,
		r = n;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (can (m))
			l = m;
		else
			r = m - 1;
	}
	can (l);

	printf ("%d\n", l);
	forn(i,l) {
		sort (ans[i], ans[i]+3);
		reverse (ans[i], ans[i]+3);
		printf ("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
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