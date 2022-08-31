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

const int N = 1000, M = N + 10, ROOKS = 666, R = ROOKS + 10, inf = 1e9 + 42;

bool have[M][M];
int ctr[2][2];
int px[R], py[R];

void move_multiple(int &sx, int &sy, int tx, int ty);
void move(int x, int y);

int main() {
	fast_cin();
	int sx, sy;
	cin >> sx >> sy;
	for (int i = 1; i <= ROOKS; ++i) {
		int x, y;
		cin >> x >> y;
		have[x][y] = true;
		px[i] = x;
		py[i] = y;
	}
	move_multiple(sx, sy, 500, 500);
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			if (have[i][j]) {
				++ctr[i < sx][j < sy];
			}
		}
	}
	int mn = inf, tx, ty;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (ctr[i][j] < mn) {
				mn = ctr[i][j];
				tx = (i ? N - 1 : 1);
				ty = (j ? N - 1 : 1);
			}
		}
	}
	move_multiple(sx, sy, tx, ty);
}

void move_multiple(int &sx, int &sy, int tx, int ty) {
	while (sx != tx or sy != ty) {
		int cx = sx;
		if (sx < tx) {
			++sx;
		} else if (sx > tx) {
			--sx;
		}
		if (sy < ty) {
			++sy;
		} else if (sy > ty) {
			--sy;
		}
		if (have[sx][sy]) {
			sx = cx;
		}
		move(sx, sy);
	}
}

void move(int sx, int sy) {
	cout << sx << ' ' << sy << endl;
	int k, x, y;
	cin >> k >> x >> y;
	if (k <= 0) {
		exit(0);
	}
	have[px[k]][py[k]] = false;
	px[k] = x; py[k] = y;
	have[px[k]][py[k]] = true;
}