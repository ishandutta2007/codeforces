#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

long long N, M;
long long A[1 << 18], B[1 << 18];
vector<int> X[1 << 18], Y[1 << 18];

long long Q;
long long P[1 << 18];

long long dist[1 << 18];

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		Y[B[i]].push_back(A[i]);
	}
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) scanf("%lld", &P[i]);

	for (int i = 1; i <= N; i++) dist[i] = (1 << 30);
	dist[P[Q]] = 0;
	queue<int> Que; Que.push(P[Q]);
	while (!Que.empty()) {
		int pos = Que.front(); Que.pop();
		for (int i : Y[pos]) {
			if (dist[i] > dist[pos] + 1) {
				dist[i] = dist[pos] + 1;
				Que.push(i);
			}
		}
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= Q - 1; i++) {
		if (dist[P[i]] - 1 != dist[P[i + 1]]) cnt1++;
		int flag = 0;
		for (int j : X[P[i]]) {
			if (dist[P[i]] - 1 == dist[j]) flag++;
		}
		if (dist[P[i]] - 1 != dist[P[i + 1]] || flag >= 2) cnt2++;
	}
	printf("%d %d\n", cnt1, cnt2);
	return 0;
}