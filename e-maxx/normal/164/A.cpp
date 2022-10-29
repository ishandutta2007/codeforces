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


int n, m, tp[MAXN];
vector<int> g[MAXN], g2[MAXN];


bool read() {
	if (! (cin >> n >> m))
		return false;
	forn(i,n) {
		g[i].clear();
		g2[i].clear();
		scanf ("%d", &tp[i]);
	}
	forn(i,m) {
		int a, b;
		scanf ("%d%d", &a, &b);
		--a, --b;
		g[a].pb (b);
		g2[b].pb (a);
	}
	return true;
}


bool u1[MAXN], u2[MAXN];

void dfs1 (int v) {
	if (u1[v])  return;
	u1[v] = true;
	forn(i,g[v].size())
		if (tp[g[v][i]] != 1)
			dfs1 (g[v][i]);
}

void dfs2 (int v) {
	if (u2[v])  return;
	u2[v] = true;
	forn(i,g2[v].size())
		if (tp[g2[v][i]] != 1)
			dfs2 (g2[v][i]);
}


void solve() {
	memset (u1, 0, sizeof u1);
	memset (u2, 0, sizeof u2);
	forn(i,n)
		if (tp[i] == 1)
			dfs1 (i);
		else if (tp[i] == 2)
			dfs2 (i);

	forn(i,n) {
		bool ans = u2[i];
		forn(j,g[i].size())
			if (u2[g[i][j]])
				ans = true;
		printf ("%c\n", (u1[i] && ans) ? '1' : '0');
	}
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