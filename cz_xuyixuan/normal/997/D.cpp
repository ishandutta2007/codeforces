#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const int MAXK = 105;
const int P = 998244353;
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
int n, m, k, c[MAXK][MAXK], f[MAXK], g[MAXK];
int dp[MAXN][MAXK], up[MAXN][MAXK];
vector <int> a[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void work(int pos, int fa) {
	for (auto x : a[pos])
		if (x != fa) work(x, pos);
	dp[pos][0] = 1;
	for (int i = 1; i <= k; i++)
	for (auto x : a[pos])
		if (x != fa) {
			for (int j = 0; j <= i - 1; j++)
				update(dp[pos][i], 1ll * dp[x][j] * dp[pos][i - j - 1] % P);
		}
}
void getup(int pos, int fa) {
	static int tmp[MAXK];
	memcpy(tmp, up[pos], sizeof(tmp));
	for (int i = 0; i <= k; i++)
	for (auto x : a[pos])
		if (x != fa) update(tmp[i], dp[x][i]);
	for (auto x : a[pos])
		if (x != fa) {
			up[x][0] = 1;
			for (int i = 1; i <= k; i++)
			for (int j = 0; j <= i - 1; j++)
				update(up[x][i], 1ll * (tmp[j] - dp[x][j] + P) * up[x][i - j - 1] % P);
		}
	memset(tmp, 0, sizeof(tmp));
	tmp[0] = 1;
	for (int i = 1; i <= k; i++)
	for (int j = 0; j <= i - 1; j++)
	for (auto x : a[pos])
		if (x != fa) update(tmp[i], 1ll * dp[x][j] * tmp[i - j - 1] % P);
		else update(tmp[i], 1ll * up[pos][j] * tmp[i - j - 1] % P);
	for (int i = 0; i <= k; i++)
		update(f[i], tmp[i]);
	for (auto x : a[pos])
		if (x != fa) getup(x, pos);
}
void getf() {
	memset(dp, 0, sizeof(dp));
	memset(up, 0, sizeof(up));
	memset(f, 0, sizeof(f));
	work(1, 0);
	getup(1, 0);
}
int main() {
	read(n), read(m), read(k);
	if (k & 1) {
		printf("0\n");
		return 0;
	}
	k /= 2;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	getf();
	swap(f, g);
	swap(n, m);
	for (int i = 1; i <= n; i++)
		a[i].clear();
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	getf();
	for (int i = 0; i <= 2 * k; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
	}
	int ans = 0;
	for (int i = 0; i <= k; i++)
		update(ans, 1ll * f[i] * g[k - i] % P * c[2 * k][2 * i] % P);
	writeln(ans);
	return 0;
}