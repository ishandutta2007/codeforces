#include <bits/stdc++.h>

using namespace std;

char A[105][150];
int N, M;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

		int ans = 0;
		for(int i = 1; i < N; i++) {
			if(A[i][M] == 'R') ans++;
		}
		for(int i = 1; i < M; i++) {
			if(A[N][i] == 'D') ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}