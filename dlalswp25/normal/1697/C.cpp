#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];
char B[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		bool ans = true;
		for(int i = 1; i <= N; ) {
			int cntA[3] = {0, 0, 0};
			int cntB[3] = {0, 0, 0};
			int l = i;
			for(int j = i; j <= N; j++) {
				cntA[A[j] - 'a']++;
				cntB[B[j] - 'a']++;
				bool fg = true;
				for(int k = 0; k < 3; k++) if(cntA[k] != cntB[k]) fg = false;
				if(fg) {
					i = j + 1; break;
				}
			}
			for(int k = 0; k < 3; k++) if(cntA[k] != cntB[k]) ans = false;
			if(cntA[0] && cntA[2]) ans = false;
			for(int j = l; j < i; j++) {
				if(A[j] < B[j]) break;
				if(A[j] > B[j]) { ans = false; break; }
			}
			if(!ans) break;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}