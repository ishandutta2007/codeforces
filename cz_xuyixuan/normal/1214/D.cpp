#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, m;
vector <char> s[MAXN];
vector <bool> a[MAXN];
vector <bool> b[MAXN];
vector <bool> vis[MAXN];
bool dfs1(int x, int y) {
	vis[x][y] = a[x][y] = true;
	if (x + y == n + m) return true;
	if (x < n && !vis[x + 1][y] && s[x + 1][y] != '#') {
		if (dfs1(x + 1, y)) return true;
	}
	if (y < m && !vis[x][y + 1] && s[x][y + 1] != '#') {
		if (dfs1(x, y + 1)) return true;
	}
	a[x][y] = false;
	return false;
}
bool dfs2(int x, int y) {
	vis[x][y] = b[x][y] = true;
	if (x + y == n + m) return true;
	if (y < m && !vis[x][y + 1] && s[x][y + 1] != '#') {
		if (dfs2(x, y + 1)) return true;
	}
	if (x < n && !vis[x + 1][y] && s[x + 1][y] != '#') {
		if (dfs2(x + 1, y)) return true;
	}
	b[x][y] = false;
	return false;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		s[i].push_back(' ');
		static char tmp[MAXN];
		scanf("\n%s", tmp + 1);
		for (int j = 1; j <= m; j++)
			s[i].push_back(tmp[j]);
		a[i].resize(m + 1);
		b[i].resize(m + 1);
		vis[i].resize(m + 1);
	}
	if (!dfs1(1, 1)) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		vis[i][j] = false;
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (i + j == 2 || i + j == n + m) continue;
		if (a[i][j] && b[i][j]) {
			puts("1");
			return 0;
		}
	}
	puts("2");
	return 0;
}