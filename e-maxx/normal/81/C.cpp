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


const int MAXN = 210000;


int n, a, b;
pair<int,int> t[MAXN];
int ans[MAXN];


bool read() {
	if (! (cin >> n >> a >> b))  return false;
	forn(i,n) {
		int j;
		scanf ("%d", &j);
		t[i] = mp (j, i);
	}
	return true;
}


void solve() {
	if (a == b) {
		forn(i,a)
			ans[i] = 1;
		fore(i,a,n)
			ans[i] = 2;
	}
	else if (a > b) {
		sort (t, t+n);

		forn(i,a)
			ans[t[i].sc] = 1;
		fore(i,a,n)
			ans[t[i].sc] = 2;
	}
	else {
		forn(i,n)
			t[i].fs *= -1;
		sort (t, t+n);

		forn(i,a)
			ans[t[i].sc] = 1;
		fore(i,a,n)
			ans[t[i].sc] = 2;
	}

	forn(i,n)
		printf ("%d ", ans[i]);
	puts("");
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}