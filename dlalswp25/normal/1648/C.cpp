#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int C = 200000;

int N, M;
int cnt[202020];
int A[202020];
ll F[202020];
ll I[202020];

struct BIT {
	ll T[202020];

	void upd(int x, ll v) {
		for(int i = x; i <= C; i += i&-i) T[i] = (T[i] + v) % MOD;
	}
	
	ll get(int x) {
		ll ret = 0;
		for(int i = x; i; i -= i&-i) ret = (ret + T[i]) % MOD;
		return ret;
	}
}fwt;

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
	F[0] = 1;
	for(int i = 1; i <= C; i++) F[i] = F[i - 1] * i % MOD;
	I[C] = inv(F[C]);
	for(int i = C - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	for(int i = 1; i <= M; i++) scanf("%d", &A[i]);

	ll X = 1;

	for(int i = 1; i <= C; i++) {
		fwt.upd(i, cnt[i]);
		X = X * I[cnt[i]] % MOD;
	}

	ll ans = 0;
	for(int i = 1; i <= M; i++) {
		if(i > N) {
			ans = (ans + 1) % MOD; break;
		}
		ans = (ans + F[N - i] * X % MOD * fwt.get(A[i] - 1)) % MOD;
		if(!cnt[A[i]]) break;
		X = X * cnt[A[i]] % MOD;
		fwt.upd(A[i], -1);
		cnt[A[i]]--;
	}
	printf("%lld\n", ans);
	return 0;
}