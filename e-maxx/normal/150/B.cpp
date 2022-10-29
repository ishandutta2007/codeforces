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


const int MAXN = 2010;
const int64 MOD = INF + 7;


int n, m, k;


bool read() {
	return !! (cin >> n >> m >> k);
}


int dsu[MAXN];
bool u[MAXN];

int get (int v) {
	return v==dsu[v] ? v : dsu[v] = get (dsu[v]);
}

void unite (int a, int b) {
	a = get(a),  b = get(b);
	if (a != b)
		dsu[a] = b;
}

void solve() {
	forn(i,n)
		dsu[i] = i;

	forn(i,n-k+1)
		forn(j,k)
			unite (i+j, i+k-1-j);

	memset (u, 0, sizeof u);
	forn(i,n)
		u[get(i)] = true;

	int64 ans = 1;
	forn(i,n)
		if (u[i])
			ans = (ans * m) % MOD;
	cout << ans << endl;
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