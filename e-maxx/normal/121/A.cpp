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


vector<int64> v;
int l, r;


bool read() {
	return !! (cin >> l >> r);
}


void solve() {
	int prev = l - 1;
	int64 ans = 0;
	forn(i,v.size())
		if (v[i] >= l) {
			int cur = (int) min ((int64)r, v[i]);
			ans += (cur - prev) * v[i];

			if (v[i] > r)
				break;
			prev = (int)v[i];
		}
	cout << ans << endl;
}



int main() {
	v.pb (0);
	forn(i,v.size()) {
		int64 c = v[i] * 10ll + 4;
		if (c < 1E11) {
			v.pb (c);
			v.pb (c + 3);
		}
	}
	sort (all (v));

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