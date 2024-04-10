#include <bits/stdc++.h>

using namespace std;

int A[50];
int B[50];
int N, K;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		sort(A + 1, A + N + 1);
		sort(B + 1, B + N + 1);
		int ans = 0;
		for(int i = 1; i <= N; i++) ans += A[i];

		int l = 1, r = N;
		for(int i = 1; i <= K; i++) {
			if(A[l] > B[r]) break;
			ans += (B[r] - A[l]);
			l++; r--;
		}
		printf("%d\n", ans);
	}
	return 0;
}