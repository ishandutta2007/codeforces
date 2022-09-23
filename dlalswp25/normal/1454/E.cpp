#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int p[202020];
int sz[202020];
int up[202020];

vector<int> adj[202020];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

bool unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b) return false;
	p[a] = b;
	return true;
}

void dfs(int v, int p) {
	up[v] = p;
	sz[v] = 1;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);
		sz[v] += sz[i];
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			p[i] = i;
			adj[i].clear();
		}

		int u, v;
		for(int i = 1; i <= N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			if(!unite(a, b)) {
				u = a; v = b;
			}
			else {
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}

		dfs(u, 0);

		ll ans = (ll)N * (N - 1) / 2;
		ll bef = 0;
		while(v != u) {
			ans += (sz[v] - bef) * (N - sz[v]);
			bef = sz[v];
			v = up[v];
		}
		printf("%lld\n", ans);
	}
	return 0;
}