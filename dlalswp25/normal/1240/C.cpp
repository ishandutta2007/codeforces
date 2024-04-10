#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;

ll D[505050];
ll E[505050];
int N, K;

vector<pii> adj[505050];

void dfs(int v, int p) {
	ll s = 0;
	priority_queue<ll> pq;

	for(pii i : adj[v]) {
		if(i.first == p) continue;
		dfs(i.first, v);
		s += E[i.first];
		pq.push(D[i.first] - E[i.first] + i.second);
	}

	int cnt = 0;
	while(pq.size()) {
		if(pq.top() < 0) break;
		if(cnt >= K) break;
		if(cnt == K - 1) D[v] = s;
		s += pq.top(); pq.pop();
		cnt++;
	}
	if(cnt <= K - 1) D[v] = s;
	E[v] = s;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i < N; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
		dfs(1, 0);
		printf("%lld\n", E[1]);

		// for(int i = 1; i <= N; i++) printf("%lld ", D[i]); puts("");
		// for(int i = 1;i <= N; i++) printf("%lld ", E[i]); puts("");

		for(int i = 1; i <= N; i++) D[i] = E[i] = 0;
		for(int i = 1; i <= N; i++) adj[i].clear();
	}

	return 0;
}