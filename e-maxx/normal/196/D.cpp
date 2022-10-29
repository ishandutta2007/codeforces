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


const int MAXN = 410000;


int d, n;
char buf[MAXN];
string s;


bool read() {
	if (! (cin >> d))
		return false;
	scanf (" %s", buf);
	s = buf;
	n = (int) s.length();
	return true;
}


int64 t1[MAXN], t2[MAXN], pw[MAXN];
string ans;

inline void fenw_add (int64 t[], int i, int64 val) {
	for (; i<n; i|=i+1)
		t[i] += val;
}

inline int64 fenw_sum (int64 t[], int r) {
	int64 res = 0;
	for (; r>=0; r=(r&(r+1))-1)
		res += t[r];
	return res;
}

inline int64 fenw_sum (int64 t[], int l, int r) {
	return fenw_sum (t, r) - fenw_sum (t, l-1);
}

inline void add_ch (int i, char c) {
	fenw_add (t1, i, c * pw[i]);
	fenw_add (t2, i, c * pw[n-1-i]);
}

inline bool is_bad (int i) {
	int d = ::d;
	forn(iter,2) {
		if (i-d+1 < 0)
			break;
		if (fenw_sum (t1, i-d+1, i) * pw[n-1-(i-d+1)] == fenw_sum (t2, i-d+1, i) * pw[i])
			return true;
		++d;
	}
	return false;
}

bool rec (int pos, bool eq) {
	if (pos == n)
		return !eq;

	char min_c = eq ? s[pos] : 'a';
	for (char c=min_c; c<='z'; ++c) {
		add_ch (pos, c);
		ans += c;
		if (! is_bad (pos) && rec (pos+1, eq && c == s[pos]))
			return true;
		add_ch (pos, -c);
		ans.erase (ans.length() - 1);
	}
	return false;
}

void solve() {
	memset (t1, 0, sizeof t1);
	memset (t2, 0, sizeof t2);
	ans = "";
	if (! rec (0, true))
		puts ("Impossible");
	else
		puts (ans.c_str());
}


int main() {
	pw[0] = 1;
	fore(i,1,MAXN)
		pw[i] = pw[i-1] * 313;

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