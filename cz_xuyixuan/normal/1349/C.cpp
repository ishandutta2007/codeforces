#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};
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
bool key[MAXN][MAXN];
int dist[MAXN][MAXN];
char s[MAXN][MAXN];
int main() {
	read(n), read(m), read(t);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	memset(dist, -1, sizeof(dist));
	static pair <int, int> q[MAXN * MAXN];
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (s[i][j] == s[i + 1][j]) key[i][j] = key[i + 1][j] = true;
		if (s[i][j] == s[i][j + 1]) key[i][j] = key[i][j + 1] = true;
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		if (key[i][j]) {
			q[++r] = make_pair(i, j);
			dist[i][j] = 0;
		}
	while (l <= r) {
		pair <int, int> pos = q[l++];
		for (int i = 0; i <= 3; i++) {
			int tx = pos.first + dx[i];
			int ty = pos.second + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && dist[tx][ty] == -1) {
				dist[tx][ty] = dist[pos.first][pos.second] + 1;
				q[++r] = make_pair(tx, ty);
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		int x, y; ll p;
		read(x), read(y), read(p);
		if (p < dist[x][y] || dist[x][y] == -1) putchar(s[x][y]);
		else if ((p - dist[x][y]) & 1) putchar(s[x][y] ^ 1);
		else putchar(s[x][y]);
		puts("");
	}
	return 0;
}