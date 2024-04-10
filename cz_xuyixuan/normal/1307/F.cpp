#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const int MAXLOG = 20;
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
int depth[MAXN], father[MAXN][MAXLOG];
vector <int> a[MAXN];
void work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos);
}
int climb(int x, int y) {
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (y & (1 << i)) x = father[x][i];
	return x;
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
int n, m, l, r, k, q[MAXN], f[MAXN], dist[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int main() {
	read(n), read(k), read(r), l = 1;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(n + i);
		a[n + i].push_back(x);
		a[y].push_back(n + i);
		a[n + i].push_back(y);
	}
	n += n - 1;
	work(1, 0);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= r; i++)
		read(q[i]), dist[q[i]] = 0;
	while (l <= r) {
		int pos = q[l++];
		if (dist[pos] == k) continue;
		for (auto x : a[pos]) {
			if (dist[x] == -1) {
				dist[x] = dist[pos] + 1;
				q[++r] = x;
			}
			f[find(x)] = find(pos);
		}
	}
	read(m);
	while (m--) {
		int x, y; read(x), read(y);
		int z = lca(x, y);
		if (depth[x] + depth[y] - 2 * depth[z] <= 2 * k) puts("YES");
		else {
			if (depth[x] - depth[z] >= k) x = climb(x, k);
			else x = climb(y, depth[x] + depth[y] - 2 * depth[z] - k);
			if (depth[y] - depth[z] >= k) y = climb(y, k);
			else y = climb(x, depth[x] + depth[y] - 2 * depth[z] - k);
			if (find(x) == find(y)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}