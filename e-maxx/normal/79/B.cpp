#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define all(a)  a.begin(), a.end()


const int MAXN = 50000;
const char* const arr[3] = { "Carrots", "Kiwis", "Grapes" };

int n, m, k, qs;
vector<int> v[MAXN];
int sumx[MAXN];


bool read() {
	if (! (cin >> n >> m >> k >> qs))  return false;
	forn(i,n)
		v[i].clear();
	forn(i,k) {
		int x, y;
		scanf ("%d%d", &x, &y);
		--x, --y;
		v[x].push_back (y);
	}
	return true;
}


void solve() {
	forn(i,n) {
		sort (all (v[i]));
		sumx[i] = (i ? sumx[i-1] : 0) + m - (int)v[i].size();
	}

	forn(i,qs) {
		int x, y;
		scanf ("%d%d", &x, &y);
		--x, --y;

		if (binary_search (all (v[x]), y)) {
			puts ("Waste");
			continue;
		}

		int cnt = int (lower_bound (all (v[x]), y) - v[x].begin());
		int idx = (x ? sumx[x-1] : 0) + y - cnt;
		puts (arr[idx%3]);
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}