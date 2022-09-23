#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[205];
int B[205];

int nxt(int p) {
	p++; if(p > 2 * N) p = 1;
	while(A[p]) {
		p++;
		if(p > 2 * N) p = 1;
	}
	return p;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= 2 * N; i++) A[i] = B[i] = 0;
		for(int i = 1; i <= K; i++) {
			int x, y; scanf("%d%d", &x, &y);
			A[x] = y;
			A[y] = x;
		}

		if(N > K) {
			int p = nxt(0); int q = p;
			for(int i = 1; i <= N - K; i++) q = nxt(q);
			for(int i = 1; i <= N - K; i++) {
				B[p] = q; B[q] = p;
				p = nxt(p); q = nxt(q);
			}
		}

		for(int i = 1; i <= 2 * N; i++) A[i] += B[i];

		int ans = 0;
		for(int i = 1; i <= 2 * N; i++) {
			if(i > A[i]) continue;
			for(int j = i + 1; j < A[i]; j++) {
				if(j > A[j]) continue;
				if(A[j] > A[i]) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}