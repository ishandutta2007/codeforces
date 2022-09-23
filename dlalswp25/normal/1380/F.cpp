#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, Q;
char S[505050];
int A[505050];
ll D[505050];

ll C[20];

struct FWT {
	int T[505050];

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}
	int get(int x) {
		x = min(x, N);
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	int get(int l, int r) { return get(r) - get(l - 1); }
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

ll f(int l, int r) {
	if(r < l) return 1;
	if(l == r) return C[A[r]];
	return (D[r - l] * C[A[r]] % MOD + D[r - l - 1] * C[10 + A[r]] % MOD) % MOD;
}

int getl(int x) {
	int l = 1, r = x - 1;
	while(l <= r) {
		int m = l + r >> 1;
		if(fwt.get(m, x - 1) == x - m) r = m - 1;
		else l = m + 1;
	}
	return l;
}

int getr(int x) {
	int l = x + 1, r = N;
	while(l <= r) {
		int m = l + r >> 1;
		if(fwt.get(x + 1, m) == m - x) l = m + 1;
		else r = m - 1;
	}
	return r;
}

int main() {
	for(int i = 0; i <= 9; i++) C[i] = i + 1;
	for(int i = 10; i <= 18; i++) C[i] = 19 - i;

	scanf("%d%d", &N, &Q);
	scanf("%s", S + 1);
	for(int i = 1; i <= N; i++) A[i] = S[i] - '0';

	D[0] = 1; D[1] = 2;
	for(int i = 2; i <= N; i++) {
		D[i] = (D[i - 1] * 2 + D[i - 2] * 8) % MOD;
	}

	ll ans = 1;
	int l = -1;
	for(int i = 1; i <= N; i++) {
		if(A[i] == 1) {
			fwt.upd(i, 1);
			if(l == -1) l = i;
		}
		else {
			if(l != -1) ans = ans * f(l, i) % MOD;
			else ans = ans * C[A[i]] % MOD;
			l = -1;
		}
	}
	if(l != -1) ans = ans * f(l, N) % MOD;

	while(Q--) {
		int x, d; scanf("%d%d", &x, &d);

		int l = getl(x);
		int r = x;
		if(A[r] == 1) r = min(N, getr(x) + 1);

		ans = ans * inv(f(l, r)) % MOD;

		if(A[x] == 1) {
			if(d == 1) ans = ans * f(l, r) % MOD;
			else {
				fwt.upd(x, -1);
				A[x] = d;
				ans = ans * f(l, x) % MOD;
				ans = ans * f(x + 1, r) % MOD;
			}
		}
		else if(d == 1) {
			int t = min(N, getr(x) + 1);
			ans = ans * inv(f(x + 1, t)) % MOD;

			A[x] = 1;
			fwt.upd(x, 1);
			r = min(N, getr(x) + 1);
			ans = ans * f(l, r) % MOD;
		}
		else {
			A[x] = d;
			ans = ans * f(l, r) % MOD;
		}
		printf("%lld\n", ans);
	}

	return 0;
}