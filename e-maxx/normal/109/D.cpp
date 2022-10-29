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

int n, a[MAXN];


bool read() {
	if (! (cin >> n))  return false;
	forn(i,n)
		scanf ("%d", &a[i]);
	return true;
}


pair<int,int> b[MAXN];
int p[MAXN];
bool u[MAXN];


bool sorted() {
	fore(i,1,n)
		if (a[i-1] > a[i])
			return false;
	return true;
}


bool good (int n) {
	while (n) {
		int c = n % 10;
		if (c != 4 && c != 7)
			return false;
		n /= 10;
	}
	return true;
}


void solve() {
	forn(i,n)
		b[i] = mp (a[i], i);
	sort (b, b+n);

	if (sorted()) {
		puts ("0");
		return;
	}

	int pos = -1;
	forn(i,n)
		if (good (a[i]))
			pos = i;
	if (pos == -1) {
		puts ("-1");
		return;
	}

	forn(i,n)
		p[i] = int (lower_bound (b, b+n, mp (a[i], i)) - b);

	memset (u, 0, sizeof u);
	vector < pair<int,int> > ans;
	vector<int> my_cycle;
	forn(i,n)
		if (!u[i]) {
			vector<int> cycle;
			bool my = false;
			for (int j=i; ; j=p[j]) {
				if (u[j])  break;
				u[j] = true;
				cycle.pb (j);
				if (j == pos)
					my = true;
			}

			if (my)
				my_cycle = cycle;
			else if (cycle.size() > 1) {
				int cpos = pos;
				ford(j,cycle.size()) {
					ans.pb (mp (cpos, cycle[j]));
					cpos = cycle[j];
				}
				ans.pb (mp (cpos, pos));
			}
		}

	if (my_cycle.size() > 1) {
		rotate (my_cycle.begin(), find (all (my_cycle), pos), my_cycle.end());
		int cpos = pos;
		ford(i,my_cycle.size())
			if (i) {
				ans.pb (mp (cpos, my_cycle[i]));
				cpos = my_cycle[i];
			}
	}

	forn(i,ans.size())
		if (! good (a[ans[i].fs]) && ! good (a[ans[i].sc]))
			throw;
		else
			swap (a[ans[i].fs], a[ans[i].sc]);
	if (! sorted())
		throw;

	printf ("%d\n", ans.size());
	forn(i,ans.size())
		printf ("%d %d\n", ans[i].fs+1, ans[i].sc+1);
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