#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		printf("%d\n", N / 2);
		for(int i = 1; i < N; i += 2) {
			printf("%d %d %d %d\n", i, i + 1, min(A[i], A[i + 1]), 1000000007);
		}
	}
	return 0;
}