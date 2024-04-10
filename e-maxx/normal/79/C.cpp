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
typedef long long int64;

const int MAXN = 110000;


char s[MAXN];
int n;
string t[10];
int64 pw[MAXN], hh[MAXN], h[10];

bool read() {
	if (scanf (" %s", s) != 1)  return false;
	cin >> n;
	forn(i,n)
		cin >> t[i];
	return true;
}

int64 get_hash (int l, int r) {
	return (hh[r] - (l ? hh[l-1] : 0)) * pw[MAXN-1-l];
}

bool good (int l, int r) {
	forn(i,n)
		if (! ((int)t[i].length() > r-l+1 || h[i] != get_hash (r-(int)t[i].length()+1, r)))
			return false;
	return true;			
}

void solve() {
	int len = (int) strlen (s);
	forn(i,len)
		hh[i] = pw[i] * s[i] + (i ? hh[i-1] : 0);
	forn(i,n) {
		h[i] = 0;
		forn(j,t[i].size())
			h[i] += pw[j] * t[i][j];
		h[i] *= pw[MAXN-1];
	}

	int ansl = 0,  ansr = -1;

	int r = -1;
	forn(l,len) {
		r = max (r, l-1);
		while (r+1<len && good (l, r+1))
			++r;
		if (r-l+1 > ansr-ansl+1)
			ansl = l,  ansr = r;
	}

	cout << ansr-ansl+1 << ' ' << ansl << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	forn(i,MAXN)
		pw[i] = (i ? pw[i-1]*313 : 1);

	while (read())
		solve();

}