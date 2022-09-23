#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[105][2][2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) {
				scanf("%d", &A[i][j][k]);
			}
			if(A[i][0][1] == A[i][1][0]) ok = true;
		}
		if(M % 2 || !ok) { puts("NO"); continue; }
		if(M == 2) { puts("YES"); continue; }
		ok = false;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= i; j++) {
				if(A[i][0][0] == A[j][0][0] && A[i][1][1] == A[j][1][1] && A[i][0][1] == A[j][1][0] && A[i][1][0] == A[j][0][1]) ok = true;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}