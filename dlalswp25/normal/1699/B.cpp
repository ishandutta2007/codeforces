#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans[55][55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) ans[i][j] = 0;
		for(int i = 0; i < N / 2; i++) {
			for(int j = 0; j < M / 2; j++) {
				if(i + j & 1) {
					ans[2 * i][2 * j] = ans[2 * i + 1][2 * j + 1] = 1;
				}
				else {
					ans[2 * i][2 * j + 1] = ans[2 * i + 1][2 * j] = 1;
				}
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) printf("%d ", ans[i][j]); puts("");
		}
	}
	return 0;
}