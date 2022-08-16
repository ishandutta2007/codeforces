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

const int N = 1e3 + 10;

bool reach[N][N], seen[N][N];

void dfs(int x, int y);
int get_edge_type(int sx, int sy, int tx, int ty);

int main() {
	fast_cin();
	int n; cin >> n;
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			reach[i][j] = (get_edge_type(i, j, ax, ay) == -1);
		}
	}
	dfs(bx, by);
	if (seen[cx][cy]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

void dfs(int x, int y) {
	if (seen[x][y] or !reach[x][y]) {
		return;
	}
	seen[x][y] = true;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			dfs(x + i, y + j);
		}
	}
}

int get_edge_type(int sx, int sy, int tx, int ty) {
    if (sx == tx) {
        if (sy < ty) {
            return 0;
        } else {
            return 1;
        }
    } else if (sy == ty) {
        if (sx < tx) {
            return 2;
        } else {
            return 3;
        }
    } else if (sx + sy == tx + ty) {
        if (sx < tx) {
            return 4;
        } else {
            return 5;
        }
    } else if (sx - sy == tx - ty) {
        if (sx < tx) {
            return 6;
        } else {
            return 7;
        }
    } else {
        return -1;
    }
}