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


int n;


bool read() {
	return !! (cin >> n);
}


char a[4][110];

void solve() {
	if (n == 1)
		puts ("a\na\nb\nb");
	else if (n == 2)
		puts ("aa\nbb\ncc\ndd");
	else {
		memset (a, 0, sizeof a);

		a[2][0] = a[3][0] = 'a';
		if (n % 2 == 1)
			a[0][n-1] = a[1][n-1] = 'a';
		else
			a[2][n-1] = a[3][n-1] = 'a';

		int cur = 0;
		for (int i=0; i<n; i+=2) {
			if (i+1 < n && a[0][i+1] == 0) {
				a[0][i] = a[0][i+1] = char ('b' + cur++ % 25);
				a[1][i] = a[1][i+1] = char ('b' + cur++ % 25);
			}
			if (i+2 < n && a[2][i+1] == 0 && a[2][i+2] == 0) {
				a[2][i+1] = a[2][i+2] = char ('b' + cur++ % 25);
				a[3][i+1] = a[3][i+2] = char ('b' + cur++ % 25);
			}
		}

		forn(i,4)
			puts (a[i]);
	}
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}