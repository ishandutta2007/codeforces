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


const int MAXN = 100;


int n, a[MAXN];


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n)
		cin >> a[i];
	return true;
}


void solve() {
	sort (a, a+n);

	int t1 = 6 * 60 - 10;
	int last1 = -1;
	int c1 = 0;
	forn(i,n)
		if (a[i] <= t1) {
			t1 -= a[i];
			++c1;
			last1 = i;
		}
		else
			break;

	int c2 = 0;
	int pen = 0;
	int t2 = 6 * 60 + t1;
	int time = -t1;
	fore(i,last1+1,n)
		if (a[i] <= t2) {
			time += a[i];
			pen += time;
			t2 -= a[i];
			++c2;
		}

	cout << c1+c2 << ' ' << pen << endl;
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