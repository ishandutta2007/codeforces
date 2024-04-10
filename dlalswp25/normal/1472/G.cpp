#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<int> adj[202020];
vector<int> rev[202020];
int ans[202020];
int D[202020];

queue<int> q;
vector<pii> v;

void dfs(int v, int c) {
	if(ans[v]) return;
	ans[v] = c;
	for(int i : rev[v]) {
		if(ans[i] || D[v] <= D[i]) continue;
		dfs(i, c);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) { adj[i].clear(); rev[i].clear(); }
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			rev[b].push_back(a);
		}
		for(int i = 1; i <= N; i++) { ans[i] = 0; D[i] = 0; }

		q.push(1); D[1] = 1;
		while(q.size()) {
			int x = q.front(); q.pop();
			for(int i : adj[x]) {
				if(D[i]) continue;
				D[i] = D[x] + 1;
				q.push(i);
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j : adj[i]) {
				if(D[i] < D[j]) continue;
				v.emplace_back(D[j], i);
			}
		}

		sort(v.begin(), v.end());

		for(pii i : v) {
			dfs(i.second, i.first);
		}
		for(int i = 1; i <= N; i++) {
			if(ans[i]) printf("%d ", min(ans[i], D[i]) - 1);
			else printf("%d ", D[i] - 1);
		}
		puts("");
	}
	return 0;
}