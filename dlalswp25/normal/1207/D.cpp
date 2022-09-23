#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;

int N;
ll F[303030];

struct X {
	int a, b;
}A[303030];

bool cmpa(X s, X t) {
	if(s.a == t.a) return s.b < t.b;
	return s.a < t.a;
}
bool cmpb(X s, X t) { return s.b < t.b; }

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

	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;

	for(int i = 1; i <= N; i++) scanf("%d%d", &A[i].a, &A[i].b);

	ll ans = 0;
	
	ll tmp = 1;
	sort(A + 1, A + N + 1, cmpa);
	int p = 1;
	while(1) {
		int c = 1;
		p++;
		while(A[p].a == A[p - 1].a) { p++; c++; }
		tmp = tmp * F[c] % MOD;
		if(p > N) break;
	}
	ans = (ans + tmp) % MOD;

	sort(A + 1, A + N + 1, cmpb);
	p = 1; tmp = 1;
	while(1) {
		int c = 1;
		p++;
		while(A[p].b == A[p - 1].b) { p++; c++; }
		tmp = tmp * F[c] % MOD;
		if(p > N) break;
	}
	ans = (ans + tmp) % MOD;

	sort(A + 1, A + N + 1, cmpa);

	bool ok = true;
	for(int i = 2; i <= N; i++) if(A[i].b < A[i - 1].b) ok = false;

	tmp = 0;

	if(ok) {
		tmp = 1;
		p = 1;
		while(1) {
			int c = 1;
			p++;
			while(A[p].b == A[p - 1].b && A[p].a == A[p - 1].a) { p++; c++; }
			tmp = tmp * F[c] % MOD;
			if(p > N) break;
		}
	}
	ans = (ans + MOD - tmp) % MOD;

	printf("%lld\n", (F[N] + MOD - ans) % MOD);

	return 0;
}