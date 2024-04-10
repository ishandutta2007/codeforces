#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, t, l, r;
int bx[MAXN], by[MAXN], bz[MAXN];
vector <vector <int>> b[6];
vector <vector <vector <int>>> a;
vector <vector <vector <vector <bool>>>> vis;
void Make(vector <vector <int>> &b, int n, int m) {
	b.resize(n + 2);
	for (int i = 0; i <= n + 1; i++)
		b[i].resize(m + 2);
}
bool inside(int x, int y, int z) {
	return 1 <= x && x <= n && 1 <= y && y <= m && 1 <= z && z <= t;
}
void add(int x, int y, int z, int d, int v) {
	assert(!vis[x][y][z][d]);
	vis[x][y][z][d] = true;
	if (a[x][y][z] == 0) return;
	if (v == 0) {
		r++, a[x][y][z] = 0;
		bx[r] = x, by[r] = y, bz[r] = z;
	} else if (a[x][y][z] == -1 || a[x][y][z] == v) a[x][y][z] = v;
	else {
		r++, a[x][y][z] = 0;
		bx[r] = x, by[r] = y, bz[r] = z;
	}
}
int main() {
	read(n), read(m), read(t), l = 1;
	a.resize(n + 2), vis.resize(n + 2);
	for (int i = 0; i <= n + 1; i++) {
		a[i].resize(m + 2);
		vis[i].resize(m + 2);
		for (int j = 0; j <= m + 1; j++) {
			a[i][j].resize(t + 2);
			vis[i][j].resize(t + 2);
			for (int k = 0; k <= t + 1; k++)
				vis[i][j][k].resize(6);
		}
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	for (int k = 1; k <= t; k++)
		a[i][j][k] = -1;
	Make(b[0], m, t);
	Make(b[1], m, t);
	Make(b[2], n, t);
	Make(b[3], n, t);
	Make(b[4], n, m);
	Make(b[5], n, m);
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= t; j++) {
		read(b[0][i][j]);
		add(1, i, j, 0, b[0][i][j]);
	}
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= t; j++) {
		read(b[1][i][j]);
		add(n, i, j, 1, b[1][i][j]);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= t; j++) {
		read(b[2][i][j]);
		add(i, 1, j, 2, b[2][i][j]);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= t; j++) {
		read(b[3][i][j]);
		add(i, m, j, 3, b[3][i][j]);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		read(b[4][i][j]);
		add(i, j, 1, 4, b[4][i][j]);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		read(b[5][i][j]);
		add(i, j, t, 5, b[5][i][j]);
	}
	while (l <= r) {
		for (int i = 0; i <= 5; i++) {
			int x = bx[l], y = by[l], z = bz[l], v = 0;
			if (i <= 1) v = b[i][y][z];
			else if (i <= 3) v = b[i][x][z];
			else v = b[i][x][y];
			if (vis[x][y][z][i]) {
				while (inside(x, y, z) && a[x][y][z] == 0) {
					x += dx[i];
					y += dy[i];
					z += dz[i];
				}
				if (!inside(x, y, z)) {
					if (v != 0) {
						puts("-1");
						return 0;
					}
				} else add(x, y, z, i, v);
			}
		}
		l++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= t; k++)
				printf("%d ", max(a[i][j][k], 0));
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}