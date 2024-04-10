#include <bits/stdc++.h>

using namespace std;

int A[202020];
int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		int i = N - 1;
		for(; i >= 1; i--) {
			if(A[i] < A[i + 1]) break;
		}

		if(!i) { puts("0"); continue; }
		for(; i >= 1; i--) {
			if(A[i] > A[i + 1]) break;
		}
		printf("%d\n", i);
	}
	return 0;
}