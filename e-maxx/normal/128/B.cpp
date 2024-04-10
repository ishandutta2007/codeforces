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


const int MAXLEN = 110000;
const int K = 26;


struct state {
	int length, link, cnt;
	int next[K];
	bool termimal;
	int64 d;
};
state st[MAXLEN*2-1];
int sz, last;

void init() {
	sz = last = 0;
	st[0].length = 0;
	st[0].link = -1;
	st[0].cnt = 0;
	memset (st[0].next, -1, sizeof st[0].next);
	++sz;
}

void sa_extend (char c) {
	int nlast = sz++;
	st[nlast].length = st[last].length + 1;
	st[nlast].cnt = 1;
	memset (st[nlast].next, -1, sizeof st[nlast].next);
	int p;
	for (p=last; p!=-1 && st[p].next[c]==-1; p=st[p].link)
		st[p].next[c] = nlast;
	if (p == -1)
		st[nlast].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].length + 1 == st[q].length)
			st[nlast].link = q;
		else {
			int clone = sz++;
			st[clone].length = st[p].length + 1;
			memcpy (st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link = st[q].link;
			st[clone].cnt = 0;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[nlast].link = clone;
		}
	}
	last = nlast;
}


char buf[MAXLEN];
string s;
int k;

bool read() {
	if (scanf (" %s", buf) != 1)
		return false;
	s = buf;
	cin >> k;
	return true;
}


string ans;

int64 get_d (int v) {
	int64 & my = st[v].d;
	if (my != -1)  return my;
	my = st[v].cnt;

	forn(i,26)
		if (st[v].next[i] != -1)
			my += get_d (st[v].next[i]);

	return my;
}

void restore (int v, int k) {
	int here = v ? st[v].cnt : 0;
	if (here >= k)
		return;
	k -= here;

	forn(c,26)
		if (st[v].next[c] != -1) {
			int to = st[v].next[c];
			int64 cc = get_d (to);
			if (cc >= k) {
				ans += char ('a' + c);
				return restore (to, k);
			}
			k -= (int) cc;
		}

	if (v == 0) {
		puts ("No such line.");
		exit(0);
	}
	throw;
}

void solve() {
	init();
	forn(i,s.length())
		sa_extend (s[i] - 'a');

	vector < pair<int,int> > vec;
	forn(i,sz)
		vec.pb (mp (st[i].length, i));
	sort (all (vec));
	ford(i,vec.size()) {
		int v = vec[i].sc;
		st[st[v].link].cnt += st[v].cnt;
	}

	forn(i,sz)
		st[i].d = -1;
	ans = "";
	restore (0, k);

	puts (ans.c_str());
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