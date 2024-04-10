#include <bits/stdc++.h>

using namespace std;

int N, M;
int id;
int A[1010101];
int B[1010101];

vector<int> adj[1010101];
vector<int> st;
bool vst[1010101];
int col[1010101];
vector<int> ans1, ans2;

int cid;

void dfs(int v) {
	vst[v] = true;
	for(int i : adj[v]) {
		if(vst[i]) continue;
		dfs(i);
	}
	st.push_back(v);
}

void dfs2(int v, int c) {
	col[v] = c;
	for(int i : adj[v]) {
		if(col[i]) continue;
		dfs2(i, c);
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("\n");
		id = cid = 0;

		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			if(a == b) continue;
			id++; A[id] = a; B[id] = b;
		}

		for(int i = 1; i <= id; i++) adj[A[i]].push_back(B[i]);
		for(int i = 1; i <= N; i++) if(!vst[i]) dfs(i);
		for(int i = 1; i <= N; i++) adj[i].clear();	
		for(int i = 1; i <= id; i++) adj[B[i]].push_back(A[i]);
		reverse(st.begin(), st.end());
		for(int i : st) if(!col[i]) { cid++; dfs2(i, cid); }

		if(cid == 1) puts("No");
		else {
			puts("Yes");
			for(int i = 1; i <= N; i++) {
				if(col[i] == cid) ans1.push_back(i);
				else ans2.push_back(i);
			}
			printf("%d %d\n", ans1.size(), ans2.size());
			for(int i : ans1) printf("%d ", i); puts("");
			for(int i : ans2) printf("%d ", i); puts("");
			ans1.clear(); ans2.clear();
		}
		st.clear();
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N; i++) { vst[i] = false; col[i] = 0; }
	}

	return 0;
}