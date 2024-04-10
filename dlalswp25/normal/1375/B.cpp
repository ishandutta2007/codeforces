#include <bits/stdc++.h>

using namespace std;

int A[303][303];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M; scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				int c = 4;
				if(i == 1) c--;
				if(i == N) c--;
				if(j == 1) c--;
				if(j == M) c--;
				if(A[i][j] > c) ok = false;
				else A[i][j] = c;
			}
		}

		if(!ok) { puts("NO"); continue; }
		puts("YES");
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) printf("%d ", A[i][j]); puts("");
		}
	}
	return 0;
}