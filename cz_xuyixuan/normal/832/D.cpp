#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define MAXLOG	20
vector <int> a[MAXN];
int father[MAXN][MAXLOG], depth[MAXN];
void work(int pos, int fa) {
	father[pos][0] = fa;
	depth[pos] = depth[fa] + 1;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos);
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
int dist(int x, int y) {
	int z = lca(x, y);
	return depth[x] + depth[y] - 2 * depth[z];
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[x].push_back(i);
		a[i].push_back(x);
	}
	work(1, 0);
	for (int i = 1; i <= q; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int a = lca(x, y);
		int b = lca(x, z);
		int c = lca(y, z);
		if (depth[b] > depth[a]) a = b;
		if (depth[c] > depth[a]) a = c;
		printf("%d\n", 1 + max(max(dist(a, x), dist(a, y)), dist(a, z)));
	}
	return 0;
}