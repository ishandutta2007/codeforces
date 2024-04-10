#include<bits/stdc++.h>
using namespace std;
const int MAXN = 512;
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
int n, m, k;
ull a[MAXN][MAXN];
int x[MAXN], y[MAXN];
int main() {
	read(k), n = 1 << k;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		read(a[i][j]);
	read(m);
	for (int i = 1; i <= m; i++)
		read(x[i]), read(y[i]);
	for (int i = m; i >= 1; i--)  {
		x[i] = (x[i] - x[1] + n) % n;
		y[i] = (y[i] - y[1] + n) % n;
	}
	for (int t = 1; t <= 9; t++) {
		static ull f[MAXN][MAXN];
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		for (int k = 1; k <= m; k++)
			f[(i + x[k]) % n][(j + y[k]) % n] ^= a[i][j];
		swap(a, f);
		for (int i = 1; i <= m; i++) {
			x[i] = x[i] * 2 % n;
			y[i] = y[i] * 2 % n;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cnt += a[i][j] != 0;
	cout << cnt << endl;
	return 0;
}