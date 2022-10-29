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
const int64 INF64 = (int64) 2E18;
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


const int MAXN = 210;


int n, m, p[MAXN][MAXN];
int64 k;


bool read() {
	if (! (cin >> n >> m >> k))
		return false;
	forn(i,n)
		forn(j,m)
			scanf ("%d", &p[i][j]);
	return true;
}


int prior[MAXN];
pair<int,int> vec[MAXN];
string pat;
int cu, u[MAXN][MAXN];
int64 d[MAXN][MAXN];

int64 get_d (int pos, int bal) {
	if (pos == (int) pat.length())
		return bal==0;

	int & myu = u[pos][bal];
	int64 & my = d[pos][bal];
	if (myu == cu)  return my;
	my = 0;
	myu = cu;

	if (pat[pos] != ')')
		my += get_d (pos+1, bal+1);
	if (bal && pat[pos] != '(')
		my += get_d (pos+1, bal-1);

	my = min (my, INF64);
	return my;
}

int64 calc() {
	++cu;
	return get_d (0, 0);
}

void rec (int pos1, int64 k) {
	if (pos1 == n+m-1) {
		forn(i,n) {
			forn(j,m)
				printf ("%c", pat[i+j]);
			puts("");
		}
		return;
	}

	int pos = vec[pos1].sc;

	pat[pos] = '(';
	int64 cur = calc();
	if (cur >= k)
		return rec (pos1+1, k);
	k -= cur;
	
	pat[pos] = ')';
	if (calc() < k)
		throw;
	return rec (pos1+1, k);
}

void solve() {
	forn(i,n+m-1)
		prior[i] = INF;
	forn(i,n)
		forn(j,m)
			prior[i+j] = min (prior[i+j], p[i][j]);
	forn(i,n+m-1)
		vec[i] = mp (prior[i], i);
	sort (vec, vec+n+m-1);

	pat = string (n+m-1, '?');
	rec (0, k);
}



int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read()) {
		solve();
		puts("");
	}
#else
	if (!read())  throw;
	solve();
#endif
}