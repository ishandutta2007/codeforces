#include <bits/stdc++.h>

using namespace std;

int N, M, A, B;

int ans[55][55];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &N, &M, &A, &B);
		if(N * A != M * B) { puts("NO"); continue; }
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) ans[i][j] = 0;
		int x = 1;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= A; j++) {
				ans[i][x] = 1;
				x++; if(x > M) x = 1;
			}
		}
		puts("YES");
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) printf("%d", ans[i][j]);
			puts("");
		}
	}
	return 0;
}