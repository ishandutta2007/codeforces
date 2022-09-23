#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll G, B;
int N;
vector<pii> adj[303030];

int sz[303030];

void init(int v, int p) {
	sz[v] = 1;
	for(auto i : adj[v]) {
		if(i.first == p) continue;
		init(i.first, v);
		sz[v] += sz[i.first];
	}
}

void dfs(int v, int p) {
	for(auto i : adj[v]) {
		if(i.first == p) continue;
		dfs(i.first, v);
		if(sz[i.first] & 1) G += i.second;
		B += (ll)i.second * min(sz[i.first], N - sz[i.first]);
	}
}
	
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		N <<= 1;
		for(int i = 1; i < N; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}

		init(1, 0);
		dfs(1, 0);

		printf("%lld %lld\n", G, B);

		for(int i = 1; i <= N; i++) {
			adj[i].clear();
			sz[i] = 0;
		}
		G = B = 0;
	}
	return 0;
}