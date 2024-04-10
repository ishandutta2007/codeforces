#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[101010];
int B[101010];
double P[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= M; i++) scanf("%d%lf", &B[i], &P[i]);
		int x = 0;
		for(int i = N; i >= 1; i--) {
			if(A[i] != i) { x = i; break; }
		}
		if(!x) { puts("1.0"); continue; }
		double ans = 1.0;
		for(int i = 1; i <= M; i++) {
			if(B[i] >= x) ans *= (1 - P[i]);
		}
		printf("%.10f\n", 1 - ans);
	}
	return 0;
}