#pragma comment (linker, "/STACK:200000000")
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
const int INF = (int) 1E9 + 100;
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
int root, val[MAXN];


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n)
		g[i].clear();
	forn(i,n) {
		int p;
		scanf ("%d%d", &p, &val[i]);
		if (p == -1)
			root = i;
		else
			g[p-1].pb (i);
	}
	return true;
}


int min_l[MAXN], max_r[MAXN];
pair<int64,int> ans[MAXN];
int leftmost[MAXN], rightmost[MAXN];

void dfs (int v, int min_left, int max_right) {
	min_l[v] = min_left;
	max_r[v] = max_right;
	if (g[v].empty()) {
		leftmost[v] = rightmost[v] = val[v];
		return;
	}

	forn(i,g[v].size()) {
		int to = g[v][i];
		
		int nl = min_left,  nr = max_right;
		if (i == 0)
			nl = min (nl, val[v]);
		else
			nr = max (nr, val[v]);

		dfs (to, nl, nr);

		if (i == 0)
			leftmost[v] = leftmost[to];
		else
			rightmost[v] = rightmost[to];
	}
}

inline pair<int64,int> operator+ (pair<int64,int> a, pair<int64,int> b) {
	return mp (a.fs+b.fs, a.sc+b.sc);
}

void dfs2 (int v, pair<int64,int> cans) {
	if (g[v].empty()) {
		ans[v] = cans;
		return;
	}

	dfs2 (g[v][0], cans + mp (leftmost[g[v][1]], 1));
	dfs2 (g[v][1], cans + mp (rightmost[g[v][0]], 1));
}

bool check_leaf (int x, int v) {
	return x < min_l[v] && x > max_r[v];
}

void solve() {
	vector < pair<int,int> > leaves;
	forn(i,n)
	 	if (g[i].size()) {
			if (val[g[i][0]] > val[g[i][1]])
				swap (g[i][0], g[i][1]);
		}
		else
			leaves.pb (mp (val[i], i));
	sort (all (leaves));

	dfs (root, INF, -INF);
	dfs2 (root, mp (0, 0));

	int m;
	cin >> m;
	forn(i,m) {
		int x;
		scanf ("%d", &x);

		int pos = int (lower_bound (all (leaves), mp (x, -INF)) - leaves.begin());
		
		int sel = -1;
		fore(j,pos-3,pos+3)
			if (j>=0 && j<(int)leaves.size() && check_leaf (x, leaves[j].sc))
				sel = leaves[j].sc;
		if (sel == -1)
			throw;

		printf ("%.20lf\n", double(ans[sel].fs) / ans[sel].sc);
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