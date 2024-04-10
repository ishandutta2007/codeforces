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


int a, b, c, d;


bool read() {
	return !! (cin >> a >> b >> c >> d);
}


void add (vector<string> & res, int start, int cnt) {
	int c1 = (cnt + 1) / 2,
		c2 = cnt - c1;
	if (start == 7)  swap (c1, c2);
	if (a < c1 || b < c2)  return;
	if (c1 == 0 && a > 0 || c2 == 0 && b > 0)  return;

	string s;
	for (int i=0, dig=start, i1=0, i2=0; i<cnt; ++i) {
		if (dig == 4 && i1 == 0)
			s += string (a - c1, '4');
		if (dig == 7 && i2 == c2-1)
			s += string (b - c2, '7');
		s += char ('0' + dig);

		if (dig == 4)
			++i1;
		else
			++i2;
		dig = 11 - dig;
	}
	res.pb (s);
}

void solve() {
	vector<string> res;
	if (c == d) {
		add (res, 4, c*2+1);
		add (res, 7, c*2+1);
	}
	if (c == d + 1)
		add (res, 4, c*2);
	if (d == c+1)
		add (res, 7, d*2);

	if (res.empty())
		puts ("-1");
	else
		puts (min_element (all (res)) ->c_str());
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