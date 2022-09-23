#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int INF = 1010101010;
const int X = 51;
int N, M;

vector<pii> adj[5151515];
int D[5151515];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		for(int j = 1; j < X; j++) {
			adj[a * X + j].emplace_back(b * X, (j + c) * (j + c));
			adj[b * X + j].emplace_back(a * X, (j + c) * (j + c));
		}
		adj[a * X].emplace_back(b * X + c, 0);
		adj[b * X].emplace_back(a * X + c, 0);
	}

	for(int i = 1; i <= X * N + X; i++) D[i] = INF;
	D[1 * X] = 0;
	pq.emplace(0, X);
	while(pq.size()) {
		int x, d; tie(d, x) = pq.top(); pq.pop();
		if(D[x] < d) continue;
		for(pii i : adj[x]) {
			if(D[i.first] > d + i.second) {
				D[i.first] = d + i.second;
				pq.emplace(D[i.first], i.first);
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		printf("%d ", D[i * X] == INF ? -1 : D[i * X]);
	}
	puts("");

	return 0;
}