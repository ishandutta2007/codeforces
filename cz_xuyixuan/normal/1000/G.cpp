#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXLOG = 21;
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
int n, m, q, val[MAXN];
ll dp[MAXN], up[MAXN], sum[MAXN], mns[MAXN];
int depth[MAXN], father[MAXN][MAXLOG];
vector <pair <int, int> > a[MAXN];
void work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	dp[pos] = val[pos];
	for (auto x : a[pos])
		if (x.first != fa) {
			work(x.first, pos);
			dp[pos] += max(dp[x.first] - 2 * x.second, 0ll);
		}
}
void getup(int pos, int fa, ll d) {
	up[pos] = d; d += dp[pos];
	sum[pos] = sum[fa] + dp[pos];
	for (auto x : a[pos])
		if (x.first != fa) {
			mns[x.first] = mns[pos] + x.second + max(dp[x.first] - 2 * x.second, 0ll);
			getup(x.first, pos, max(d - max(dp[x.first] - 2 * x.second, 0ll) - 2 * x.second, 0ll));
		}
}
int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[father[x][i]] >= depth[y]) x = father[x][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
		}
	return father[x][0];
}
ll dpsum(int x, int y, int z) {
	int tmp = father[z][0];
	return sum[x] + sum[y] - sum[tmp] - sum[z];
}
ll mnsum(int x, int y, int z) {
	int tmp = z;
	return mns[x] + mns[y] - mns[tmp] - mns[z];
}
int main() {
	read(n), m = n - 1, read(q);
	for (int i = 1; i <= n; i++)
		read(val[i]);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		a[x].emplace_back(y, z);
		a[y].emplace_back(x, z);
	}
	work(1, 0);
	getup(1, 0, 0);
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		int z = lca(x, y);
		writeln(dpsum(x, y, z) - mnsum(x, y, z) + up[z]);
	}
	return 0;
}