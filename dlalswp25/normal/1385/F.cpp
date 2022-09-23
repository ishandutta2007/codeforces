#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> adj[202020];
int cnt[202020];
int deg[202020];
queue<int> q;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if(K == 1) { printf("%d\n", N - 1); continue; }

		while(q.size()) q.pop();

		for(int i = 1; i <= N; i++) deg[i] = adj[i].size();

		for(int i = 1; i <= N; i++) {
			cnt[i] = 0;
			for(int j : adj[i]) {
				if(deg[j] == 1) cnt[i]++;
			}
			if(cnt[i] >= K) q.push(i);
		}

		int ans = 0;
		while(q.size()) {
			int x = q.front(); q.pop();
			if(cnt[x] < K) continue;
			ans++;
			cnt[x] -= K;
			deg[x] -= K;
			if(cnt[x] >= K) {
				q.push(x); continue;
			}
			if(deg[x] == 1) {
				for(int i : adj[x]) {
					if(deg[i] > 1) {
						cnt[i]++;
						if(cnt[i] >= K) q.push(i);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}