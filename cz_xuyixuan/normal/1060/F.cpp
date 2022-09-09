#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
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
int n, depth[MAXN], size[MAXN];
double ans, f[MAXN][MAXN], c[MAXN][MAXN];
vector <int> a[MAXN];
void times(double *a, double *b, double *res) {
	for (int i = 0; i <= n; i++)
		res[i] = 0;
	for (int i = 0; i <= n; i++)
	for (int j = 0; i + j <= n; j++)
		res[i + j] += a[i] * b[j];
}
void work(int x, int par) {
	size[x] = 0;
	f[x][0] = 1;
	for (auto y : a[x])
		if (y != par) {
			work(y, x);
			vector <double> tmp(size[y] + 1);
			for (int i = 0; i <= size[y]; i++)
			for (int j = 1; j <= size[y]; j++)
				if (j <= i) tmp[i] += f[y][min(i, j - 1)] / 2;
				else tmp[i] += f[y][min(i, j - 1)];
			vector <double> res(size[y] + size[x] + 1);
			for (int i = 0; i <= size[x]; i++)
			for (int j = 0; j <= size[y]; j++)
				res[i + j] += f[x][i] * tmp[j] * c[i + j][j] * c[size[x] + size[y] - i - j][size[x] - i];
			for (int i = 0; i <= size[x] + size[y]; i++)
				f[x][i] = res[i];
			size[x] += size[y];	
		}
	size[x]++;
}
int main() {
	read(n);
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		work(i, 0);
		double ans = f[i][n - 1];
		for (int j = 1; j <= n - 1; j++)
			ans /= j;
		printf("%.10lf\n", ans);
	}
	return 0;
}