#include <bits/stdc++.h>

using namespace std;

char A[55][55];
int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		// for(int i = 1; i <= N; i++) {
		// 	for(int j = 1; j <= N; j++) printf("%c ", A[i][j]); puts("");
		// }
		bool ok = true;
		for(int i = 1; i < N; i++) {
			for(int j = 1; j < N; j++) {
				if(A[i][j] == '1' && A[i + 1][j] == '0' && A[i][j + 1] == '0') ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}