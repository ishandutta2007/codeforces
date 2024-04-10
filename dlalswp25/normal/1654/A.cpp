#include <bits/stdc++.h>

using namespace std;

int N;
int A[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		printf("%d\n", A[N - 1] + A[N]);
	}
	return 0;
}