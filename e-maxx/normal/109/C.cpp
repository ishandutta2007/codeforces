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


int n;
vector<int> g[MAXN];
vector<char> good[MAXN];


bool is_good (int n) {
	while (n) {
		int c = n % 10;
		if (c != 4 && c != 7)  return false;
		n /= 10;
	}
	return true;
}


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n) {
		g[i].clear();
		good[i].clear();
	}
	forn(i,n-1) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c);
		--a, --b;
		g[a].pb (b);
		good[a].pb (is_good (c));
		g[b].pb (a);
		good[b].pb (is_good (c));
	}
	return true;
}


int size[MAXN];
int64 ans1[MAXN], ans2[MAXN], total_ans;


void dfs1 (int v, int par = -1) {
	size[v] = 1;
	ans1[v] = 0;

	forn(i,g[v].size()) {
		int to = g[v][i];
		if (to == par)  continue;
		dfs1 (to, v);

		size[v] += size[to];
		if (good[v][i])
			ans1[v] += size[to];
		else
			ans1[v] += ans1[to];
	}

	ans2[v] = ans1[v] * (ans1[v] - 1);
}


void dfs2 (int v, int64 up1, int64 up2, int par = -1) {
	total_ans += up2;
	total_ans += up1 * ans1[v] * 2;
	total_ans += ans2[v];

	forn(i,g[v].size()) {
		int to = g[v][i];
		if (to == par)  continue;

		int64 nup1, nup2;
		if (good[v][i]) {
			nup1 = n - size[to];
			nup2 = nup1 * (nup1 - 1);
		}
		else {
			int64 cur_ans = ans1[to];
			int64 cur_ans2 = ans2[v] - (ans1[v] - cur_ans) * (ans1[v] - cur_ans - 1);
			int64 cur_ans3 = 2 * (ans1[v] - cur_ans) * up1;
			nup1 = up1 + ans1[v] - cur_ans;
			nup2 = up2 + ans2[v] - cur_ans2 + cur_ans3;
		}
		
		dfs2 (to, nup1, nup2, v);
	}
}


void solve() {
	dfs1 (0);

	total_ans = 0;
	dfs2 (0, 0, 0);

	cout << total_ans << endl;
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