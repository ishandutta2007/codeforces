#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);

		int mn = A[N] - A[1];
		int idx = 1;

		for(int i = 2; i <= N; i++) {
			if(A[i] - A[i - 1] < mn) {
				mn = A[i] - A[i - 1];
				idx = i;
			}
		}

		for(int i = idx; i <= N; i++) printf("%d ", A[i]);
		for(int i = 1; i < idx; i++) printf("%d ", A[i]);
		puts("");
	}
	return 0;
}