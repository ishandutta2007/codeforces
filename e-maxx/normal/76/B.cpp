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
const int64 INF64 = (int64) 1E18;
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


const int MAXN = 110000;


int test;
int n, m, ya, yb, x[MAXN], y[MAXN];
vector<int> mouse[MAXN];
int deg[MAXN], dist[MAXN];
vector<int> che[MAXN];
bool in_ans[MAXN];

struct cmp {
	bool operator() (int a, int b) {
		if (deg[a] != deg[b])
			return deg[a] < deg[b];
		if (dist[a] != dist[b])
			return dist[a] < dist[b];
		if (x[a] != x[b])
			return x[a] < x[b];
		return a < b;
	}
};

set<int,cmp> q;


bool read() {
	if (! (cin >> n >> m >> ya >> yb))
		return false;
	forn(i,n)
		scanf ("%d", &x[i]);
	forn(i,m)
		scanf ("%d", &y[i]);
	return true;
}


void rebuild (int id, int to) {
	q.erase (id);

	forn(i,mouse[id].size())
		if (mouse[id][i] == to) {
			mouse[id].erase (mouse[id].begin() + i);
			break;
		}
	deg[id] = (int) mouse[id].size();

	if (deg[id] == 0 || in_ans[id])
		return;
	q.insert (id);
}

void solve() {
	if (m == 0) {
		printf ("%d\n", n);
		return;
	}

	forn(i,m) {
		che[i].clear();
		mouse[i].clear();
	}
	q.clear();
	memset (in_ans, 0, sizeof in_ans);

	forn(i,n) {
		deg[i] = 0;
		int id = int (lower_bound (y, y+m, x[i]) - y);

		vector < pair<int,int> > v;
		if (id != m)
			v.pb (mp (abs (x[i] - y[id]), id));
		if (id > 0)
			v.pb (mp (abs (x[i] - y[id-1]), id-1));
		sort (all (v));
		if (v.size()==2 && v[1].fs > v[0].fs)
			v.pop_back();

		mouse[i].clear();
		dist[i] = v[0].fs;

		forn(j,v.size()) {
			che[v[j].sc].pb (i);
			mouse[i].pb (v[j].sc);
		}
		deg[i] = (int) mouse[i].size();

		//cerr << mouse[i].size() << endl;
	}

	forn(i,n)
		q.insert (i);

	forn(i,n) {
		if (q.empty())  break;

		int id = *q.begin();
		q.erase (q.begin());

		if (deg[id] == 0 || in_ans[id])
			continue;

		int to = mouse[id][0];
		forn(j,che[to].size()) {
			int k = che[to][j];
			if (dist[k] != dist[id])
				rebuild (k, to);
			else {
				q.erase (k);
				in_ans[k] = true;
			}
		}
	}

	cout << n - count (in_ans, in_ans+n, true) << endl;
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