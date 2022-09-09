#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
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
int n, size[MAXN][MAXN], nxt[MAXN][MAXN], len[MAXN][MAXN];
int x[MAXN], y[MAXN]; ll dp[MAXN][MAXN];
vector <int> a[MAXN];
void dfs(int root, int fa, int pos) {
	size[root][pos] = 1;
	len[root][pos] = len[root][fa] + 1;
	if (fa == root) nxt[root][pos] = pos;
	else nxt[root][pos] = nxt[root][fa];
	for (auto x : a[pos])
		if (x != fa) {
			dfs(root, pos, x);
			size[root][pos] += size[root][x];
		}
}
ll getans(int x, int y) {
	if (x == y) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	return dp[x][y] = (n - size[x][nxt[x][y]]) * (n - size[y][nxt[y][x]]) + max(getans(nxt[x][y], y), getans(x, nxt[y][x]));
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		read(x[i]), read(y[i]);
		a[x[i]].push_back(y[i]);
		a[y[i]].push_back(x[i]);
	}
	for (int i = 1; i <= n; i++) {
		size[i][i] = n;
		for (auto x : a[i])
			dfs(i, i, x);
	}
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		chkmax(ans, getans(i, j));
	cout << ans << endl;
	return 0;
}