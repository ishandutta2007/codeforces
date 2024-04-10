#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[105];
int S[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
		if(S[N] == X) { puts("NO"); continue; }
		for(int i = 1; i <= N; i++) {
			if(S[i] == X) {
				swap(A[i], A[i + 1]);
				break;
			}
		}
		puts("YES");
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}