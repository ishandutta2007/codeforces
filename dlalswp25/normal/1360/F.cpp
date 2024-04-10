#include <bits/stdc++.h>

using namespace std;

char A[15][15];
int N, M;
char ans[15];
bool ok;

void f() {
	if(N == 1) { ok = true; return; }
	for(int i = 2; i <= N; i++) {
		int diff = 0;
		for(int j = 1; j <= M; j++) {
			if(ans[j] != 0) {
				if(A[i][j] != ans[j]) diff++;
			}
		}
		if(!diff) continue;
		if(diff >= 2) return;

		int x = 0;
		for(int j = 1; j <= M; j++) {
			if(!ans[j]) { x++; ans[j] = A[i][j]; }
		}
	}
	ok = true; return;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

		ok = false;

		for(int i = 1; i <= M; i++) {
			ok = false;
			for(int j = 1; j <= M; j++) {
				if(i == j) ans[j] = 0;
				else ans[j] = A[1][j];
			}
			// for(int j = 1; j <= M; j++) printf("%c", ans[j]); puts("");
			f();
			if(ok) break;
		}
		if(!ok) puts("-1");
		else {
			for(int i = 1; i <= M; i++) {
				if(!ans[i]) ans[i] = 'a';
				printf("%c", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}