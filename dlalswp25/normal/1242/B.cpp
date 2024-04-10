#include <bits/stdc++.h>

using namespace std;

set<int> S;
vector<int> adj[101010];
queue<int> q;
vector<int> tmp;

int ans;
int N, M;

bool is_edge(int a, int b) {
	auto it = lower_bound(adj[a].begin(), adj[a].end(), b);
	if(it == adj[a].end()) return false;
	if((*it) == b) return true;
	return false;
}

void bfs(int s) {
	while(q.size()) q.pop();
	q.push(s); S.erase(s);
	while(q.size()) {
		int v = q.front(); q.pop();
		tmp.clear();
		for(int i : S) {
			if(!is_edge(i, v)) tmp.push_back(i);
		}

		for(int i : tmp) { q.push(i); S.erase(i); }
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	for(int i = 1; i <= N; i++) S.insert(i);

	for(int i = 1; i <= N; i++) {
		if(S.find(i) == S.end()) continue;
		bfs(i); ans++;
	}
	printf("%d\n", ans - 1);

	return 0;
}