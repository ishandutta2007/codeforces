#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, q, rt[MAXN], depth[MAXN], father[MAXN][MAXLOG];
ll l, path[MAXN], dist[MAXN], res[MAXN];
vector <pair <int, int>> a[MAXN];
priority_queue <ll> Heap[MAXN];
void getans(int pos, int fa) {
	while (!Heap[pos].empty()) Heap[pos].pop();
	Heap[pos].push(res[pos]);
	for (auto x : a[pos])
		if (x.first != fa) {
			getans(x.first, pos);
			while (Heap[x.first].size() > Heap[pos].size()) swap(Heap[x.first], Heap[pos]);
			while (!Heap[x.first].empty()) {
				Heap[pos].push(Heap[x.first].top());
				Heap[x.first].pop();
			}
		}
	while (Heap[pos].top() - res[pos] > l) Heap[pos].pop();
	rt[pos] = Heap[pos].size();
}
void work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].first != fa) {
			path[a[pos][i].first] = path[pos] + a[pos][i].second;
			work(a[pos][i].first, pos);
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
void dfs(int pos, int fa) {
	for (auto x : a[pos])
		if (x.first != fa) {
			dist[x.first] = dist[pos] + x.second;
			dfs(x.first, pos);
		}
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		a[x].emplace_back(y, z);
		a[y].emplace_back(x, z);
	}
	work(1, 0);
	int x = 0, y = 0;
	dist[1] = 0, dfs(1, 0);
	for (int i = 1; i <= n; i++)
		if (dist[i] > dist[x]) x = i;
	dist[x] = 0, dfs(x, 0);
	for (int i = 1; i <= n; i++)
		if (dist[i] > dist[y]) y = i;
	ll Min = 1e18; int rx = 0, ry = 0;
	for (int i = 1; i <= n; i++) {
		ll lenx = path[i] + path[x] - 2 * path[lca(i, x)];
		ll leny = path[i] + path[y] - 2 * path[lca(i, y)];
		res[i] = max(lenx, leny);
		chkmin(Min, res[i]);
		if (lenx > leny) {
			if (rx == 0 || res[i] < res[rx]) rx = i;
		} else {
			if (ry == 0 || res[i] < res[ry]) ry = i;
		}
	}
	read(q);
	while (q--) {
		read(l);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (res[i] - Min <= l) ans++;
		getans(rx, ry);
		getans(ry, rx);
		for (int i = 1; i <= n; i++)
			chkmax(ans, rt[i]);
		printf("%d\n", ans);
	}
	return 0;
}