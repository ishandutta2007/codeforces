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

int n, k;
char a[MAXN];


bool read() {
	if (! (cin >> n >> k))
		return false;
	forn(i,n)
		scanf (" %c", &a[i]);
	return true;
}


void solve() {
	int pos = 0;
	vector<int> oper;
	forn(i,k) {
		while (pos+1 < n && (a[pos] != '4' || a[pos+1] != '7'))
			++pos;
		if (pos >= n-1)
			break;

		if (pos % 2 == 0)
			a[pos] = a[pos+1] = '4';
		else {
			a[pos] = a[pos+1] = '7';
			if (pos)
				--pos;
		}

		if (oper.size() >= 2 && oper[oper.size()-2] == pos)
			i += max (0, (k - i - 10) / 2 * 2);
		oper.pb (pos);
	}

	forn(i,n)
		printf ("%c", a[i]);
	puts("");
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