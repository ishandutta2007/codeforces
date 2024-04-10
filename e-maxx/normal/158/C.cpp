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


int n;


bool read() {
	return !! (cin >> n);
}


char buf[1000000];

string simplify (string s) {
  if (s == "" || s[0] != '/')  throw;
  s += '/';

  vector<string> v;
  int prev = -1;
  forn(i,s.length())
    if (s[i] == '/') {
      string tok = s.substr (prev+1, i-prev-1);
      if (tok != "") {
        if (tok == "..")
          v.pop_back();
        else
          v.pb (tok);
      }
      prev = i;
    }

  string res = "/";
  forn(i,v.size())
    res += v[i] + "/";
  return res;
}

void solve() {
  string dir = "/";
  forn(i,n) {
    scanf (" %s", buf);
    
    if (buf[0] == 'c') {
      scanf (" %s", buf);
      if (buf[0] == '/')
        dir = buf;
      else
        dir += buf;
      dir = simplify (dir);
    }
    else if (buf[0] == 'p') {
      puts (dir.c_str());
    }
    else
      throw;
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