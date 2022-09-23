#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
int A[101010];
ll F[101010];
ll I[101010];

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

int main() {
	scanf("%d", &N);
	ll S = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		S += A[i];
	}

	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	I[N] = inv(F[N]);
	for(int i = N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	if(S % N) { puts("0"); return 0; }

	sort(A + 1, A + N + 1);

	ll M = S / N;

	int l = 1, r = 1;
	while(l <= N && A[l] < M) l++;
	while(r <= N && A[r] <= M) r++;
	r--;
	if(l == 1 && r == N) { puts("1"); return 0; }

	ll ans = F[N] * I[r - l + 1] % MOD * I[N - (r - l + 1)] % MOD;
	ll x = F[l - 1], y = F[N - r];

	int c = 1;
	for(int i = 2; i < l; i++) {
		if(A[i] != A[i - 1]) { x = x * I[c] % MOD; c = 1; }
		else c++;
	}
	x = x * I[c] % MOD;

	c = 1;
	for(int i = r + 1; i <= N; i++) {
		if(A[i] != A[i - 1]) { y = y * I[c] % MOD; c = 1; }
		else c++;
	}
	y = y * I[c] % MOD;

	if(l == 2) {
		printf("%lld\n", ans * y % MOD * (N - r + 1) % MOD);
	}
	else if(r == N - 1) {
		printf("%lld\n", ans * x % MOD * l % MOD);
	}
	else {
		printf("%lld\n", ans * x % MOD * y % MOD * 2 % MOD);
	}

	return 0;
}