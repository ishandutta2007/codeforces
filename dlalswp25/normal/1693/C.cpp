#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<int> adj[202020];
int deg[202020];
int cnt[202020];
int D[202020];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		deg[a]++;
		adj[b].push_back(a);
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 1; i <= N; i++) D[i] = 1010101010;
	D[N] = 0; pq.emplace(0, N);
	while(pq.size()) {
		int x, d; tie(d, x) = pq.top(); pq.pop();
		if(D[x] < d) continue;
		for(int i : adj[x]) {
			cnt[i]++;
			if(D[i] > d + 1 + deg[i] - cnt[i]) {
				D[i] = d + 1 + deg[i] - cnt[i];
				pq.emplace(D[i], i);
			}
		}
	}
	printf("%d\n", D[1]);
	return 0;
}