#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[1010][1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		int x = 0, y = 0;
		for(int i = 1; i <= N; i++) for(int j = i + 1; j <= N; j++) {
			if(A[i][j] == A[j][i]) { x = i; y = j; break; }
		}
		if(x) {
			puts("YES");
			for(int j = 0; j <= M; j++) {
				printf("%d ", (j & 1 ? x : y));
			}
			puts("");
			continue;
		}
		if(M & 1) {
			puts("YES");
			for(int j = 0; j <= M; j++) printf("%d ", (j & 1) + 1);
			puts("");
			continue;
		}
		if(N == 2) { puts("NO"); continue; }

		int z;
		for(int i = 1; i <= N; i++) {
			int va = 0, vb = 0;
			for(int j = 1; j <= N; j++) {
				if(i == j) continue;
				if(A[i][j] == 'a') va = j;
				if(A[i][j] == 'b') vb = j;
			}
			if(va && vb) {
				x = vb; y = i; z = va;
				break;
			}
		}

		puts("YES");
		if(M % 4) {
			for(int j = 0; j <= M; j++) {
				if(j % 4 == 0) printf("%d ", x);
				else if(j % 4 == 1) printf("%d ", y);
				else if(j % 4 == 2) printf("%d ", z);
				else printf("%d ", y);
			}
		}
		else {
			for(int j = 0; j <= M; j++) {
				if(j % 4 == 0) printf("%d ", y);
				else if(j % 4 == 1) printf("%d ", z);
				else if(j % 4 == 2) printf("%d ", y);
				else printf("%d ", x);
			}
		}
		puts("");
	}
	return 0;
}