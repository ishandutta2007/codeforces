#include <bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;

const int N = 1e5 + 20;

int T, n, m, k, alive[N], deg[N];
vector<int> g[N];

bool check(int v) {
	if (1LL * k * (k - 1) / 2 > m) return false;
	vector<int> f = {v};
	for (auto u : g[v])
		if (alive[u] >= 1)
			f.pb(u);
	for (auto a : f)
		for (auto b : f) 
			if (a != b && !binary_search(g[a].begin(), g[a].end(), b)) return 0;
	printf("2\n");
	for (auto x : f)
		printf("%d ", x);
	puts("");
	return 1;
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) 
		g[i].clear(), alive[i] = 2, deg[i] = 0;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		deg[i] = sz(g[i]);
		sort(g[i].begin(), g[i].end());
		if (deg[i] < k) {
			q.push(i);
			alive[i] = 1;
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		alive[v] = 0;
		if (deg[v] == k - 1) 
			if (check(v))
				return;
		for (auto u : g[v])
			if (--deg[u] < k && alive[u] == 2) {
				q.push(u);
				alive[u] = 1;
			}
	}
	vector<int> res;
	for (int i = 1; i <= n; ++i)
		if (alive[i])
			res.pb(i);
	if (res.empty()) return printf("-1\n"), void(0);
	printf("1 %d\n", sz(res));
	for (auto x : res)
		printf("%d ", x);
	puts("");
}

int main() {
	scanf("%d", &T);
	while(T--)
		solve();
	return 0;
}