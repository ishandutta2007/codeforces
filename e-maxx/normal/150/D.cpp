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
const int INF = (int) 1E8;
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


const int MAXN = 160;


int n, cost[MAXN];
string s;


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n) {
		cin >> cost[i+1];
		if (cost[i+1] == -1)
			cost[i+1] = -INF;
	}
	cin >> s;
	return true;
}


int d[MAXN][MAXN][MAXN];
bool u[MAXN][MAXN][MAXN];

int get_d (int l, int r, int len) {
	if (l > r)  return cost[len];
	if (l == r)  return max (cost[len] + cost[1], cost[len+1]);

	int & my = d[l][r][len];
	bool & myu = u[l][r][len];
	if (myu)  return my;
	myu = true;
	my = -INF;

	if (len != 0)
		my = max (my, cost[len] + get_d (l, r, 0));
	fore(i,l,r)
		my = max (my, get_d (l, i, 0) + get_d (i+1, r, len));
	fore(i,l+1,r+1)
		my = max (my, get_d (i, r, 0) + get_d (l, i-1, len));
	fore(i,l,r+1)
		my = max (my, get_d (l, i-1, 0) + cost[len+1] + get_d (i+1, r, 0));

	if (s[l] == s[r])
		my = max (my, get_d (l+1, r-1, len+2));

	return my;
}

int d2[MAXN];

void solve() {
	memset (u, 0, sizeof u);
	int x = get_d (0, n-1, 0);
	forn(i,n) {
		d2[i] = i ? d2[i-1] : 0;
		forn(j,i+1)
			d2[i] = max (d2[i], get_d (j, i, 0) + (j ? d2[j-1] : 0));
	}

	cout << d2[n-1] << endl;
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