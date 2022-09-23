#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		A[N + 1] = 0;
		int ans = 0;
		for(int i = 2; i < N; i++) {
			if(A[i] > A[i - 1] && A[i] > A[i + 1]) {
				ans++;
				A[i + 1] = max(A[i], A[i + 2]);
			}
		}
		printf("%d\n", ans);
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}