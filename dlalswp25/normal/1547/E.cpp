#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, K;
int A[303030];
int B[303030];

priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) A[i] = 0;
		for(int i = 1; i <= K; i++) scanf("%d", &B[i]);
		for(int i = 1; i <= K; i++) {
			int c; scanf("%d", &c);
			pq.emplace(c, B[i]);
		}
		while(pq.size()) {
			int c, x; tie(c, x) = pq.top();
			pq.pop();
			if(A[x] && A[x] <= c) continue;
			A[x] = c;
			if(x > 1) pq.emplace(c + 1, x - 1);
			if(x < N) pq.emplace(c + 1, x + 1);
		}
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}