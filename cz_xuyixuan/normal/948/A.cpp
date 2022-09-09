#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
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
char mp[MAXN][MAXN];
int main() {
	int n, m;
	read(n), read(m);
	bool ans = true;
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", mp[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (mp[i][j] == '.') mp[i][j] = 'D';
			if (i != 1 && mp[i][j] == 'S' && mp[i - 1][j] == 'W') ans = false;
			if (i != 1 && mp[i][j] == 'W' && mp[i - 1][j] == 'S') ans = false;
			if (j != 1 && mp[i][j] == 'S' && mp[i][j - 1] == 'W') ans = false;
			if (j != 1 && mp[i][j] == 'W' && mp[i][j - 1] == 'S') ans = false;
		}
	}
	if (!ans) printf("No\n");
	else {
		printf("Yes\n");
		for (int i = 1; i <= n; i++)
			printf("%s\n", mp[i] + 1);
	}
	return 0;
}