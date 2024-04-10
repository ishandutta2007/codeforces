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


int64 a, b, ax, ay, bx, by;


bool read() {
	return !! (cin >> a >> b >> ax >> ay >> bx >> by);
}


int64 mydiv (int64 a, int64 b) {
	if (a >= 0)
		return a / b;
	return -1 - (-a) / b;
}

int64 myabs (int64 n) {
	return n>=0 ? n : -n;
}

void solve() {
	int64
		x1 = mydiv (ax + ay, 2*a),
		y1 = mydiv (ax - ay, 2*b),
		x2 = mydiv (bx + by, 2*a),
		y2 = mydiv (bx - by, 2*b);
	int64 ans = max (myabs(x1-x2), myabs(y1-y2));
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