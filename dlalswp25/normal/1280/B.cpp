#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[66][66];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

		int cnt = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == 'A') cnt++;
			}
		}
		if(cnt == N * M) { puts("0"); continue; }
		if(cnt == 0) { puts("MORTAL"); continue; }

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i][1] == 'P') ok = false;
		}
		if(ok) { puts("1"); continue; }

		ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i][M] == 'P') ok = false;
		}
		if(ok) { puts("1"); continue; }

		ok = true;
		for(int i = 1; i <= M; i++) {
			if(A[1][i] == 'P') ok = false;
		}
		if(ok) { puts("1"); continue; }

		ok = true;
		for(int i = 1; i <= M; i++) {
			if(A[N][i] == 'P') ok = false;
		}
		if(ok) { puts("1"); continue; }

		if(A[1][1] == 'A' || A[N][1] == 'A' || A[1][M] == 'A' || A[N][M] == 'A') { puts("2"); continue; }

		bool ans = false;
		for(int i = 2; i < N; i++) {
			bool ok = true;
			for(int j = 1; j <= M; j++) {
				if(A[i][j] == 'P') ok = false;
			}
			if(ok) { ans = true; puts("2"); break; }
		}
		if(ans) continue;

		for(int i = 2; i < M; i++) {
			bool ok = true;
			for(int j = 1; j <= N; j++) {
				if(A[j][i] == 'P') ok = false;
			}
			if(ok) { ans = true; puts("2"); break; }
		}
		if(ans) continue;

		for(int i = 1; i <= N; i++) {
			if(A[i][1] == 'A' || A[i][M] == 'A') { ans = true; puts("3"); break; }
		}
		if(ans) continue;

		for(int i = 1; i <= M; i++) {
			if(A[1][i] == 'A' || A[N][i] == 'A') { ans = true; puts("3"); break; }
		}
		if(ans) continue;

		puts("4");
	}

	return 0;
}