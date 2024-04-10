#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
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
const int64 INF64 = (int64) 4E18;
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


const int MAXN = 210;
const int MAXE = 51000;


int test;
int n, m;
int64 G, S;

struct edge {
	int a, b;
	int64 g, s;

	bool operator< (const edge & e) const {
		return mp(g,s) < mp(e.g,e.s);
	}
};

edge e[MAXE];
vector<int> g[MAXN];
int par[MAXN], pv[MAXN];
bool u[MAXN];


bool read() {
	if (! (cin >> n >> m >> G >> S))
		return false;
	forn(i,m) {
		int g, s;
		scanf ("%d%d%d%d", &e[i].a, &e[i].b, &g, &s);
		--e[i].a;
		--e[i].b;
		e[i].g = g;
		e[i].s = s;
	}
	return true;
}


void dfs (int v) {
	u[v] = true;
	forn(i,g[v].size()) {
		int id = g[v][i];
		int to = e[id].a;
		if (!u[to]) {
			par[to] = id;
			pv[to] = v;
			dfs (to);
		}
		to = e[id].b;
		if (!u[to]) {
			par[to] = id;
			pv[to] = v;
			dfs (to);
		}
	}
}

inline void del_e (int id) {
	int a = e[id].a,
		b = e[id].b;
	g[a].erase (find (all (g[a]), id));
	g[b].erase (find (all (g[b]), id));
}

void solve() {
	sort (e, e+m);
	forn(i,n)
		g[i].clear();

	int64 ans = INF64;

	int comps = n;
	forn(i,m) {
		int a = e[i].a;
		int b = e[i].b;
		if (a == b)  continue;

		forn(j,n) {
			u[j] = false;
			par[j] = -1;
		}
		dfs (a);

		if (!u[b]) {
			g[a].pb (i);
			g[b].pb (i);
			--comps;
		}
		else {
			vector<int> lst;
			for (int v=b; v!=a; ) {
				int id = par[v];
				lst.pb (id);
				v = pv[v];
			}

			int sel = -1;
			forn(j,lst.size())
				if (sel == -1 || e[lst[j]].s > e[sel].s)
					sel = lst[j];
			if (e[sel].s > e[i].s) {
				del_e (sel);
				g[a].pb (i);
				g[b].pb (i);
			}
		}

		if (comps == 1) {
			int64 max_s = -INF64;
			forn(v,n)
				forn(j,g[v].size())
					max_s = max (max_s, e[g[v][j]].s);

			ans = min (ans, max_s * S + e[i].g * G);
		}
	}

	if (ans == INF64)
		ans = -1;
	cout << ans << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read()) {
		++test;
		solve();
	}

}