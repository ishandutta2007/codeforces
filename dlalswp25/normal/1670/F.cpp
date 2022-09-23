#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
ll L, R, Z, X;
ll ncr[1010][1010];
ll D[65][2020];
ll pw[65656];

ll f(int b, int r) {
	if(b < 0) return 1;
	if(X >> b & 1) r++;
	if(r > 2 * N) return pw[(N - 1) * (b + 1)];
	ll& ret = D[b][r];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = Z >> b & 1; i <= N; i += 2) {
		if(i > r) break;
		ret = (ret + ncr[N][i] * f(b - 1, (r - i) * 2)) % MOD;
	}
	return ret;
}

ll solve(ll x) {
	X = x;
	for(int i = 0; i < 60; i++) {
		for(int j = 0; j <= 2 * N; j++) D[i][j] = -1;
	}
	return f(59, 0);
}

int main() {
	pw[0] = 1;
	for(int i = 1; i <= 65000; i++) pw[i] = pw[i - 1] * 2 % MOD;
	scanf("%d%lld%lld%lld", &N, &L, &R, &Z);
	for(int i = 0; i <= N; i++) ncr[i][0] = 1;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= i; j++) {
		ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
	}
	printf("%lld\n", (solve(R) + MOD - solve(L - 1)) % MOD);
	return 0;
}