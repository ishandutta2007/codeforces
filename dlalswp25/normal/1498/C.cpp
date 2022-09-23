#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int N, K;
int D[1010][1010];

int f(int l, int k) {
	if(l == N) return 1;
	if(k == 1) return 1;
	if(D[l][k] != -1) return D[l][k];
	return D[l][k] = (f(N - l, k - 1) + f(l + 1, k)) % MOD;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 0; i <= N; i++) for(int j = 1; j <= K; j++) D[i][j] = -1;
		printf("%d\n", f(0, K));
	}
	return 0;
}