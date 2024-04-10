#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int p = 1;
		for(int i = 1; i <= K; i++) {
			while(p <= N && !A[p]) p++;
			if(p >= N) break;
			A[p]--; A[N]++;
		}
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}