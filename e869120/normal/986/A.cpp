#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, S, K, A[1 << 17], dist[109][1 << 17];
vector<int>X[1 << 17], G[1 << 17];

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &S);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); X[A[i]].push_back(i); }
	for (int i = 1; i <= M; i++) { int p1, p2; scanf("%d%d", &p1, &p2); G[p1].push_back(p2); G[p2].push_back(p1); }

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) dist[i][j] = (1 << 30);

		queue<int>Q;
		for (int j : X[i]) { dist[i][j] = 0; Q.push(j); }
		while (!Q.empty()) {
			int pos = Q.front(); Q.pop();
			for (int j = 0; j < G[pos].size(); j++) {
				if (dist[i][G[pos][j]] > dist[i][pos] + 1) {
					dist[i][G[pos][j]] = dist[i][pos] + 1;
					Q.push(G[pos][j]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i >= 2) printf(" ");
		vector<int>vec;
		for (int j = 1; j <= K; j++) vec.push_back(dist[j][i]);
		sort(vec.begin(), vec.end());

		int sum = 0;
		for (int j = 0; j < S; j++) sum += vec[j];
		printf("%d", sum);
	}
	printf("\n");
	return 0;
}