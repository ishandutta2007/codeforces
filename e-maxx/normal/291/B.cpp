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


string s;


bool read() {
	return !!getline(cin, s);
}


void solve() {
    s = ' ' + s + ' ';

    string token;
    forn(i,s.length()) {
        if (s[i] == ' ') {
            if (!token.empty()) {
                printf("<%s>\n", token.c_str());
                token = "";
            }
        }
        else if (s[i] == '"') {
            size_t end = s.find('"', i + 1);
            printf("<%s>\n", s.substr(i + 1, end - i - 1).c_str());
            i = end;
        }
        else
            token += s[i];
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