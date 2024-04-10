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


vector<int> num;
int l1, r1, l2, r2, k;


bool read() {
	return !! (cin >> l1 >> r1 >> l2 >> r2 >> k);
}


int64 prob (int first1, int last1, int first2, int last2) {
	first1 = max (first1, l1);
	last1 = min (last1, r1);
	first2 = max (first2, l2);
	last2 = min (last2, r2);
	if (first1 > last1 || first2 > last2)  return 0;
	return (last1 - first1 + 1) * 1ll * (last2 - first2 + 1);
}


void solve() {
	int64 ans = 0;
	forn(i,num.size()-k+1) {
		int first = num[i],
			last = num[i+k-1],
			pfirst = i ? num[i-1]+1 : 1,
			nlast = i+k<(int)num.size() ? num[i+k]-1 : INF;
		ans += prob (pfirst, first, last, nlast);
		ans += prob (last, nlast, pfirst, first);
		if (k == 1)
			ans -= prob (first, first, first, first);
	}
	
	double dans = ans * 1.0 / ((r1 - l1 + 1) * 1ll * (r2 - l2 + 1));
	printf ("%.20lf\n", dans);
}



int main() {

	vector<int> prev;
	prev.pb (0);
	for(;;) {
		vector<int> cur;
		forn(i,prev.size()) {
			long long n = prev[i] * 10ll;
			if (n + 4 <= INF)
				cur.pb (int (n + 4));
			if (n + 7 <= INF)
				cur.pb (int (n + 7));
		}
		if (cur.empty())  break;
		forn(i,cur.size())
			num.pb (cur[i]);
		prev = cur;
	}
	
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