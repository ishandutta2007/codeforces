#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int N = 500;

const int BLACK = 0, WHITE = 1;
int n, m;
int black, white;
char map[N][N];

void color(int ii, int jj, int down, int left) {
	if (down == left) {
		map[ii + 1][jj] = map[ii][jj + 1] = '\\';
		if (down == BLACK) map[ii][jj] = '#', map[ii + 1][jj + 1] = '.';
		if (down == WHITE) map[ii][jj] = '.', map[ii + 1][jj + 1] = '#';
	} else {
		map[ii][jj] = map[ii + 1][jj + 1] = '/';
		if (down == BLACK) map[ii + 1][jj] = '.', map[ii][jj + 1] = '#';
		if (down == WHITE) map[ii + 1][jj] = '#', map[ii][jj + 1] = '.';
	}
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %*d", &black, &white);
	int mid = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ii = i << 1, jj = j << 1;
			if (black) {
				map[ii][jj] = map[ii | 1][jj] =
				map[ii][jj | 1] = map[ii | 1][jj | 1] = '#';
				black--;
			} else if (mid) {
				int left = WHITE;
				if (j == 0) {
					color(ii, jj, BLACK, mid % 2 ? BLACK : WHITE);
				} else if ((map[ii][jj - 1] == '#' || map[ii + 1][jj - 1] == '#')) {
					color(ii, jj, BLACK, BLACK);
				} else {
					color(ii, jj, BLACK, WHITE);
				}
				mid--;
			} else if (white) {
				map[ii][jj] = map[ii + 1][jj] =
				map[ii][jj + 1] = map[ii + 1][jj + 1] = '.';
				white--;
			} else {
				int left = WHITE, down = WHITE;
				if (j > 0 && (map[ii][jj - 1] == '#' || map[ii + 1][jj - 1] == '#')) {
					left = BLACK;
				}
				if (i > 0 && (map[ii - 1][jj] == '#' || map[ii - 1][jj + 1] == '#')) {
					down = BLACK;
				}
				color(ii, jj, down, left);
			}
		}
	}

	for (int i = 2 * n - 1; i >= 0; i--, puts("")) {
		for (int j = 0; j < m << 1; j++) {
			printf("%c", map[i][j]);
		}
	}
	return 0;
}