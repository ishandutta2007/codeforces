#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		if(N == 2 && A[1] == 1 && A[2] == 2) {
			puts("2"); continue;
		}
		int ans = (A[N] + 2) / 3;
		if(A[N] % 3 == 0) {
			bool ok = true;
			for(int i = 1; i < N; i++) {
				if(A[i] % 3) ok = false;
			}
			if(!ok) ans++;
		}
		else {
			bool ok = true;
			for(int i = 1; i < N; i++) {
				if(A[i] % 3 && A[i] % 3 != A[N] % 3) ok = false;
			}
			if(!ok) {
				int t = -1;
				for(int i = N - 1; i >= 1; i--) {
					if(A[i] != A[N]) {
						t = A[i]; break;
					}
				}
				if(!(A[N] % 3 == 1 && t != A[N] - 1 && A[1] != 1)) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}