#include <bits/stdc++.h>

using namespace std;

int N;
char A[55];
char B[55];
char S[10] = "abacaba";

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);

		bool ans = false;

		for(int i = 1; i <= N - 6; i++) {
			for(int j = 1; j <= N; j++) B[j] = A[j];
			bool ok = true;

			for(int j = 0; j < 7; j++) {
				if(A[i + j] != S[j] && A[i + j] != '?') ok = false;
				else B[i + j] = S[j];
			}

			if(!ok) continue;

			for(int j = 1; j <= N - 6; j++) {
				if(i == j) continue;
				bool tmp = true;
				for(int k = 0; k < 7; k++) {
					if(B[j + k] != S[k]) tmp = false;
				}
				if(tmp) ok = false;
			}

			if(ok) {
				for(int j = 1; j <= N; j++) if(B[j] == '?') B[j] = 'z';
				ans = true;
				break;
			}
		}

		if(ans) {
			puts("Yes");
			for(int i = 1; i <= N; i++) printf("%c", B[i]); puts("");
		}
		else puts("No");
	}
	return 0;
}