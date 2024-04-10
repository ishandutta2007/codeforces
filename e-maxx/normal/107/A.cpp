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



const int MAXN = 1000;

int n, m, g[MAXN], w[MAXN];
bool has_in[MAXN];


bool read() {
	if (! (cin >> n >> m))
		return false;

	memset (g, -1, sizeof g);
	memset (has_in, 0, sizeof has_in);
	forn(i,m) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		has_in[y] = true;
		g[x] = y;
		cin >> w[x];
	}

	return true;
}


void solve() {
	vector < pair<int, pair<int,int> > > res;
	forn(i,n)
		if (!has_in[i] && g[i] != -1) {
			int j = i,
				ans = INF;
			while (g[j] != -1) {
				ans = min (ans, w[j]);
				j = g[j];
			}
			res.pb (mp (i, mp (j, ans)));
		}

	printf ("%d\n", res.size());
	forn(i,res.size())
		printf ("%d %d %d\n", res[i].fs+1, res[i].sc.fs+1, res[i].sc.sc);
}



int main() {
#ifdef SU2_PROJ
        freopen ("input.txt", "rt", stdin);
        freopen ("output.txt", "wt", stdout);
		while (read())
                solve();
#else
        if (read())
                solve();
		else
				throw;
#endif
}