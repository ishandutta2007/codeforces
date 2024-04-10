#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int N = 1e5+5;
vector<int> T[N];
int sz[N];
int depth[N];
const int K = 17;
int parent[N][K];

void dfs(int v, int p, int d) {
	parent[v][0] = p;
	sz[v] = 1;
	depth[v] = d;
	for(int u : T[v]) {
		if(u == p) continue;
		dfs(u, v, d+1);
		sz[v] += sz[u];
	}
}

int get_anc(int u, int amt) {
	for(int k = K-1; k >= 0; --k) {
		if((1<<k) <= amt) {
			amt -= 1<<k;
			u = parent[u][k];
		}
	}
	return u;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs(0, 0, 0);
	for(int k = 1; k < K; ++k) {
		for(int v = 0; v < n; ++v)
			parent[v][k] = parent[parent[v][k-1]][k-1];
	}

	int m;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y, --x, --y;
		if(x == y) {
			cout << n << "\n";
			continue;
		} else if((depth[x]+depth[y])%2 != 0) {
			cout << "0\n";
			continue;
		}
		if(depth[y] > depth[x]) swap(x, y);
		int y2 = y;

		int x2 = get_anc(x, depth[x]-depth[y]);

		for(int k = K-1; k >= 0; --k) {
			if(parent[x2][k] != parent[y2][k]) {
				x2 = parent[x2][k];
				y2 = parent[y2][k];
			}
		}
		int c = x2;
		if(x2 != y2)
			c = parent[x2][0];
		
		if(depth[x] == depth[y]) {
			int ans = n - sz[x2] - sz[y2];
			cout << ans << "\n";
		} else {
			int tot = depth[x] + depth[y] - 2*depth[c];
			c = get_anc(x, tot/2);
			x = get_anc(x, tot/2-1);
			int ans = sz[c] - sz[x];
			cout << ans << "\n";
		}
	}
}