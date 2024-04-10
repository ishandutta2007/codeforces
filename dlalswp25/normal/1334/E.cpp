#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

vector<ll> P;
int Q, M;
ll D;

vector<int> a;
vector<int> tmp;

ll ncr[1010][1010];

void init() {
	for(int i = 2; (ll)i * i <= D; i++) {
		if(D % i) continue;
		while(D % i == 0) {
			D /= i;
		}
		P.push_back(i);
	}
	if(D > 1) P.push_back(D);

	for(int i = 0; i <= 100; i++) ncr[i][0] = 1;
	for(int i = 1; i <= 100; i++) for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
}

void f(ll x) {
	for(int i = 0; i < M; i++) tmp[i] = 0;
	for(int i = 0; i < M; i++) {
		while(x % P[i] == 0) {
			tmp[i]++; x /= P[i];
		}
		// printf("%d %d\n", i, tmp[i]);
	}
}


int main() {
	scanf("%lld", &D);
	init();

	M = P.size();
	tmp.resize(M);
	a.resize(M);

	// for(ll i : P) printf("%lld ", i); puts("");

	scanf("%d", &Q);
	while(Q--) {
		ll u, v; scanf("%lld%lld", &u, &v);
		f(u);
		for(int i = 0; i < M; i++) a[i] = tmp[i];
		// for(int i : a) printf("%d ", i); puts("");
		f(v);

		int x = 0, y = 0;
		for(int i = 0; i < M; i++) {
			a[i] -= tmp[i];
			if(a[i] < 0) x -= a[i];
			else y += a[i];
		}

		// for(int i : a) printf("%d ", i); puts("");

		ll ans = 1;
		for(int i = 0; i < M; i++) {
			if(a[i] >= 0) continue;
			ans = ans * ncr[x][-a[i]] % MOD;
			x += a[i];
		}
		for(int i = 0; i < M; i++) {
			if(a[i] <= 0) continue;
			ans = ans * ncr[y][a[i]] % MOD;
			y -= a[i];
		}
		printf("%lld\n", ans);
	}

	return 0;
}