#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[10][10];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		int y = -1;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == 'R') {
					if(y == -1) y = j;
					else if(j < y) ok = false;
				}
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}