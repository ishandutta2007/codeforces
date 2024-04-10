#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];
bool C[202020];
int R[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		C[N + 1] = true;
		for(int i = N; i >= 1; i--) {
			if(C[i + 1]) R[i] = i;
			else R[i] = R[i + 1];
			if(A[i] > B[i - 1]) C[i] = true;
			else C[i] = false;
		}
		for(int i = 1; i <= N; i++) {
			printf("%d ", *lower_bound(B + 1, B + N + 1, A[i]) - A[i]);
		}
		puts("");
		for(int i = 1; i <= N; i++) {
			printf("%d ", B[R[i]] - A[i]);
		}
		puts("");
	}
	return 0;
}