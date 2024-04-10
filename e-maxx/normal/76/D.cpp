#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
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
#define mp  make_pair
#define fs  first
#define sc  second
#define pb  push_back


int test;
typedef unsigned long long ll;
ll a, b, one = 1;
string sa, sb;


bool read() {
	return cin >> a >> b;
}


int d[100][2];
bool us[100][2];
pair<ll,ll> d2[100][2];

int get_d (int pos, int per) {
	if (pos == 64)
		return true;

	int & my = d[pos][per];
	if (my != -1)  return my;

	my = false;
	if (sb[pos] == '1') {
		int cur = (1 + per) % 2;
		if (cur != sa[pos]-'0')
			return my = false;
		return my = get_d (pos+1, (1 + per) / 2);
	}
	else {
		if (per == sa[pos]-'0') {
			if (get_d (pos+1, 0))
				return my = true;
			if (get_d (pos+1, 1))
				return my = true;
		}
	}

	return my;
}

pair<ll,ll> restore (int pos, int per) {
	if (us[pos][per])
		return d2[pos][per];

	if (pos == 64)
		return mp (ll(0), ll(0));

	us[pos][per] = true;
	pair<ll,ll> & my = d2[pos][per];

	if (sb[pos] == '1') {
		pair<ll,ll> res = restore (pos+1, (1 + per) / 2);
		res.sc += one << pos;
		return my = res;
	}
	else {
		if (per == sa[pos]-'0') {
			vector < pair<ll,ll> > v;
			if (get_d (pos+1, 0))
				v.pb (restore (pos+1, 0));
			if (get_d (pos+1, 1)) {
				v.pb (restore (pos+1, 1));
				v.back().fs += one << pos;
				v.back().sc += one << pos;
			}
			sort (all (v));
			return my = v[0];
		}
	}

	throw;
}


void solve() {
	sa = sb = "";
	forn(i,64) {
		sa += char ('0' + (a % 2));
		a /= 2;
	}
	forn(i,64) {
		sb += char ('0' + (b % 2));
		b /= 2;
	}

	memset (d, -1, sizeof d);
	if (! get_d (0, 0))
		puts ("-1");
	else {
		memset (us, 0, sizeof us);
		pair<ll,ll> ans = restore (0, 0);
		cout << ans.fs << ' ' << ans.sc << endl;

	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read()) {
		++test;
		solve();
	}

}