#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		printf("0 ");
		for(int i = 2; i <= N; i++) {
			int b = 0;
			for(int j = 0; j < 30; j++) {
				if(A[i - 1] & 1 << j) {
					if(~A[i] & 1 << j) b ^= 1 << j;
				}
			}
			A[i] ^= b;
			printf("%d ", b);
		}
		puts("");
	}
	return 0;
}