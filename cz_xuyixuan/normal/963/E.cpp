#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8005;
const int MAXM = 120;
const int MAXR = 60;
const int P = 1e9 + 7;
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
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int n, p[5], point[MAXM][MAXM], a[MAXN][MAXN];
int main() {
	int r; read(r);
	for (int i = 1; i <= 4; i++) {
		read(p[i]);
		p[0] += p[i];
	}
	for (int i = 1; i <= 4; i++)
		p[i] = 1ll * p[i] * power(p[0], P - 2) % P;
	for (int i = -r; i <= r; i++)
	for (int j = -r; j <= r; j++) {
		int tmp = i * i + j * j;
		if (tmp <= r * r) point[i + MAXR][j + MAXR] = ++n;
	}
	for (int i = -r + MAXR; i <= r + MAXR; i++)
	for (int j = -r + MAXR; j <= r + MAXR; j++) {
		if (point[i][j] == 0) continue;
		int tmp = point[i][j];
		a[tmp][tmp] = P - 1; a[tmp][n + 1] = P - 1;
		if (point[i - 1][j] != 0) a[tmp][point[i - 1][j]] = p[1];
		if (point[i][j - 1] != 0) a[tmp][point[i][j - 1]] = p[2];
		if (point[i + 1][j] != 0) a[tmp][point[i + 1][j]] = p[3];
		if (point[i][j + 1] != 0) a[tmp][point[i][j + 1]] = p[4];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n + 1; j++)
			if (a[j][i] != 0) {
				swap(a[i], a[j]);
				break;
			}
		int top = 0;
		static int q[MAXN];
		for (int j = 1; j <= n + 1; j++)
			if (a[i][j] != 0) q[++top] = j;
		int inv = power(a[i][i], P - 2);
		for (int j = 1; j <= top; j++)
			a[i][q[j]] = 1ll * a[i][q[j]] * inv % P;
		for (int j = i + 1; j <= n; j++) {
			if (a[j][i] == 0) continue;
			int tmp = a[j][i];
			for (int k = 1; k <= top; k++)
				a[j][q[k]] = (a[j][q[k]] - 1ll * tmp * a[i][q[k]] % P + P) % P; 
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++)
			a[i][n + 1] = (a[i][n + 1] - 1ll * a[j][0] * a[i][j] % P + P) % P;
		a[i][0] = 1ll * a[i][n + 1] * power(a[i][i], P - 2) % P;
		if (i == point[MAXR][MAXR]) {
			writeln(a[i][0]);
			return 0;
		}
	}
	return 0;
}