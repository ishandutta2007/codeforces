/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 10, D = 4;

char a[N][N];
int c[N][N];
int dx[D] = {0, 0, -1, 1};
int dy[D] = {-1, 1, 0, 0};

void dfs(int i, int j, int n, int m, int col);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> (a[i] + 1);
	}
	int nxt = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == '#' and !c[i][j]) {
				dfs(i, j, n, m, nxt++);
			}
		}
	}
	bool ok = true, e_row = false, e_col = false;
	string bad = "#.#A";
	for (int i = 1; i <= n; ++i) {
		int p = 0;
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == bad[p]) {
				++p;
			}
		}
		ok = (ok and p < 3);
		e_row = (e_row or p == 0);
	}
	for (int i = 1; i <= m; ++i) {
		int p = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[j][i] == bad[p]) {
				++p;
			}
		}
		ok = (ok and p < 3);
		e_col = (e_col or p == 0);
	}
	ok = (ok and (e_row xor e_col) == 0);
	if (ok) {
		cout << nxt - 1 << '\n';
	} else {
		cout << -1 << '\n';
	}
}

void dfs(int i, int j, int n, int m, int col) {
	c[i][j] = col;
	for (int d = 0; d < D; ++d) {
		int x = i + dx[d];
		int y = j + dy[d];
		if (1 <= x and x <= n and 1 <= y and y <= m and a[x][y] == '#' and c[x][y] != col) {
			dfs(x, y, n, m, col);
		}
	}
}