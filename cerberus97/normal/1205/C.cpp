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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 50 + 5;

bool known[2][N][N], val[2][N][N];
bool seen[N][N][N][N], mem[N][N][N][N];
bool ans[2][N][N][N][N];

void dfs(int u, int v, int n, bool known[N][N], bool val[N][N]);
bool ask(int x1, int y1, int x2, int y2);
bool solve(int n);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int x = 0; x < 2; ++x) {
		known[x][0][0] = known[x][n - 1][n - 1] = true;
		val[x][0][0] = 1;
		dfs(0, 0, n, known[x], val[x]);
		known[x][0][1] = true;
		val[x][0][1] = x;
		dfs(0, 1, n, known[x], val[x]);
	}
	int x = solve(n);
	cout << "!" << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << val[x][i][j];
		}
		cout << '\n';
	}
	cout << endl;
}

void dfs(int u, int v, int n, bool known[N][N], bool val[N][N]) {
	assert(known[u][v]);
	for (int cu = 0; cu <= 2; ++cu) {
		int cv = 2 - cu;
		if (u + cu < n and v + cv < n and !known[u + cu][v + cv]) {
			known[u + cu][v + cv] = true;
			val[u + cu][v + cv] = (ask(u, v, u + cu, v + cv) ? val[u][v] : !val[u][v]);
			dfs(u + cu, v + cv, n, known, val);
		}
	}
	for (int cu = 0; cu >= -2; --cu) {
		int cv = -2 - cu;
		if (u + cu >= 0 and v + cv >= 0 and !known[u + cu][v + cv]) {
			known[u + cu][v + cv] = true;
			val[u + cu][v + cv] = (ask(u + cu, v + cv, u, v) ? val[u][v] : !val[u][v]);
			dfs(u + cu, v + cv, n, known, val);
		}
	}
}

bool ask(int x1, int y1, int x2, int y2) {
	if (!seen[x1][y1][x2][y2]) {
		seen[x1][y1][x2][y2] = true;
		cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
		cin >> mem[x1][y1][x2][y2];
	}
	return mem[x1][y1][x2][y2];
}

bool solve(int n) {
	for (int d = 0; d < 2 * n; ++d) {
		for (int x1 = 0; x1 < n; ++x1) {
			for (int x2 = x1; x2 < n; ++x2) {
				for (int y1 = 0; y1 < n; ++y1) {
					int y2 = d - (x2 - x1) + y1;
					if (y2 < y1) {
						continue;
					} else if (y2 >= n) {
						break;
					} else if (d == 0) {
						ans[0][x1][y1][x2][y2] = ans[1][x1][y2][x2][y2] = true;
					} else if (d == 1) {
						for (int t = 0; t < 2; ++t) {
							ans[t][x1][y1][x2][y2] = (val[t][x1][y1] == val[t][x2][y2]);
						}
					} else {
						for (int t = 0; t < 2; ++t) {
							if (val[t][x1][y1] != val[t][x2][y2]) {
								ans[t][x1][y1][x2][y2] = false;
							} else {
								ans[t][x1][y1][x2][y2] |= ans[t][x1 + 1][y1][x2 - 1][y2];
								ans[t][x1][y1][x2][y2] |= ans[t][x1 + 1][y1][x2][y2 - 1];
								ans[t][x1][y1][x2][y2] |= ans[t][x1][y1 + 1][x2 - 1][y2];
								ans[t][x1][y1][x2][y2] |= ans[t][x1][y1 + 1][x2][y2 - 1];
							}
						}
						if (ans[0][x1][y1][x2][y2] != ans[1][x1][y1][x2][y2]) {
							return (ask(x1, y1, x2, y2) == ans[1][x1][y1][x2][y2]);
						}
					}
				}
			}
		}
	}
	assert(0);
}