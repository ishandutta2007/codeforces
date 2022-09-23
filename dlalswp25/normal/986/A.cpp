#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[100005];
int a[100005];
int N, M, S, K;
vector<int> ans[100005];
queue<int> q;
bool visited[100005];

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &S);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= K; j++) {
			ans[i].push_back(987654321);
		}
	}

	for(int i = 1; i <= K; i++) {
		for(int j = 1; j <= N; j++) {
			visited[j] = false;
		}
		for(int j = 1; j <= N; j++) {
			if(a[j] == i) {
				visited[j] = true;
				q.push(j);
				ans[j][i] = 0;
			}
		}

		while(!q.empty()) {
			int now = q.front(); q.pop();
			for(int j = 0; j < adj[now].size(); j++) {
				int next = adj[now][j]; if(visited[next]) continue;
				visited[next] = true;
				ans[next][i] = ans[now][i] + 1;
				q.push(next);
			}
		}
	}
	for(int i = 1; i <= N; i++) {
		sort(ans[i].begin(), ans[i].end());
		int ret = 0;
		for(int j = 0; j < S; j++) ret += ans[i][j];
		printf("%d ", ret);
	}
	return 0;
}