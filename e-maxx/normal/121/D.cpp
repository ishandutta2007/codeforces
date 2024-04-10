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


const int MAXN = 110000;

vector<int64> v;
int n;
int64 k;
pair<int64,int64> a[MAXN];
int64 mx;


bool read() {
	if (! (cin >> n >> k))
		return false;
	forn(i,n)
		scanf ("%I64d%I64d", &a[i].fs, &a[i].sc);
	return true;
}


vector<int64> dl, dr;

void build_dl() {
	vector<int64> e (n);
	forn(i,n)
		e[i] = a[i].sc;
	sort (all (e));
	
	dl.resize (v.size());
	int ptr = 0;
	int64 d = 0;
	double dd = 0;
	forn(i,v.size()) {
		if (ptr) {
			d += ptr * (v[i] - v[i-1]);
			dd += ptr * 1.0 * (v[i] - v[i-1]);
		}
		while (ptr < n && e[ptr] <= v[i]) {
			d += v[i] - e[ptr];
			dd += v[i] - e[ptr++];
		}
		
		if (dd > 1.5E18)
			d = INF64 + 100;
		d = min (d, INF64 + 100);

		dl[i] = d;
	}
}

void build_dr() {
	vector<int64> e (n);
	forn(i,n)
		e[i] = a[i].fs;
	sort (all (e));
	
	dr.resize (v.size());
	int ptr = n-1;
	int64 d = 0;
	double dd = 0;
	ford(i,v.size()) {
		if (ptr != n-1) {
			d += (n-1 - ptr) * (v[i+1] - v[i]);
			dd += (n-1 - ptr) * 1.0 * (v[i+1] - v[i]);
		}
		while (ptr >= 0 && e[ptr] >= v[i]) {
			d += e[ptr] - v[i];
			dd += e[ptr--] - v[i];
		}
		
		if (dd > 1.5E18)
			d = INF64 + 100;
		d = min (d, INF64 + 100);

		dr[i] = d;
	}
}

int64 calc (int l, int r) {
	if (v[r] - v[l] > mx)
		return INF64 + 100;
	return dl[r] + dr[l];
}

void solve() {
	build_dl();
	build_dr();

	mx = INF64;
	forn(i,n)
		mx = min (mx, a[i].sc - a[i].fs);
	
	int ans = 0;
	forn(i,v.size()) {
		int lt = i,
			rt = (int)v.size() - 1;
		while (lt < rt) {
			int mid = (lt + rt + 1) / 2;
			if (calc (i, mid) <= k)
				lt = mid;
			else
				rt = mid - 1;
		}

		if (calc (i, lt) <= k)
			ans = max (ans, lt - i + 1);
	}
	cout << ans << endl;
}


void rec (int64 num, int pos, int len) {
	if (pos == len)
		v.pb (num);
	else {
		rec (num * 10 + 4, pos + 1, len);
		rec (num * 10 + 7, pos + 1, len);
	}
}


int main() {
	for (int i=1; i<=18; ++i)
		rec (0, 0, i);

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