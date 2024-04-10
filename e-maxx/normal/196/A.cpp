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


const int MAXN = 110000;


char buf[MAXN];
int n;
string s;


bool read() {
	if (scanf ("%s", buf) != 1)
		return false;
	s = buf;
	n = (int) s.length();
	return true;
}


int nxt[MAXN][26];


void solve() {
	memset (nxt, -1, sizeof nxt);
	ford(i,n)
		forn(c,26)
			nxt[i][c] = s[i]-'a'==c ? i : nxt[i+1][c];

	string ans;
	for (int pos=0; ; ) {
		int mx = -1;
		forn(c,26)
			if (nxt[pos][c] != -1)
				mx = c;
		if (mx == -1)
			break;
		ans += char (mx + 'a');
		pos = nxt[pos][mx] + 1;
	}
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