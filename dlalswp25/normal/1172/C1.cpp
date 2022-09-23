#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll D[55][55][55][55];
int A[55];
int W[55];
ll S;
ll P;
int N, M;

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

ll f(int t, int n, int c, int p) {
	if(A[t] == 0 && W[t] <= c) return 0;
	if(n == M) {
		if(A[t] == 1) return W[t] + c;
		return W[t] - c;
	}
	if(D[t][n][c][p] != -1) return D[t][n][c][p];

	ll wtc = (A[t] ? W[t] + c : W[t] - c);
	ll sw = S + p - (n - p);
	//printf("%d %d %d %d %lld %lld\n", t, n, c, p, wtc, sw);
	ll isw = inv(sw);
	ll& ret = D[t][n][c][p]; ret = 0;
	ret = (ret + f(t, n + 1, c + 1, p + A[t]) * wtc % MOD * isw) % MOD;
	if(A[t] == 1) {
		ret = (ret + f(t, n + 1, c, p + 1) * (P + p - wtc) % MOD * isw) % MOD; 
		ret = (ret + f(t, n + 1, c, p) * ((S - P) - (n - p)) % MOD * isw) % MOD;
	}
	else {
		ret = (ret + f(t, n + 1, c, p + 1) * (P + p) % MOD * isw) % MOD; 
		ret = (ret + f(t, n + 1, c, p) * ((S - P) - (n - p) - wtc) % MOD * isw) % MOD;
	}
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &W[i]);
		S += W[i];
		if(A[i]) P += W[i];
	}

	for(int i = 0; i < 55; i++) {
		for(int j = 0; j < 55; j++) {
			for(int k = 0; k < 55; k++) {
				for(int l = 0; l < 55; l++) {
					D[i][j][k][l] = -1;
				}
			}
		}
	}

	for(int i = 1; i <= N; i++) printf("%lld\n", f(i, 0, 0, 0));

	return 0;
}