#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 555;

char map[N][N];
int ways[N][N];
int n, m;
int ver[N][N], hor[N][N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			map[i][j] = '#';
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", map[i] + 1);
		map[i][m + 1] = '#';
		for (int j = 1; j <= m; j++) {
			ways[i][j] = ways[i][j - 1] + ways[i - 1][j] - ways[i - 1][j - 1];
			if (map[i][j - 1] == '.') {
				ways[i][j] += (map[i][j] == '.');
			}
			if (map[i - 1][j] == '.') {
				ways[i][j] += (map[i][j] == '.');
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int s = 0;
		for (int j = 1; j <= m; j++) {
			s += (map[i][j] == '.' && map[i][j - 1] == '.');
			hor[i][j] = s;
		}
	}

	for (int i = 1; i <= m; i++) {
		int s = 0;
		for (int j = 1; j <= n; j++) {
			s += (map[j][i] == '.' && map[j - 1][i] == '.');
			ver[j][i] = s;
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", ways[c][d] - ways[c][b] - ways[a][d] + ways[a][b] + hor[a][d] - hor[a][b] + ver[c][b] - ver[a][b]);

	}
	return 0;
}