#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		if(A[N - 1] > A[N]) { puts("-1"); continue; }
		bool ok = true;
		for(int i = 1; i < N; i++) if(A[i] > A[i + 1]) ok = false;
		if(ok) { puts("0"); continue; }
		if(A[N] < 0) { puts("-1"); continue; }
		printf("%d\n", N - 2);
		for(int i = 1; i <= N - 2; i++) printf("%d %d %d\n", i, N - 1, N);
	}
	return 0;
}