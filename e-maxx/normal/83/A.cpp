#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
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

int n, a[MAXN];

bool read() {
	if (! (cin >> n))  return false;
	forn(i,n)
		scanf ("%d", &a[i]);
	return true;
}


int64 f (int64 n) {
	return n * (n+1) / 2;
}

void solve() {
	int64 ans = 0;
	forn(i,n) {
		int j = i;
		while (j+1<n && a[j+1] == a[i])
			++j;
		ans += f (j-i+1);
		i = j;
	}
	cout << ans << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}