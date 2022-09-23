#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
char X[1010];
char Y[1010];

ll D[1010][1010];
ll E[1010][1010];

int main() {
	scanf("%s", X + 1);
	scanf("%s", Y + 1);
	N = strlen(X + 1);
	M = strlen(Y + 1);

	for(int i = 1; i <= N; i++) {
		D[i][0] = (X[i] == X[i - 1] ? 0 : D[i - 1][0]) + 1;
	}
	for(int i = 1; i <= M; i++) {
		E[0][i] = (Y[i] == Y[i - 1] ? 0 : E[0][i - 1]) + 1;
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(X[i] != X[i - 1]) D[i][j] = D[i - 1][j];
			if(X[i] != Y[j]) {
				D[i][j] = (D[i][j] + E[i - 1][j]) % MOD;
				if(i > 1) D[i][j] = (D[i][j] + E[0][j]) % MOD;
			}
			if(Y[j] != Y[j - 1]) E[i][j] = E[i][j - 1];
			if(X[i] != Y[j]) {
				E[i][j] = (E[i][j] + D[i][j - 1]) % MOD;
				if(j > 1) E[i][j] = (E[i][j] + D[i][0]) % MOD;
			}
			ans = (ans + D[i][j] + E[i][j]) % MOD;
		}
	}

	printf("%lld\n", ans);

	return 0;
}