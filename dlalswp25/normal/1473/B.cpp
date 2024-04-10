#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[25];
char T[25];
char ans[505];

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		scanf("%s", T + 1);
		N = strlen(S + 1); M = strlen(T + 1);
		int g = gcd(N, M);
		for(int i = 0; i < M / g; i++) {
			for(int j = 1; j <= N; j++) {
				ans[i * N + j] = S[j];
			}
		}
		ans[N * M / g + 1] = 0;
		bool ok = true;
		for(int i = 0; i < N / g; i++) {
			for(int j = 1; j <= M; j++) {
				if(ans[i * M + j] != T[j]) ok = false;
			}
		}
		if(!ok) puts("-1");
		else printf("%s\n", ans + 1);
	}
	return 0;
}