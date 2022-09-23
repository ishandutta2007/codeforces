#include <bits/stdc++.h>

using namespace std;

int N, K;
int D[202][202][202];
char S[202];
char T[3];

int f(int n, int t0, int k) {
	if(n > N) return 0;
	int& ret = D[n][t0][k];
	if(ret != -1) return ret;

	if(S[n] == T[0]) ret = f(n + 1, t0 + 1, k);
	else if(S[n] == T[1]) ret = f(n + 1, t0, k) + t0;
	else ret = f(n + 1, t0, k);

	if(k < K) {
		ret = max(ret, f(n + 1, t0 + 1, k + 1));
		ret = max(ret, f(n + 1, t0, k + 1) + t0);
	}

	return ret;
}

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", S + 1);
	scanf("%s", T);

	if(T[0] == T[1]) {
		int cnt = 0;
		for(int i = 1; i <= N; i++) cnt += (S[i] == T[0]);
		cnt = min(N, cnt + K);
		printf("%d\n", cnt * (cnt - 1) / 2);
		return 0;
	}

	for(int i = 0; i < 202; i++) for(int j = 0; j < 202; j++) for(int k = 0; k < 202; k++) D[i][j][k] = -1;

	printf("%d\n", f(1, 0, 0));

	return 0;
}