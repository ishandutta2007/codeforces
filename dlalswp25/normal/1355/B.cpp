#include <bits/stdc++.h>

using namespace std;

int A[202020];
int D[202020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);

		for(int i = 1; i <= N; i++) {
			if(A[i] > i) { D[i] = D[i - 1]; continue; }
			D[i] = max(D[i - 1], D[i - A[i]] + 1);
		}
		printf("%d\n", D[N]);
	}
	return 0;
}