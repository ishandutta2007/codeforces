#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pp;

const int INF = 1010101010;

int N, Q, X, D;
int A[202020];
int p[202020];
int sz[202020];
int ans[202020];
set<pii> S;
vector<int> V[202020];
vector<int> adj[202020];

int cost(int i, int j) {
	if(!i) return INF;
	return abs(abs(A[i] - A[j]) - D);
}

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

int unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b) return 0;
	if(sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	for(int i : V[b]) V[a].push_back(i);
	return 1;
}

void dfs(int v, int p, int x) {
	ans[v] = x;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v, max(x, cost(v, i)));
	}
}

int main() {
	scanf("%d%d%d%d", &N, &Q, &X, &D);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) {
		p[i] = i;
		sz[i] = 1;
		V[i].push_back(i);
		S.insert({A[i], i});
	}

	int cnt = 0;
	while(cnt < N - 1) {
		vector<pii> edges;
		for(int i = 1; i <= N; i++) {
			if(p[i] != i) continue;
			for(int j : V[i]) S.erase(S.find({A[j], j}));

			int x = 0, y = 0;
			for(int j : V[i]) {
				auto update = [&](int nx, int ny) {
					if(nx > ny) swap(nx, ny);
					if(pp(cost(x, y), {x, y}) > pp(cost(nx, ny), {nx, ny})) {
						x = nx; y = ny;
					}
				};

				auto it = S.lower_bound({A[j] + D, 0});
				int nx = j, ny = it -> second;
				update(nx, ny);
				if(it != S.begin()) {
					it--; nx = j; ny = it -> second;
					update(nx, ny);
				}

				it = S.lower_bound({A[j] - D, 0});
				nx = j, ny = it -> second;
				update(nx, ny);
				if(it != S.begin()) {
					it--; nx = j; ny = it -> second;
					update(nx, ny);
				}
			}

			assert(x);
			edges.emplace_back(x, y);

			for(int j : V[i]) S.insert({A[j], j});
		}
		for(auto &i : edges) {
			int a = i.first, b = i.second;

			if(unite(a, b)) {
				cnt++;
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
	}

	dfs(X, 0, 0);

	// for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");

	while(Q--) {
		int i, k; scanf("%d%d", &i, &k);
		puts(ans[i] <= k ? "Yes" : "No");
	}

	return 0;
}