#include <iostream>
#include <set>
using namespace std;
#pragma warning (disable: 4996)

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b & (1LL << i)) != 0) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

const long long mod = 998244353;
long long N, Q;
long long P1[1 << 18];
long long P2[1 << 18];
long long P3[1 << 18];
long long P4[1 << 18];
bool G[1 << 18];

set<int> Set;
long long ans = 0;

long long ranged(int l, int r) {
	long long EXPTIME = Div(P2[l - 1], P2[r], mod);
	EXPTIME = (EXPTIME + mod - 1LL) % mod;

	long long EXPFAIL = Div((P2[l - 1] - P2[r] + mod) % mod, P2[l - 1], mod);

	long long EXPVAL = Div((P4[r] - P4[l - 1] + mod) % mod, P2[l - 1], mod);

	long long EXPNUM = Div(EXPVAL, EXPFAIL, mod); EXPNUM = (EXPNUM - (l - 1) + mod) % mod;

	return (EXPTIME * EXPNUM) % mod;
}

void add(int v) {
	auto itr1 = Set.lower_bound(v);
	int cr = (*itr1); itr1--;
	int cl = (*itr1);

	G[v] = true;
	ans -= ranged(cl, cr - 1);
	ans += ranged(cl, v - 1);
	ans += ranged(v, cr - 1);
	ans = (ans + mod * mod) % mod;
	Set.insert(v);
}

void lose(int v) {
	Set.erase(v);
	auto itr1 = Set.lower_bound(v);
	int cr = (*itr1); itr1--;
	int cl = (*itr1);

	G[v] = false;
	ans += ranged(cl, cr - 1);
	ans -= ranged(cl, v - 1);
	ans -= ranged(v, cr - 1);
	ans = (ans + mod * mod) % mod;
}

int main() {
	scanf("%lld%lld", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &P1[i]);
		P1[i] = Div(P1[i], 100, mod);
	}
	P2[0] = 1;
	for (int i = 1; i <= N; i++) P2[i] = (P2[i - 1] * P1[i]) % mod;
	for (int i = 1; i <= N; i++) P3[i] = (P2[i - 1] * (1LL - P1[i] + mod)) % mod;
	for (int i = 1; i <= N; i++) P4[i] = (1LL * i * P3[i]) % mod;
	for (int i = 1; i <= N; i++) P4[i] = (P4[i] + P4[i - 1]) % mod;

	Set.insert(1);
	Set.insert(N + 1);
	ans += ranged(1, N);

	for (int i = 1; i <= Q; i++) {
		int d; scanf("%d", &d);
		if (G[d] == false) add(d);
		else lose(d);

		printf("%lld\n", (ans + N) % mod);
	}
	return 0;
}