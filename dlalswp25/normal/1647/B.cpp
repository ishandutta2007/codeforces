#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[105][105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		bool ok = true;
		for(int i = 1; i < N; i++) {
			for(int j = 1; j < M; j++) {
				int c = (A[i][j] - '0') + (A[i][j + 1] - '0') + (A[i + 1][j] - '0') + (A[i + 1][j + 1] - '0');
				if(c == 3) ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}