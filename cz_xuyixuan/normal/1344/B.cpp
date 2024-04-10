#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int dx[4] = {0, 0, -1, 1};
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
int n, m, x, y;
char s[MAXN][MAXN];
void dfs(int x, int y) {
	s[x][y] = '.';
	for (int i = 0; i <= 3; i++)
		if (s[x + dx[i]][y + dy[i]] == '#') dfs(x + dx[i], y + dy[i]);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j <= m; j++)
			cnt += (s[i][j] == '#') ^ (s[i][j + 1] == '#');
		if (cnt > 2) {
			puts("-1");
			return 0;
		} else if (cnt == 0) x++;
	}
	for (int j = 1; j <= m; j++) {
		int cnt = 0;
		for (int i = 0; i <= n; i++)
			cnt += (s[i][j] == '#') ^ (s[i + 1][j] == '#');
		if (cnt > 2) {
			puts("-1");
			return 0;
		} else if (cnt == 0) y++;
	}
	if ((x != 0) ^ (y != 0)) {
		puts("-1");
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		if (s[i][j] == '#') {
			ans++;
			dfs(i, j);
		}
	cout << ans << endl;
	return 0;
}