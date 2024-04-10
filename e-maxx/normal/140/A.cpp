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


int n, R, r;


bool read() {
	return !! (cin >> n >> R >> r);
}


bool solve() {
	if (r > R)
		return false;
	if (r == R)
		return n == 1;
	
	int d = R - r;
	if (r > d)
		return n == 1;
	double ang = 2 * asin (min (1.0, r * 1.0 / d));
	int cnt = int (2 * PI / ang + EPS);
	return cnt >= n;
}



int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		puts (solve() ? "YES" : "NO");
#else
	if (!read())  throw;
	puts (solve() ? "YES" : "NO");
#endif
}