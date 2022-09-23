#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[101010];
int A[202020];
int B[202020];
int C[202020];
int chk[202020];
int ans[202020];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) scanf("%d%d%d", &A[i], &B[i], &C[i]);
	for(int i = 29; i >= 0; i--) {
		for(int j = 1; j <= N; j++) {
			adj[j].clear();
			chk[j] = -1;
		}
		queue<int> q;
		int p = 1;
		for(int j = 1; j <= M; j++) {
			if(~C[j] & 1 << i) {
				if(chk[A[j]] == -1) { chk[A[j]] = 0; q.push(A[j]); }
				if(chk[B[j]] == -1) { chk[B[j]] = 0; q.push(B[j]); }
				continue;
			}
			if(A[j] == B[j]) { chk[A[j]] = 1; continue; }
			adj[A[j]].push_back(B[j]);
			adj[B[j]].push_back(A[j]);
		}

		while(1) {
			while(q.size()) {
				int x = q.front(); q.pop();
				for(int i : adj[x]) chk[i] = 1;
			}
			if(p > N) break;
			while(p <= N && chk[p] != -1) p++;
			if(p <= N) {
				q.push(p);
				chk[p] = 0;
			}
		}

		for(int j = 1; j <= N; j++) ans[j] |= chk[j] << i;
	}
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	return 0;
}