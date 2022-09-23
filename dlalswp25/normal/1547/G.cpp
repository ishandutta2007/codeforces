#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[404040];
int B[404040];
bool vst[404040];
int col[404040];
int D[404040];
int cid;
vector<int> adj[404040];
vector<int> V;
vector<int> bck[404040];

void dfs(int v) {
	vst[v] = true;
	for(int i : adj[v]) if(!vst[i]) dfs(i);
	V.push_back(v);
}

void dfs2(int v, int c) {
	col[v] = c;
	for(int i : adj[v]) if(!col[i]) dfs2(i, c);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) adj[i].clear();
		V.clear();

		for(int i = 1; i <= N; i++) {
			vst[i] = false;
			col[i] = D[i] = 0;
		}
		cid = 0;

		for(int i = 1; i <= M; i++) {
			scanf("%d%d", &A[i], &B[i]);
			adj[A[i]].push_back(B[i]);
		}

		for(int i = 1; i <= N; i++) if(!vst[i]) dfs(i);
		reverse(V.begin(), V.end());
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= M; i++) adj[B[i]].push_back(A[i]);
		for(int i : V) if(!col[i]) { cid++; dfs2(i, cid); }

		for(int i = 1; i <= cid; i++) bck[i].clear();
		for(int i = 1; i <= M; i++) {
			if(col[A[i]] == col[B[i]]) D[col[A[i]]] = -2;
			else {
				bck[col[B[i]]].push_back(col[A[i]]);
			}
		}

		if(D[col[1]] != -2) D[col[1]] = 1;
		else D[col[1]] = -1;

		for(int i = 1; i <= cid; i++) {
			for(int j : bck[i]) if(D[j] == -1) D[i] = -1;
			if(D[i] == -1 || D[i] == 1) continue;
			int s = 0;
			for(int j : bck[i]) s += D[j];
			if(D[i] == -2 && s) D[i] = -1;
			else D[i] = s;
			if(D[i] > 1) D[i] = 2;
		}
		for(int i = 1; i <= N; i++) printf("%d ", D[col[i]]); puts("");
	}
	return 0;
}