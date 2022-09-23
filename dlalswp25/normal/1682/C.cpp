#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;
int A[202020];
int L[202020];
int R[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		for(int i = 2; i <= N; i++) {
			L[i] = L[i - 1];
			if(A[i] == A[i - 1]) continue;
			if(i > 2 && A[i - 1] == A[i - 2]) L[i] += 2;
			else L[i]++;
		}
		R[N] = 0;
		for(int i = N - 1; i >= 1; i--) {
			R[i] = R[i + 1];
			if(A[i] == A[i + 1]) continue;
			if(i < N - 1 && A[i + 1] == A[i + 2]) R[i] += 2;
			else R[i]++;
		}
		int ans = 0;
		for(int i = 1; i <= N; i++) ans = max(ans, 1 + L[i] / 2 + R[i] / 2);
		printf("%d\n", ans);
	}
	return 0;
}