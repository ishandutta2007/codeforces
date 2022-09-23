#include <bits/stdc++.h>

using namespace std;

int N, L, R, K;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%d", &N, &L, &R, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] < L || A[i] > R) continue;
			if(A[i] > K) break;
			ans++; K -= A[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}