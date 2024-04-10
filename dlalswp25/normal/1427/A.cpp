#include <bits/stdc++.h>

using namespace std;

int N;
int A[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int s = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			s += A[i];
		}
		if(s == 0) { puts("NO"); continue; }
		puts("YES");
		sort(A + 1, A + N + 1);
		if(s > 0) {
			reverse(A + 1, A + N + 1);
		}
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}