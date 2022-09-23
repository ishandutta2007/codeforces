#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		scanf("%d", &M);
		int s = 0;
		for(int i = 1; i <= M; i++) {
			int b; scanf("%d", &b);
			s = (s + b) % N;
		}
		printf("%d\n", A[s % N + 1]);
	}
	return 0;
}