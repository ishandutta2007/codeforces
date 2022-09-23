#include <bits/stdc++.h>

using namespace std;

int N;
int A[5050];
int C[5050][5050];
int cnt[5050];
int D[5050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N + 1; i++) for(int j = 1; j <= N; j++) C[i][j] = 0;
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) cnt[j] = 0;
			int mx = 0;
			for(int j = i; j <= N; j++) {
				cnt[A[j]]++;
				mx = max(mx, cnt[A[j]]);
				C[i][j] = max(j - i + 1 & 1, mx - (j - i + 1 - mx));
			}
		}
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			D[i] = 1 - C[1][i - 1];
			for(int j = 1; j < i; j++) {
				if(A[j] != A[i]) continue;
				D[i] = max(D[i], D[j] - C[j + 1][i - 1] + 1);
			}
			ans = max(ans, D[i] - C[i + 1][N]);
		}
		printf("%d\n", ans);
	}
	return 0;
}