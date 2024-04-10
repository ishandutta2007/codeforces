#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		int mn = 1010101010, mx = -1;
		int m = 0, k = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == -1) {
				if(i > 1 && A[i - 1] != -1) { mn = min(mn, A[i - 1]); mx = max(mx, A[i - 1]); }
				if(i < N && A[i + 1] != -1) { mn = min(mn, A[i + 1]); mx = max(mx, A[i + 1]); }
			}
			if(A[i] != -1 && A[i + 1] != -1 && i < N) m = max(m, abs(A[i + 1] - A[i]));
		}

		printf("%d %d\n", max(m, (mx - mn + 1) / 2), (mx + mn) / 2);
	}
	return 0;
}