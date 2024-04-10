#include <bits/stdc++.h>

using namespace std;

int A[2];
char S[404040];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &A[0], &A[1]);
		scanf("%s", S + 1);
		int N = A[0] + A[1];
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(S[i] != '?') {
				if(S[N - i + 1] != '?') {
					if(S[i] != S[N - i + 1]) ok = false;
				}
				else S[N - i + 1] = S[i];
			}
			else S[i] = S[N - i + 1];
		}

		if(!ok) { puts("-1"); continue; }
		for(int i = 1; i <= N; i++) if(S[i] != '?') A[S[i] - '0']--;

		if(A[0] < 0 || A[1] < 0) { puts("-1"); continue; }
		for(int i = 1; i <= N; i++) {
			if(i > N - i + 1) break;
			if(S[i] == '?') {
				if(i == N - i + 1) {
					if(A[0]) S[i] = '0';
					else S[i] = '1';
				}
				else {
					if(A[0] >= 2) { S[i] = S[N - i + 1] = '0'; A[0] -= 2; }
					else if(A[1] >= 2) { S[i] = S[N - i + 1] = '1'; A[1] -= 2; }
					else ok = false;
				}
			}
		}
		if(!ok) puts("-1");
		else {
			for(int i = 1; i <= N; i++) printf("%c", S[i]); puts("");
		}
	}
	return 0;
}