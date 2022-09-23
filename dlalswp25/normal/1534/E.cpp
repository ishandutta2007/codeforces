#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int A[505];
pii B[505];
priority_queue<pii> pq;

int main() {
	int N, K; scanf("%d%d", &N, &K);
	if(N % 2 == 1 && K % 2 == 0) { puts("-1"); return 0; }
	for(int i = 1; i <= N; i++) A[i] = 1;
	int s = N;
	int p = 1, mx = 1;

	while(1) {
		if(s % K == 0) {
			if(mx <= s / K) break;
		}
		s += 2;
		A[p] += 2; mx = max(mx, A[p]);
		p = p % N + 1;
	}

	for(int i = 1; i <= N; i++) pq.emplace(A[i], i);

	int ans = 0;
	while(pq.size() >= K) {
		for(int i = 1; i <= K; i++) { B[i] = pq.top(); pq.pop(); }
		printf("? ");
		for(int i = 1; i <= K; i++) printf("%d ", B[i].second);
		printf("\n"); fflush(stdout);

		int x; scanf("%d", &x);
		ans = ans ^ x;
		for(int i = 1; i <= K; i++) if(B[i].first > 1) pq.emplace(B[i].first - 1, B[i].second);
	}
	printf("! %d\n", ans); fflush(stdout);
	return 0;
}