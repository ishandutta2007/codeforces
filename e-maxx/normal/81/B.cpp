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


char buf[1000];


bool read() {
	return gets (buf) != 0;
}


void solve() {
	string s = buf;
	string t;
	vector<string> v;
	forn(i,s.length()) {
		if (s[i] == ',') {
			v.pb (t);
			t = "";
		}
		else if (isdigit (s[i])) {
			if (t!="" && !isdigit(t[0])) {
				v.pb (t);
				t = "";
			}
		}
		else if (s[i] == '.') {
			if (t!="" && t[0]!='.' || t=="...") {
				v.pb (t);
				t = "";
			}
		}
		else {
			v.pb (t);
			t = "";
			continue;
		}
		t += s[i];
	}
	v.pb (t);

	vector<string> vv;
	forn(i,v.size())
		if (v[i] != "")
			vv.pb (v[i]);
	v = vv;

	vector<char> space (v.size() + 1);
	forn(i,v.size()) {
		if (v[i] == "," && i != (int)v.size()-1)
			space[i+1] = true;
		if (v[i] == "..." && i != 0)
			space[i] = true;
		if (isdigit (v[i][0]) && i+1 < (int)v.size() && isdigit (v[i+1][0]))
			space[i+1] = true;
	}

	string ans;
	forn(i,v.size()) {
		if (space[i])
			ans += " ";
		ans += v[i];
	}
	if (space.back())
		ans += " ";

	puts (ans.c_str());
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}