#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int INF = 1010101010;

int N, M, K;
int D[1010][1010];

int A[1010];
int B[1010];
vector<pii> adj[1010];

priority_queue<pii, vector<pii>, greater<pii> > pq;

pii Q[1010];

void dijkstra(int s) {
	while(pq.size()) pq.pop();
	for(int i = 1; i <= N; i++) D[s][i] = INF;
	D[s][s] = 0;
	pq.emplace(0, s);
	while(pq.size()) {
		int c = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if(D[s][x] < c) continue;
		for(pii i : adj[x]) {
			if(D[s][i.first] > D[s][x] + i.second) {
				D[s][i.first] = D[s][x] + i.second;
				pq.emplace(D[s][i.first], i.first);
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= M; i++) {
		int c;
		scanf("%d%d%d", &A[i], &B[i], &c);
		adj[A[i]].emplace_back(B[i], c);
		adj[B[i]].emplace_back(A[i], c);
	}
	for(int i = 1; i <= K; i++) scanf("%d%d", &Q[i].first, &Q[i].second);
	for(int i = 1; i <= N; i++) dijkstra(i);

	int ans = INF * 2;
	for(int i = 1; i <= M; i++) {
		int s = 0;
		int x = A[i], y = B[i];
		for(int j = 1; j <= K; j++) {
			int a = Q[j].first, b = Q[j].second;
			s += min(D[a][b], min(D[a][x] + D[b][y], D[a][y] + D[b][x]));
		}
		ans = min(ans, s);
	}
	printf("%d\n", ans);

	return 0;
}