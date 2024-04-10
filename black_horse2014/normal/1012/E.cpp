//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 220000;

int cn;
int f[N], vis[N], a[N], b[N], x[N];
vector<int> adj[N], cyc[N];

void dfs(int u) {
	while (!adj[u].empty()) {
		int id = adj[u].back();
		adj[u].pop_back();
		dfs(a[id]);
		cyc[cn].push_back(id);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, s; cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i], x[i-1] = a[i];
	sort(x, x + n);
	int xn = unique(x, x + n) - x;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(x, x + xn, a[i]) - x + 1, b[i] = a[i];
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i]) continue;
		adj[b[i]].push_back(i);
	}
	for (int i = 1; i <= xn; i++) if (!adj[i].empty()) {
		dfs(i);
		cn++;
	}
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 0; i < cn; i++) {
		for (int j = 0; j < cyc[i].size(); j++) {
			int u = cyc[i][j], v = cyc[i][(j+1)%cyc[i].size()];
			f[v] = u;
		}
		s -= cyc[i].size();
	}
	if (s < 0) {
		puts("-1");
		return 0;
	}
	s = min(cn, s);
	if (s > 1) {
		printf("%d\n%d\n", cn - s + 2, s);
		for (int i = 0; i < s; i++) printf("%d ", cyc[i][0]);
		puts("");
		int last = f[cyc[s-1][0]];
		for (int i = s-1; i > 0; i--) f[cyc[i][0]] = f[cyc[i-1][0]];
		f[cyc[0][0]] = last;
	} else {
		printf("%d\n", cn);
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == i || vis[i]) continue;
		vector<int> ans;
		for (int j = i; !vis[j]; vis[j] = 1, j = f[j]) ans.push_back(j);
		printf("%d\n", ans.size());
		for (int x : ans) printf("%d ", x);
		puts("");
	}
	return 0;
}