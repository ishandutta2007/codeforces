#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int E = 1000000;
const int inf = 2139062143;

struct edge {
	int u, v, len, id;
}e[N];
int chosen[E];
int pre[N], inwei[N], innum[N], id[N], vis[N];
int inc[E], decr[E], pos;

inline int mst(int n, int m, int root = 1) {
	memset(inc,0,sizeof(inc));
	memset(decr,0,sizeof(decr));
	memset(chosen,0,sizeof(chosen));
	int ans = 0, eg = m;
	pos = m;
	while (true) {
		memset(inwei, 127, sizeof(int) * (n + 2));
		memset(id, 0, sizeof(int) * (n + 2));
		memset(vis, 0, sizeof(int) * (n + 2));
		for (int i = 1; i <= m; i++)
			if (e[i].len < inwei[e[i].v]) {
				inwei[e[i].v] = e[i].len;
				pre[e[i].v] = e[i].u;
				innum[e[i].v] = e[i].id;
			}
		inwei[root] = 0;
		for (int i = 1; i <= n; i++)
			if (inwei[i] == inf) return -1;
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			ans += inwei[i];
			if (i != root) chosen[innum[i]]++;
			int j = i;
			while (vis[j] != i && j != root && !id[j])
				vis[j] = i, j = pre[j];
			if (j != root && !id[j]) {
				id[j] = ++tot;
				for (int k = pre[j]; k != j; k = pre[k]) id[k] = tot;
			}
		}
		if (!tot) break;
		for (int i = 1; i <= n; i++)
			if (!id[i]) id[i] = ++tot;
		n = tot;
		int j = 1;
		for (int i = 1; i <= m; i++) {
			int v = e[i].v;
			e[j].v = id[e[i].v];
			e[j].u = id[e[i].u];
			if (e[j].v != e[j].u) {
				e[j].len = e[i].len - inwei[v];
				pos++;
				inc[pos] = e[i].id;
				decr[pos] = innum[v];
				e[j++].id = pos;
			}
		}
		m = j-1;
		root = id[root];
	}
	while (pos > eg) {
		if (chosen[pos] > 0) {
			chosen[inc[pos]]++;
			chosen[decr[pos]]--;
		}
		pos--;
	}
	return ans;
}
bool bad[N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		e[i].id = i;
		cin >> e[i].u >> e[i].v >> e[i].len;
		if (e[i].len) bad[i] = 1;
	}
	int res = mst(n,m);
	cout << res << '\n';
	if (res == -1) return 0;
	for (int i = 1; i <= m; ++i) 
		if (bad[i] and chosen[i])
			cout << i << ' ';
	cout << '\n';
}