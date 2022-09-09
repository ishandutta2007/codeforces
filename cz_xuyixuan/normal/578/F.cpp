#include<bits/stdc++.h>
using namespace std;
const int MAXN = 405;
const int MAXM = 1e5 + 5;
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
int n, m, tot, P, a[MAXN][MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
char s[MAXN][MAXN];
int num[MAXN][MAXN], f[MAXM], g[MAXM];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int gauss(int n) {
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			if (a[j][i]) {
				swap(a[i], a[j]);
				ans = P - ans;
			}
		int inv = power(a[i][i], P - 2);
		for (int j = i + 1; j <= n; j++)
			if (a[j][i]) {
				int tmp = 1ll * a[j][i] * inv % P;
				for (int k = i; k <= n; k++)
					update(a[j][k], P - 1ll * a[i][k] * tmp % P);
			}
	}
	for (int i = 1; i <= n; i++)
		ans = 1ll * ans * a[i][i] % P;
	return ans;
}
int solve(int type) {
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= m; j++)
		if ((i + j) % 2 == type) f[num[i][j]] = num[i][j];
		else f[num[i][j]] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if ((i + j) % 2 == type) {
			if (s[i][j] == '\\') {
				int x = find(num[i][j]), y = find(num[i - 1][j - 1]);
				if (x == y) return 0;
				else f[x] = y;
			}
		} else {
			if (s[i][j] == '/') {
				int x = find(num[i - 1][j]), y = find(num[i][j - 1]);
				if (x == y) return 0;
				else f[x] = y;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= tot; i++)
		if (f[i] == i) g[i] = ++cnt;
	if (cnt > 200) return 0;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if ((i + j) % 2 == type) {
			if (s[i][j] == '*') {
				int x = g[find(num[i][j])], y = g[find(num[i - 1][j - 1])];
				if (x != y) {
					update(a[x][x], 1);
					update(a[y][y], 1);
					update(a[x][y], P - 1);
					update(a[y][x], P - 1);
				}
			}
		} else {
			if (s[i][j] == '*') {
				int x = g[find(num[i - 1][j])], y = g[find(num[i][j - 1])];
				if (x != y) {
					update(a[x][x], 1);
					update(a[y][y], 1);
					update(a[x][y], P - 1);
					update(a[y][x], P - 1);
				}
			}
		}
	}
	return gauss(cnt - 1);
}
int main() {
	read(n), read(m), read(P);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= m; j++)
		num[i][j] = ++tot;
	int ans = solve(0);
	update(ans, solve(1));
	cout << ans << endl;
	return 0;
}