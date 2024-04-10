#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, m, d[N], ans[N];
vector<int> adj[N];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	fill(d + 1, d + n + 1, N);
	d[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : adj[v])
			if (d[u] == N) {
				d[u] = d[v] + 1;
				q.push(u);
			}
	}
	vector<int> g[n];
	for (int i = 1; i <= n; ++i) {
		if (d[i] == N) 
			return printf("NO\n"), void(0);
		g[d[i]].pb(i);
		ans[i] = 0;
	}
	int cnt = 1;
	ans[1] = 1;
	for (int i = 2; i <= n - 1; ++i) {
		for (auto v : g[i]) {
			bool ok = 0;
			for (auto u : adj[v])
				ok |= ans[u];
			if (ok == 0) {
				ans[v] = 1; cnt++;
			}
		}
	}
	printf("YES\n");
	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i)
		if (ans[i]) printf("%d ", i);
	puts("");
}
	

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	
	return 0;
}