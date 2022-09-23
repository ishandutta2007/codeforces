#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, X;
ll D[505][505];
ll ncr[505][505];
ll pw[505][505];

int main() {
	scanf("%d%d", &N, &X);
	for(int i = 0; i <= N; i++) ncr[i][0] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
	}
	for(int i = 1; i <= X; i++) {
		pw[i][0] = 1;
		for(int j = 1; j <= N; j++) pw[i][j] = pw[i][j - 1] * i % MOD;
	}

	for(int i = 2; i <= N; i++) {
		for(int j = 1; j <= X; j++) {
			if(i - 1 >= j) { D[i][j] = pw[j][i]; continue; }
			D[i][j] = pw[i - 1][i];
			for(int k = 0; k < i; k++) {
				D[i][j] = (D[i][j] + ncr[i][k] * pw[i - 1][k] % MOD * D[i - k][j - i + 1]) % MOD;
			}
		}
	}
	printf("%lld\n", D[N][X]);
	return 0;
}