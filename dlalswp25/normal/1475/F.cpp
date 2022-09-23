#include <bits/stdc++.h>

using namespace std;

int N;
char S[1010];
int A[1010][1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%s", S + 1);
			for(int j = 1; j <= N; j++) A[i][j] = S[j] - '0';
		}
		for(int i = 1; i <= N; i++) {
			scanf("%s", S + 1);
			for(int j = 1; j <= N; j++) A[i][j] ^= S[j] - '0';
		}
		bool ok = true;
		for(int i = 2; i <= N; i++) {
			for(int j = 2; j <= N; j++) {
				if(A[1][1] ^ A[1][j] ^ A[i][1] ^ A[i][j]) ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}