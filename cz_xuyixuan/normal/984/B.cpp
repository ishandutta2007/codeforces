#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {-1, 1, -1, 1, 0, -1, 1, 0};
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
char mp[MAXN][MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", mp[i] + 1);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (mp[i][j] == '*') continue;
		int cnt = 0;
		if (mp[i][j] != '.') cnt = mp[i][j] - '0';
		for (int k = 0; k < 8; k++)
			if (mp[i + dx[k]][j + dy[k]] == '*') cnt--;
		if (cnt != 0) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}