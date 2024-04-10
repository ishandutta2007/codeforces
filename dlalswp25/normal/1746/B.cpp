#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int L[101010];
int R[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) L[i] = L[i - 1] + (A[i] == 1);
		R[N + 1] = 0;
		for(int i = N; i >= 1; i--) R[i] = R[i + 1] + (A[i] == 0);
		int ans = N;
		for(int i = 0; i <= N; i++) ans = min(ans, max(L[i], R[i + 1]));
		printf("%d\n", ans);
	}
	return 0;
}