#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define MAXLOG	30
struct edge {int dest, len; };
vector <edge> a[MAXN];
int n, m, ans, f[MAXN];
int x[MAXN], y[MAXN], w[MAXN], length[MAXN];
int depth[MAXN], father[MAXN][MAXLOG], value[MAXN][MAXLOG];
bool mark[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void dfs(int pos, int fa, int val) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	value[pos][0] = val;
	for (int i = 1; i < MAXLOG; i++) {
		father[pos][i] = father[father[pos][i - 1]][i - 1];
		value[pos][i] = value[pos][i - 1] ^ value[father[pos][i - 1]][i - 1];
	}
	if (pos == n) ans = value[pos][MAXLOG - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].dest != fa) dfs(a[pos][i].dest, pos, a[pos][i].len);
}
int get(int x, int y) {
	int ans = 0;
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[father[x][i]] <= depth[y]) {
			ans ^= value[x][i];
			x = father[x][i];
		}
	if (x == y) return ans;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (father[x][i] != father[y][i]) {
			ans ^= value[x][i];
			x = father[x][i];
			ans ^= value[y][i];
			y = father[y][i];
		}
	return ans ^ value[x][0] ^ value[y][0];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> w[i];
		if (F(x[i]) == F(y[i])) continue;
		f[F(x[i])] = F(y[i]);
		a[x[i]].push_back((edge) {y[i], w[i]});
		a[y[i]].push_back((edge) {x[i], w[i]});
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= m; i++)
		length[i] = get(x[i], y[i]) ^ w[i];
	for (int i = MAXLOG; i >= 0; i--) {
		int tmp = 1 << i, pos = 0;
		for (int j = 1; j <= m; j++)
			if (length[j] & tmp) {
				pos = j;
				break;
			}
		if (pos == 0) continue;
		int value = length[pos];
		if (ans & tmp) ans ^= value;
		for (int j = 1; j <= m; j++)
			if (length[j] & tmp) length[j] ^= value;
	}
	cout << ans << endl;
	return 0;
}