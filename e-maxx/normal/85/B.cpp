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


const int MAXN = 110000;


int n, k[3], t[3], start[MAXN];


bool read() {
	forn(i,3)
		if (! (cin >> k[i]))
			return false;
	forn(i,3)
		cin >> t[i];
	cin >> n;
	forn(i,n)
		scanf ("%d", &start[i]);
	return true;
}


void solve() {
	set < pair<int64,int> > w[3], q[3];
	set<int64> e (start, start+n);
	int ptr = 0;

	int64 ans = 0;
	while (e.size()) {
		int64 time = *e.begin();
		e.erase (e.begin());
		for(;;) {
			bool f = false;

			if (ptr < n && start[ptr] == time) {
				f = true;
				q[0].insert (mp (time, ptr++));
			}

			forn(i,3)
				if (w[i].size() && w[i].begin()->fs == time) {
					f = true;
					int who = w[i].begin()->sc;
					w[i].erase (w[i].begin());
					if (i != 2)
						q[i+1].insert (mp (time, who));
					else
						ans = max (ans, time - start[who]);
				}

			forn(i,3)
				if (q[i].size() && (int) w[i].size() < k[i]) {
					f = true;
					int who = q[i].begin()->sc;
					q[i].erase (q[i].begin());
					w[i].insert (mp (time + t[i], who));
					e.insert (time + t[i]);
				}

			if (!f)  break;
		}
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