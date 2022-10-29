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


int64 n;


bool read() {
	return !! (cin >> n);
}


int64 mi, ma;

inline void upd (int64 x, int64 y, int64 z) {
	int64 a = x+1, b = y+2, c = z+2;
	int64 cur = a*b*c - (a-1)*(b-2)*(c-2);
	mi = min (mi, cur);
	ma = max (ma, cur);
}

void solve() {
	vector<int64> v;
	for (int64 i=1; i*i<=n; ++i)
		if (n % i == 0) {
			v.pb (i);
			v.pb (n / i);
		}
	sort (all (v));

	mi = INF64;
	ma = -INF64;
	forn(i,v.size()) {
		int64 xy = v[i],
			z = n / xy;
		forn(j,i+1)
			if (v[i] % v[j] == 0) {
				int64 x = v[j],
					y = xy / x;
				upd (x, y, z);
				upd (x, z, y);
				upd (y, x, z);
				upd (y, z, x);
				upd (z, x, y);
				upd (z, y, x);
			}
	}

	cout << mi << ' ' << ma << endl;
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