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


int64 l, r;

bool read() {
	return !! (cin >> l >> r);
}


int64 rev (int64 n) {
	char buf[20];
	sprintf (buf, "%I64d", n);
	forn(i,strlen(buf))
		buf[i] = '9' - (buf[i] - '0');
	return _atoi64 (buf);
}

int64 val (int64 n) {
	return n * 1ll * rev (n);
}


void solve() {
	int64 ans = 0;
	int64 pw = 5;
	forn(i,10) {
		int64 cur = min (max (l, pw), r);
		ans = max (ans, val ((int)cur));

		pw *= 10;
	}

	cout << ans << endl;
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}