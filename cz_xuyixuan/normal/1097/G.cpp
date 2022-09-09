#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXK = 205;
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
int n, k, fac[MAXK], s[MAXK][MAXK];
int dp[MAXN][MAXK], res[MAXK], size[MAXN];
vector <int> a[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void times(int *a, int &la, int *b, int lb) {
	static int tmp[MAXK];
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i <= la && i <= k; i++)
	for (int j = 0; j <= lb && i + j <= k; j++)
		update(tmp[i + j], 1ll * a[i] * b[j] % P);
	memcpy(a, tmp, sizeof(tmp));
	la += lb;
}
void work(int pos, int fa) {
	size[pos] = 1, dp[pos][0] = 2;
	for (auto x : a[pos])
		if (x != fa) {
			work(x, pos);
			times(dp[pos], size[pos], dp[x], size[x]);
			for (int i = 0; i <= k; i++)
				update(res[i], P - dp[x][i]);
		}
	for (int i = 0; i <= k; i++)
		update(res[i], dp[pos][i]);
	for (int i = k; i >= 1; i--)
		update(dp[pos][i], dp[pos][i - 1]);
	update(dp[pos][1], P - 1);
}
void init(int n, int k) {
	s[0][0] = fac[0] = 1;
	for (int i = 1; i <= k; i++) {
		fac[i] = 1ll * fac[i - 1] * i % P;
		for (int j = 1; j <= i; j++)
			s[i][j] = (s[i - 1][j - 1] + 1ll * s[i - 1][j] * j) % P;
	}	
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	init(n, k);
	work(1, 0);
	int ans = 0;
	for (int i = 0; i <= k; i++)
		update(ans, 1ll * s[k][i] * fac[i] % P * res[i] % P);
	writeln(ans);
	return 0;
}