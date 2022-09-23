#include <bits/stdc++.h>

using namespace std;

int N;
char A[305][305];
char B[305][305];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		int tot = 0;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) if(A[i][j] == 'X') tot++;
		for(int t = 0; t < 3; t++) {
			for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) B[i][j] = A[i][j];
			int cnt = 0;
			for(int i = 1; i <= N; i++) {
				int j = (i + t) % 3 + 1;
				for(; j <= N; j += 3) if(A[i][j] == 'X') { cnt++; B[i][j] = 'O'; }
			}
			if(tot / 3 >= cnt) break;
		}
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) printf("%c", B[i][j]); puts("");
		}
	}
	return 0;
}