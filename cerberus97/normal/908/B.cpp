/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 100;

string path;
char s[N][N];
vector<pii> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool solve(int n, int m);
bool valid(int x, int y, int n, int m);

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> (s[i] + 1);
	}

	cin >> path;
	int ans = 0, ctr = 24;
	while(ctr--) {
		next_permutation(dir.begin(), dir.end());
		if (solve(n, m)) {
			++ans;
		}
	}

	cout << ans << endl;
}

bool solve(int n, int m) {
	int sx, sy, tx, ty;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if (s[i][j] == 'E') {
				tx = i;
				ty = j;
			}
		}
	}

	for (auto &i : path) {
		sx += dir[i - '0'].first;
		sy += dir[i - '0'].second;
		if (!valid(sx, sy, n, m)) {
			return false;
		} else if (sx == tx and sy == ty) {
			return true;
		}
	}

	return false;
}

bool valid(int x, int y, int n, int m) {
	return (x > 0 and x <= n and y > 0 and y <= m and s[x][y] != '#');
}