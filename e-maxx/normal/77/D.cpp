#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;


#define forn(i,n)  for (int i=0; i<int(n); ++i)

const int MAXN = 300;
const int MOD = 1000*1000*1000+7;


int n, m;
string a[MAXN][MAXN];
char buf[MAXN*4];
string s[MAXN*4];
int d[MAXN];
set<string> horiz, vert;


bool read() {
	if (! (cin >> n >> m))
		return false;
	
	forn(i,n*4+1) {
		scanf (" %s", buf);
		s[i] = buf;
	}
	forn(i,n)
		forn(j,m) {
			int row = 1 + i*4;
			int col = 1 + j*4;
			a[i][j] = s[row].substr(col,3) + s[row+1].substr(col,3) + s[row+2].substr(col,3);
		}
	
	return true;
}


bool good_col_1 (int j) {
	if (n % 2)
		return false;
	forn(i,n)
		if (! vert.count (a[i][j]))
			return false;
	return true;
}

int good_col_2 (int j) {
	static int d2[MAXN][2];
	forn(i,n+1)
		forn(t,2)
			d2[i][t] = 0;

	d2[0][0] = 1;
	forn(i,n)
		forn(t,2) {
			d2[i][t] %= MOD;
			if (horiz.count (a[i][j]) && horiz.count (a[i][j+1]))
				d2[i+1][1] += d2[i][t];
			if (i+1<n && vert.count (a[i][j]) && vert.count (a[i][j+1]) && vert.count (a[i+1][j]) && vert.count (a[i+1][j+1]))
				d2[i+2][t] += d2[i][t];
		}
	return d2[n][1] % MOD;
}


void solve() {
	forn(j,m) {
		d[j] = 0;
		if (good_col_1 (j))
			d[j] += (j ? d[j-1] : 1);
		if (j>=1) {
			int cur = good_col_2 (j-1);
			d[j] += (j-1 ? d[j-2] : 1) * 1ll * cur % MOD;
		}
		if (d[j] >= MOD)
			d[j] -= MOD;
	}
	cout << d[m-1] << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	vert.insert ("..." "..." "...");
	vert.insert ("..." ".O." "...");
	vert.insert ("..O" "..." "O..");
	vert.insert ("..O" ".O." "O..");
	vert.insert ("O.O" "..." "O.O");
	vert.insert ("O.O" ".O." "O.O");
	vert.insert ("O.O" "O.O" "O.O");

	horiz.insert ("..." "..." "...");
	horiz.insert ("..." ".O." "...");
	horiz.insert ("O.." "..." "..O");
	horiz.insert ("O.." ".O." "..O");
	horiz.insert ("O.O" "..." "O.O");
	horiz.insert ("O.O" ".O." "O.O");
	horiz.insert ("OOO" "..." "OOO");

	while (read())
		solve();

}