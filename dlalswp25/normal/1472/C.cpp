#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int D[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int ans = 0;
		for(int i = N; i >= 1; i--) {
			D[i] = A[i];
			if(i + A[i] <= N) D[i] += D[i + A[i]];
			ans = max(ans, D[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}