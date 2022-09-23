#include <bits/stdc++.h>

using namespace std;

int A[55][55];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, M; scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);

		int r = N, c = M;
		for(int i = 1; i <= N; i++) {
			int ok = 0;
			for(int j = 1; j <= M; j++) ok |= A[i][j];
			r -= ok;
		}
		for(int j = 1; j <= M; j++) {
			int ok = 0;
			for(int i = 1; i <= N; i++) ok |= A[i][j];
			c -= ok;
		}

		puts(min(r, c) & 1 ? "Ashish" : "Vivek");
	}
	return 0;
}