#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 250;

int n, m;
bool a[MAXN][MAXN];

int dfs (int x, int y) {
	int res = 1;
	a[x][y] = false;
	for (int dx=-1; dx<=1; ++dx)
		for (int dy=-1; dy<=1; ++dy)
			if (dx || dy) {
				int nx = x + dx,  ny = y + dy;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny])
					res += dfs (nx, ny);
			}
	return res;
}

int type1 (int x, int y) {
	int len1 = 1;
	while (y+len1 < m && a[x][y+len1])
		++len1;
	int len2 = 1;
	while (x+len2 < n && a[x+len2][y])
		++len2;
	int res = 0,  per = 0;
	if (len1 == len2) {
		int len = len1 - 1;
		bool ok = true;
		for (int cx=x; cx<=x+len; ++cx)
			ok &= a[cx][y+len];
		for (int cy=y; cy<=y+len; ++cy)
			ok &= a[x+len][cy];
		res = ok;
		per = 4 * len;
	}

	if (dfs (x, y) != per)
		return 0;
	return res;
}

int type2 (int x, int y) {
	int len1 = 1;
	while (x+len1 < n && y+len1 < m && a[x+len1][y+len1])
		++len1;
	int len2 = 1;
	while (x+len2 < n && y-len2 >= 0 && a[x+len2][y-len2])
		++len2;
	int res = 0,  per = 0;
	if (len1 == len2) {
		int len = len1 - 1;
		bool ok = true;
		for (int i=0; i<=len; ++i)
			ok &= a[x+len+i][y+len-i];
		for (int i=0; i<=len; ++i)
			ok &= a[x+len+i][y-len+i];
		res = ok;
		per = 4 * len;
	}

	if (dfs (x, y) != per)
		return 0;
	return res;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	for (int tt=0; tt<t; ++tt) {
		scanf ("%d%d", &n, &m);
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j) {
				char tmp;
				scanf (" %c", &tmp);
				a[i][j] = tmp != '0';
			}

		int ans = 0;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (a[i][j]) {
					if (j+1 < m && a[i][j+1])
						ans += type1 (i, j);
					else if (i+1 < n && j+1 < m && a[i+1][j+1])
						ans += type2 (i, j);
					else
						dfs (i, j);
				}
		printf ("%d\n", ans);
	}

}