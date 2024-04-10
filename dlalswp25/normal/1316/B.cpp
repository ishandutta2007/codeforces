#include <bits/stdc++.h>

using namespace std;

char S[5050][5050];
char A[5050];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		scanf("%s", A + 1);

		int mn = 0;

		for(int i = 1; i <= N; i++) {
			int c = 1;
			for(int j = i; j <= N; j++) { S[i][c] = A[j]; c++; }

			if((i % 2) == (N % 2)) {
				for(int j = i - 1; j >= 1; j--) { S[i][c] = A[j]; c++; }
			}
			else {
				for(int j = 1; j <= i - 1; j++) { S[i][c] = A[j]; c++; }
			}

			// for(int j = 1; j <= N; j++) printf("%c", S[i][j]); puts("");

			if(!mn) mn = i;
			else {
				bool ok = false;
				for(int j = 1; j <= N; j++) {
					if(S[mn][j] < S[i][j]) break;
					if(S[mn][j] > S[i][j]) { ok = true; break; }
				}

				if(ok) mn = i;
			}
		}
		for(int i = 1; i <= N; i++) printf("%c", S[mn][i]); puts("");
		printf("%d\n", mn);
	}
	return 0;
}