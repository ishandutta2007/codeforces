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


const int MAXN = 110;
const int INF = 1000000000;


int n, k;
string s;
int g[26][26], gt[26][26], d[MAXN][MAXN][26];


bool read() {
	int m;
	if (! (cin >> s >> k >> m))  return false;
	n = (int) s.length();
	memset (g, 0, sizeof g);
	memset (gt, 0, sizeof gt);
	for (int i=0; i<m; ++i) {
		char x, y;
		int c;
		scanf (" %c %c %d", &x, &y, &c);
		g[x-'a'][y-'a'] = c;
		gt[y-'a'][x-'a'] = c;
	}
	return true;
}

void gen() {
	n = rand() % 100 + 1;
	s = string (n, 'a');
	for (int i=0; i<n; ++i)
		s[i] = char ('a' + rand() % 26);
	k = rand() % 101;
	for (int i=0; i<26; ++i)
		for (int j=0; j<26; ++j)
			g[i][j] = gt[j][i] = rand() % 2001 - 1000;
}


void solve() {
	for (int pos=0; pos<=n; ++pos)
		for (int kk=0; kk<=k; ++kk)
			for (int c=0; c<26; ++c) {
				int & my = d[pos][kk][c];
				my = -INF;

				int kkk = kk;
				if (c != s[pos] - 'a')
					--kkk;

				if (kkk < 0)
					continue;
				if (pos == 0) {
					my = 0;
					continue;
				}

				for (int pc=0; pc<26; ++pc)
					my = max (my, gt[c][pc] + d[pos-1][kkk][pc]);
			}

	int ans = -INF;
	for (int c=0; c<26; ++c)
		ans = max (ans, d[n-1][k][c]);

	cout << ans << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	/*
	for(;;) {
		gen();
		solve();
		cerr << 'x';
	}
	*/

	while (read())
		solve();

}