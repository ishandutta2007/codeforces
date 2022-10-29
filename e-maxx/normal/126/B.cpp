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


const int MAXN = 1100000;

char buf[MAXN];


bool read() {
	return scanf (" %s", buf) == 1;
}


bool d[MAXN];

void solve() {
	string s = buf;
	vector<int> p (s.length());
	fore(i,1,s.length()) {
		p[i] = p[i-1];
		while (p[i] && s[i] != s[p[i]])
			p[i] = p[p[i]-1];
		if (s[i] == s[p[i]])
			++p[i];
	}

	memset (d, 0, sizeof d);
	fore(i,1,s.length()-1) {
		int cur = p[i];
		if (cur == i+1)
			cur = p[cur-1];
		d[cur] = true;
	}

	ford(i,s.length()+1)
		if (i && d[i])
			d[p[i-1]] = true;

	int cur = p[s.length()-1];
	while (cur && !d[cur])
		cur = p[cur-1];

	if (! cur)
		puts ("Just a legend");
	else {
		buf[cur] = 0;
		puts (buf);
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