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


const int MOD = INF + 9;
const int K = 4;
const string STR = "ACGT";


struct vertex {
	int next[K], go[K], p, link, pch, end, d_end;

	vertex() {
		memset (next, -1, sizeof next);
		memset (go, -1, sizeof go);
		p = link = pch = d_end = -1;
		end = 0;
	}
};

vertex t[200];
int sz;
 
void add_string (const string & s) {
	int v = 0;
	forn(i,s.length()) {
		int c = (int) STR.find (s[i]);
		if (t[v].next[c] == -1) {
			t[sz].p = v;
			t[sz].pch = c;
			t[v].next[c] = sz++;
		}
		v = t[v].next[c];
	}
	t[v].end = max (t[v].end, (int)s.length());
}
 
int get_link (int v) {
	int go (int v, int c);
	if (t[v].link == -1)
		if (v == 0 || t[v].p == 0)
			t[v].link = 0;
		else
			t[v].link = go (get_link (t[v].p),
					t[v].pch);
	return t[v].link;
}
 
int go (int v, int c) {
	if (t[v].go[c] == -1)
		if (t[v].next[c] != -1)
			t[v].go[c] = t[v].next[c];
		else
			t[v].go[c] = v==0 ? 0
					: go (get_link (v), c);
	return t[v].go[c];
}

int get_end (int v) {
	int & my = t[v].d_end;
	if (my != -1)  return my;
	
	my = t[v].end;
	int to = get_link (v);
	if (to != v)  my = max (my, get_end (to));
	return my;
}


int n, m;
string s[10];

bool read() {
	if (! (cin >> n >> m))
		return false;
	forn(i,m)
		cin >> s[i];
	return true;
}


int d[1100][15][200];

int get_d (int pos, int start, int v) {
	if (pos-start > 11)  return 0;

	int & my = d[pos][pos-start][v];
	if (my != -1)  return my;
	my = 0;

	int need = pos - start;
	if (need && get_end (v) >= need)
		return my = get_d (pos, pos, v);
	if (pos == n && start == n)
		return my = 1;
	if (pos == n)
		return my = 0;

	forn(ch,4) {
		int nv = go (v, ch);
		my += get_d (pos+1, start, nv);
		if (my >= MOD)
			my -= MOD;
	}

	return my;
}


void solve() {
	forn(i,200)
		t[i] = vertex();
	sz = 1;

	forn(i,m)
		add_string (s[i]);

	memset (d, -1, sizeof d);
	int ans = get_d (0, 0, 0);
	printf ("%d\n", ans);
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}