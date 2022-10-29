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
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-7;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


int t1, t2, a, b, t0;


bool read() {
	return !! (cin >> t1 >> t2 >> a >> b >> t0);
}


void solve() {
	if (t2 == t0) {
		cout << (t1==t0 ? a : 0) << ' ' << b << endl;
		return;
	}

	int64 lx = 0,  ly = b;
	double minv = t2;
	for (int x=1; x<=a; ++x) {
		int64 ch = x * 1ll * (t0 - t1);
		int64 zn = t2 - t0;
		
		int64 cx = x,
			cy = (ch + zn-1) / zn;
		if (cy > b)
			continue;

		double ct = (cx * t1 + cy * t2) * 1.0 / (cx + cy);
		if (ct < minv - EPS || abs (ct - minv) < EPS && cx+cy > lx+ly) {
			minv = ct;
			lx = cx;
			ly = cy;
		}
	}

	cout << lx << ' ' << ly << endl;
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