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
string s;
bool g[26][26];


bool read() {
  if (scanf (" %s", buf) != 1)
    return false;
  s = buf;

  memset (g, 0, sizeof g);
  int m;
  cin >> m;
  forn(i,m) {
    char a, b;
    cin >> a >> b;
    g[a-'a'][b-'a'] = true;
    g[b-'a'][a-'a'] = true;
  }

	return true;
}


int last[26], d[MAXN];


void solve() {
  memset (last, -1, sizeof last);
  int ans = 0;
  forn(i,s.length()) {
    d[i] = 1;
    forn(prev,26)
      if (last[prev] != -1 && ! g[prev][s[i]-'a'])
        d[i] = max (d[i], 1 + d[last[prev]]);
    last[s[i]-'a'] = i;
    ans = max (ans, d[i]);
  }

  cout << (int) s.length() - ans << endl;
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