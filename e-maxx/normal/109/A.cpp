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


int n;


bool read() {
	return !! (cin >> n);
}


void solve() {
	bool any = false;
	string ans;

	for (int c=0; c*4<=n; ++c) {
		int c7 = (n - c*4) / 7;
		if (c*4 + c7*7 != n)  continue;
		if (!any || c+c7 <= (int)ans.length()) {
			string cur = string(c,'4') + string(c7,'7');
			if (!any || cur.length() < ans.length() || cur.length() == ans.length() && cur < ans)
				ans = cur;
			any = true;
		}
	}

	if (ans == "")  ans = "-1";
	puts (ans.c_str());
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