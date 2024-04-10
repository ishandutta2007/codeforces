#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[202020];
char T[202020];
int L[202020];
int R[202020];

int main() {
	scanf("%d%d", &N, &M);
	scanf("%s", S + 1);
	scanf("%s", T + 1);
	int p = 1;
	for(int i = 1; i <= M; i++) {
		while(S[p] != T[i]) p++;
		L[i] = p; p++;
	}
	p = N;
	for(int i = M; i >= 1; i--) {
		while(S[p] != T[i]) p--;
		R[i] = p; p--;
	}

	int ans = 0;
	for(int i = 1; i < M; i++) {
		ans = max(ans, R[i + 1] - L[i]);
	}
	printf("%d\n", ans);
	return 0;
}