#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<char> X[404040];
vector<int> dn[404040];
char S[404040];
int Y[404040];

int A[2020202];
int B[2020202];
vector<int> adj[404040];
bool vst[404040];
int col[404040];
int eid, cid;
vector<int> stk;
bool ok[404040];

int idx(int i, int j) { return i * M + j + 1; }

void add_edge(int a, int b) {
	A[eid] = a;
	B[eid] = b;
	eid++;
}

void dfs(int v) {
	vst[v] = true;
	for(int i : adj[v]) if(!vst[i]) dfs(i);
	stk.push_back(v);
}

void dfs2(int v, int c) {
	col[v] = c;
	for(int i : adj[v]) if(!col[i]) dfs2(i, c);
}

int main() {
	scanf("%d%d", &N, &M);

	for(int i = 0; i < N; i++) {
		X[i].resize(M);
		scanf("%s", S);
		for(int j = 0; j < M; j++) X[i][j] = S[j];
	}
	for(int i = 0; i < M; i++) scanf("%d", &Y[i]);

	for(int i = 0; i <= N; i++) dn[i].resize(M);

	for(int j = 0; j < M; j++) dn[N][j] = N;
	for(int i = N - 1; i >= 0; i--) {
		for(int j = 0; j < M; j++) {
			if(X[i][j] == '#') dn[i][j] = i;
			else dn[i][j] = dn[i + 1][j];
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(X[i][j] == '#') {
				int t = dn[i + 1][j];
				if(t < N) add_edge(idx(i, j), idx(t, j));
				if(j) {
					t = dn[i][j - 1];
					if(t < N) add_edge(idx(i, j), idx(t, j - 1));
				}
				if(j < M - 1) {
					t = dn[i][j + 1];
					if(t < N) add_edge(idx(i, j), idx(t, j + 1));
				}
				if(i && X[i - 1][j] == '#') {
					add_edge(idx(i, j), idx(i - 1, j));
				}
			}
		}
	}

	for(int i = 0; i < eid; i++) adj[A[i]].push_back(B[i]);
	for(int i = 1; i <= N * M; i++) if(!vst[i]) dfs(i);
	for(int i = 1; i <= N * M; i++) adj[i].clear();
	for(int i = 0; i < eid; i++) adj[B[i]].push_back(A[i]);
	reverse(stk.begin(), stk.end());
	for(int i : stk) if(!col[i]) { cid++; dfs2(i, cid); }

	for(int i = 1; i <= cid; i++) ok[i] = true;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int t = idx(i, j);
			if(X[i][j] != '#') ok[col[t]] = false;
		}
	}

	for(int i = 0; i < eid; i++) {
		int a = A[i], b = B[i];
		if(col[a] == col[b]) continue;
		ok[col[b]] = false;
	}

	int ans = 0;
	for(int i = 1; i <= cid; i++) ans += ok[i];
	printf("%d\n", ans);
	return 0;
}