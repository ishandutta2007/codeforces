#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[105][105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if((i ^ j ^ A[i][j]) & 1) A[i][j]++;
			}
		}
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) printf("%d ", A[i][j]); puts("");
		}
	}
	return 0;
}