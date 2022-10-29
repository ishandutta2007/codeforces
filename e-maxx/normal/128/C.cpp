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


const int MOD = INF + 7;
const int MAXN = 1100;


int c[MAXN][MAXN], n, m, k;


bool read() {
	return !! (cin >> n >> m >> k);
}


int get_c (int n, int k) {
	if (k < 0 || k > n)  return 0;
	return c[n][k];
}

void solve() {
	int ans = get_c (n-1, 2*k) * 1ll * get_c (m-1, 2*k) % MOD;
	cout << ans << endl;
}



int main() {
	forn(i,MAXN) {
		c[i][0] = c[i][i] = 1;
		for (int j=1; j<i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
	}

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