#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[105][105];
int X[205];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 2; i <= N + M; i++) X[i] = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				scanf("%d", &A[i][j]);
				X[i + j] ^= A[i][j];
			}
		}

		bool ok = false;
		for(int i = 2; i <= N + M; i++) if(X[i]) ok = true;
		puts(ok ? "Ashish" : "Jeel");
	}
	return 0;
}