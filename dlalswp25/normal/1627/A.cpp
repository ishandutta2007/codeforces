#include <bits/stdc++.h>

using namespace std;

int N, M, R, C;
char A[55][55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%d", &N, &M, &R, &C);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		if(A[R][C] == 'B') { puts("0"); continue; }
		int b = 0;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) b += (A[i][j] == 'B');
		if(!b) { puts("-1"); continue; }
		b = 0;
		for(int i = 1; i <= N; i++) b += (A[i][C] == 'B');
		for(int j = 1; j <= M; j++) b += (A[R][j] == 'B');
		if(b) puts("1");
		else puts("2");
	}
	return 0;
}