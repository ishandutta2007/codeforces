#include <bits/stdc++.h>

using namespace std;

int N, M;
int T[202020];
int A[202020];
int B[202020];
vector<int> adj[202020];

int dir[202020];
int indeg[202020];
int pos[202020];

bool dfs(int v) {
	bool ret = true;
	for(int i : adj[v]) {
		if(!dir[i]) {
			dir[i] = 3 - dir[v];
			dfs(i);
		}
		else if(dir[i] == dir[v]) ret = false;
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d", &T[i], &A[i], &B[i]);
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	for(int i = 1; i <= N; i++) {
		if(!dir[i]) {
			dir[i] = 1;
			if(!dfs(i)) {
				puts("NO");
				return 0;
			}
		}
	}

	for(int i = 1; i <= N; i++) adj[i].clear();
	for(int i = 1; i <= M; i++) {
		if(T[i] == 1) {
			int a = A[i], b = B[i];
			if(dir[a] != 1) swap(a, b);
			adj[a].push_back(b);
			indeg[b]++;
		}
		else {
			int a = A[i], b = B[i];
			if(dir[a] != 2) swap(a, b);
			adj[a].push_back(b);
			indeg[b]++;
		}
	}

	queue<int> q;
	for(int i = 1; i <= N; i++) {
		if(!indeg[i]) q.push(i);
	}
	vector<int> v;
	while(q.size()) {
		int x = q.front(); q.pop();
		v.push_back(x);
		for(int i : adj[x]) {
			indeg[i]--;
			if(!indeg[i]) q.push(i);
		}
	}

	if(v.size() != N) { puts("NO"); return 0; }
	for(int i = 0; i < N; i++) pos[v[i]] = i;
	puts("YES");
	for(int i = 1; i <= N; i++) printf("%c %d\n", (dir[i] == 1 ? 'L' : 'R'), pos[i]);
	return 0;
}