#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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
#define mp  make_pair
#define fs  first
#define sc  second
#define pb  push_back


const int MAXN = 110000;
const int MAXC = 10000;


int test;
int n, x[MAXN], y[MAXN];


bool read() {
	if (! (cin >> n))  return false;
	forn(i,n)
		scanf ("%d%d", &x[i], &y[i]);
	return true;
}


int64 solve (int a[]) {
	forn(i,n)
		a[i] += MAXC;

	int64 cur = 0;
	forn(i,n)
		cur += a[i] * a[i];
	int64 cx = 0;

	int64 sum = 0;
	forn(i,n)
		sum += a[i];

	int64 ans = 0;
	forn(i,n) {
		int j = i;
		while (i+1<n && a[i+1] == a[j])
			++i;

		int c = i-j+1;

		while (cx != a[i]) {
			cur += n + 2 * n * cx - 2 * sum;
			++cx;
		}

		ans += cur * c;
	}
	return ans;
}

void solve() {
	sort (x, x+n);
	sort (y, y+n);
	int64 ans = solve (x) + solve (y);
	cout << ans / 2 << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read()) {
		++test;
		solve();
	}

}