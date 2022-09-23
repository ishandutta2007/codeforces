#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
int A[8585858];
int B[8585858][24];
int C[24][26];
char S[20202];
int mn[26];
ll I[26];

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

void f(int n, int state) {
	if(n >= N) {
		if(!state) return;
		ll t = 1;
		for(int j = 0; j < 26; j++) t = t * (mn[j] + 1) % MOD;
		A[state] = t;
		return;
	}
	f(n + 1, state);
	int tmp[26];
	for(int j = 0; j < 26; j++) tmp[j] = mn[j];
	for(int j = 0; j < 26; j++) mn[j] = min(mn[j], C[n][j]);
	f(n + 1, state | 1 << n);
	for(int j = 0; j < 26; j++) mn[j] = tmp[j];
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) I[i] = inv(i);

	for(int i = 0; i < N; i++) {
		scanf("%s", S + 1);
		int M = strlen(S + 1);
		int p = 1;
		for(int j = 0; j < 26; j++) {
			char c = 'a' + j;
			int bef = p;
			while(p <= M && S[p] <= c) p++;
			C[i][j] = p - bef;
		}
	}

	for(int i = 0; i < 26; i++) mn[i] = 20202;
	f(0, 0);

	for(int i = 1; i < 1 << N; i++) {
		int b = 0;
		for(int j = 0; j < N; j++) {
			if(~i & 1 << j) continue;
			b++;
		}
		for(int j = 0; j < N; j++) {
			if(~i & 1 << j) continue;
			for(int k = 1; k < b; k++) {
				B[i][k] = (B[i][k] + B[i ^ 1 << j][k]) % MOD;
			}
		}
		for(int k = 1; k <= b - 1; k++) B[i][k] = B[i][k] * I[b - k] % MOD;
		B[i][b] = A[i];
	}

	ll ans = 0;
	for(int i = 1; i < 1 << N; i++) {
		int b = 0, s = 0;
		for(int j = 0; j < N; j++) {
			if(i & 1 << j) {
				b++; s += j + 1;
			}
		}

		ll x = 0;
		for(int j = 1; j <= b; j++) {
			// printf("%d %d b %d\n", i, j, B[i][j]);
			ll t = B[i][j];
			if(j % 2 == 0) t = (MOD - t) % MOD;
			x = (x + t) % MOD;
		}
		// printf("%d %lld\n", i, x);
		ans = ans ^ (x * b * s);
	}
	printf("%lld\n", ans);
	return 0;
}