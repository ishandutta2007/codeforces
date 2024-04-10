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


const int MAXN = 1100;


int n, m;
pair<int,int> a[MAXN];
int ans[MAXN];

bool read() {
	if (! (cin >> n >> m))  return false;
	forn(i,m) {
		scanf ("%d", &a[i].fs);
		a[i].sc = i;
	}
	return true;
}


void no() {
	puts ("-1");
}

void solve() {
	sort (a, a+m);

	int s = 0;
	forn(i,m)
		s += a[i].fs;
	if (s < n)
		return no();

	if (m == 1 || n % 2 == 1 && m == 2)
		return no();

	memset (ans, -1, sizeof ans);
	if (a[m-1].fs >= n/2) {
		forn(i,n/2)
			ans[i*2] = a[m-1].sc;

		int nn = n;
		if (n % 2 == 1) {
			if (m == 2)  throw;
			ans[n-1] = a[0].sc;
			--a[0].fs;
			ans[n-2] = a[1].sc;
			--a[1].fs;
			nn -= 2;
		}

		int p = 0;
		forn(i,nn/2) {
			while (a[p].fs == 0)  ++p;
			if (p >= m-1)
				return no();

			ans[i*2+1] = a[p].sc;
			--a[p].fs;
		}
	}
	else {
		int p = 0;
		forn(i,n/2) {
			while (a[p].fs == 0)  ++p;
			if (p >= m)  throw;
			
			ans[i*2] = a[p].sc;
			--a[p].fs;
		}

		int nn = n;
		if (n % 2 == 1) {
			while (a[p].fs == 0)  ++p;
			if (p+1 >= m)  throw;
			
			ans[n-2] = a[p+1].sc;
			--a[p+1].fs;
			
			ans[n-1] = a[p].sc;
			--a[p].fs;

			nn -= 2;
		}
		forn(i,nn/2) {
			while (a[p].fs == 0)  ++p;
			if (p >= m)  throw;

			ans[i*2+1] = a[p].sc;
			--a[p].fs;
		}
	}

	forn(i,m)
		if (a[i].fs < 0)
			throw;
	forn(i,n)
		if (ans[i] == ans[(i+1)%n])
			throw;

	forn(i,n)
		printf ("%d ", ans[i]+1);
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