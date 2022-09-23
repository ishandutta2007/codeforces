#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int N;
ll S;
vector<pii> adj[101010];
int sz[101010];
ll w[101010];
priority_queue<pii> pq;

bool lf(int v) {
	return adj[v].size() == 1 && v != 1;
}

void dfs(int v, int p) {
	if(lf(v)) sz[v] = 1;
	else sz[v] = 0;
	for(pii i : adj[v]) {
		if(i.first == p) continue;
		w[i.first] = i.second;
		dfs(i.first, v);
		sz[v] += sz[i.first];
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &S);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			adj[a].emplace_back(b, c);
			adj[b].emplace_back(a, c);
		}

		dfs(1, 0);

		while(pq.size()) pq.pop();

		ll sum = 0;
		for(int i = 2; i <= N; i++) {
			sum += (ll)w[i] * sz[i];
			pq.emplace((w[i] + 1) / 2 * sz[i], i);
		}

		int ans = 0;
		while(sum > S) {
			pii t = pq.top(); pq.pop();
			sum -= t.first;

			w[t.second] /= 2;
			pq.emplace((w[t.second] + 1) / 2 * sz[t.second], t.second);
			ans++;
			// printf("%d %lld\n", ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}