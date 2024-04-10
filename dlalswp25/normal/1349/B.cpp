#include <bits/stdc++.h>

using namespace std;

int A[101010];
int S[101010];
int N, K;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(A[i] == K) ok = true;
		}
		if(!ok) { puts("no"); continue; }

		if(N == 1) {
			puts("yes"); continue;
		}

		int mn = 1010101010;
		ok = false;
		for(int i = 1; i <= N; i++) {
			if(A[i] >= K) S[i] = S[i - 1] + 1;
			else S[i] = S[i - 1] - 1;
			if(S[i] - mn > 0) ok = true;
			mn = min(mn, S[i - 1]);
		}
		// for(int i = 1; i <= N; i++) printf("%d ", S[i]); puts("");
		puts(ok ? "yes" : "no");
	}
	return 0;
}