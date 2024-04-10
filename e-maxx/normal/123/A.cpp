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


string s;


bool read() {
	return !! (cin >> s);
}


void solve() {
	int n = (int) s.length();

	int sz = 0;
	int one = 1;
	vector<int> vsz, vone;
	vone.pb (1);
	fore(i,2,n+1) {
		bool pr = true;
		for (int j=2; j<i; ++j)
			if (i % j == 0) {
				pr = false;
				break;
			}

		if (!pr || i * 2 <= n) {
			vsz.pb (i);
			++sz;
		}
		else {
			vone.pb (i);
			++one;
		}
	}

	vector<int> c (26);
	forn(i,n)
		++c[s[i]-'a'];
	forn(i,26)
		if (c[i] >= sz) {
			c[i] -= sz;

			string ans (n, '_');
			forn(j,sz)
				ans[vsz[j]-1] = char ('a' + i);
			forn(j,one)
				forn(k,26)
					if (c[k]) {
						--c[k];
						ans[vone[j]-1] = char ('a' + k);
						break;
					}
			cout << "YES\n" << ans << endl;

			return;
		}

	puts ("NO");
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