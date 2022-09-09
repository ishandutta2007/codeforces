#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
const int P = 1e9 + 7;
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
char s[MAXN][MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];
int main() {
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	f[n][m - 1] = s[n][m - 1] == '.';
	g[n - 1][m] = s[n - 1][m] == '.';
	for (int i = n; i >= 1; i--)
	for (int j = m; j >= 1; j--) {
		if (s[i][j] == '#') continue;
		f[i][j] += f[i + 1][j] + f[i][j + 1];
		if (f[i][j] >= P) f[i][j] -= P;
		g[i][j] += g[i + 1][j] + g[i][j + 1];
		if (g[i][j] >= P) g[i][j] -= P;
	}
	writeln(((1ll * f[2][1] * g[1][2] - 1ll * f[1][2] * g[2][1]) % P + P) % P);
	return 0;
}