#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];
int cnt[202020];
int indeg[202020];
vector<int> adj[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) { cnt[i] = 0; adj[i].clear(); indeg[i] = 0; }
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			cnt[A[i]]++;
		}
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		int t = max_element(cnt + 1, cnt + N + 1) - cnt;
		for(int i = 1; i <= N; i++) {
			if(A[i] != t && B[i] != t) {
				adj[A[i]].push_back(B[i]);
				indeg[B[i]]++;
			}
		}
		queue<int> q;
		for(int i = 1; i <= N; i++) {
			if(!indeg[i]) q.push(i);
		}
		while(q.size()) {
			int x = q.front(); q.pop();
			for(int i : adj[x]) {
				indeg[i]--;
				if(!indeg[i]) q.push(i);
			}
		}
		puts(*max_element(indeg + 1, indeg + N + 1) ? "WA" : "AC");
	}
	return 0;
}