#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
char S[3030];
char T[3030];

ll D[3030][3030];

ll f(int n, int lft) {
	if(n >= N) {
		return (lft == 1);
	}

	ll& ret = D[n][lft];
	if(ret != -1) return ret;

	ret = 0;
	if(lft + n - 1 > N) return ret = 0;

	if(n >= M && lft == 1) ret = 1;

	if(lft > M) {
		ret = (ret + 2 * f(n + 1, lft)) % MOD;
		if(T[M] == S[n + 1]) ret = (ret + f(n + 1, M)) % MOD;
		return ret;
	}

	if(lft > 1 && T[lft - 1] == S[n + 1]) ret = (ret + f(n + 1, lft - 1)) % MOD;
	if(lft + n <= M) {
		if(T[lft + n] == S[n + 1]) ret = (ret + f(n + 1, lft)) % MOD;
	}
	else ret = (ret + f(n + 1, lft)) % MOD;
	return ret;
}

int main() {
	scanf("%s", S + 1);
	scanf("%s", T + 1);
	N = strlen(S + 1);
	M = strlen(T + 1);

	ll ans = 0;
	for(int i = 0; i < 3030; i++) for(int j = 0; j < 3030; j++) D[i][j] = -1;

	for(int i = 1; i <= M; i++) {
		if(T[i] == S[1]) ans = (ans + f(1, i)) % MOD;
	}
	ans = (ans + f(1, M + 1)) % MOD;
	printf("%lld\n", ans * 2 % MOD);

	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M + 1; j++) printf("%lld ", f(i, j)); puts("");
	// }

	return 0;
}