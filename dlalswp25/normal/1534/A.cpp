#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[105][105];
char B[105][105];

bool chk() {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(A[i][j] != '.' && A[i][j] != B[i][j]) return false;
		}
	}
	return true;
}

void print() {
	puts("YES");
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) printf("%c", B[i][j]); puts("");
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				B[i][j] = (i + j & 1 ? 'R' : 'W');
			}
		}
		if(chk()) { print(); continue; }

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				B[i][j] = (i + j & 1 ? 'W' : 'R');
			}
		}
		if(chk()) { print(); continue; }
		puts("NO");
	}
	return 0;
}