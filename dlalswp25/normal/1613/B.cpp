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
		for(int i = 1; i <= N / 2; i++) {
			printf("%d %d\n", A[i + 1], A[1]);
		}
	}
	return 0;
}