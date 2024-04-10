#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 1000000007;

long long Fibonacci(long long K) {
	long long pa = 1, pb = 0, qa = 1, qb = 0;
	for (int i = 0; i < 60; i++) {
		if ((K / (1LL << i)) % 2 == 1) {
			long long ra = pa * qa + pa * qb + pb * qa; ra %= mod;
			long long rb = pa * qa + pb * qb; rb %= mod;
			qa = ra; qb = rb;
		}
		long long sa = pa * (pa + pb + pb); sa %= mod;
		long long sb = pa * pa + pb * pb; sb %= mod;
		pa = sa; pb = sb;
	}
	return qb;
}

const int Backet = 300;
long long N, Q, A1[100009], A2[100009], S1[509], S2[509], T[509];

void refresh(int G) {
	if (T[G] == 0) return;

	long long r1 = Fibonacci(T[G] + 1), r2 = Fibonacci(T[G]), r3 = Fibonacci(T[G] - 1);
	for (int i = G * Backet; i < (G + 1) * Backet; i++) {
		long long s1 = A1[i] * r1 + A2[i] * r2; s1 %= mod;
		long long s2 = A1[i] * r2 + A2[i] * r3; s2 %= mod;
		A1[i] = s1; A2[i] = s2;
	}
	T[G] = 0;
}

void add_smallrange(int l, int r, int x) {
	int G = l / Backet;
	refresh(G);

	long long r1 = Fibonacci(x + 1), r2 = Fibonacci(x), r3 = Fibonacci(x - 1);
	for (int i = l; i < r; i++) {
		long long s1 = A1[i] * r1 + A2[i] * r2; s1 %= mod;
		long long s2 = A1[i] * r2 + A2[i] * r3; s2 %= mod;
		A1[i] = s1; A2[i] = s2;
	}

	S1[G] = 0; S2[G] = 0;
	for (int i = G * Backet; i < (G + 1)*Backet; i++) {
		S1[G] += A1[i]; if (S1[G] >= mod) S1[G] -= mod;
		S2[G] += A2[i]; if (S2[G] >= mod) S2[G] -= mod;
	}
}

void add(int l, int r, int x) {
	int v1 = l / Backet, v2 = r / Backet;
	if (v1 == v2) add_smallrange(l, r, x);
	else {
		add_smallrange(l, v1 * Backet + Backet, x);

		long long r1 = Fibonacci(x + 1), r2 = Fibonacci(x), r3 = Fibonacci(x - 1);
		for (int i = v1 + 1; i < v2; i++) {
			long long s1 = S1[i] * r1 + S2[i] * r2; s1 %= mod;
			long long s2 = S1[i] * r2 + S2[i] * r3; s2 %= mod;
			S1[i] = s1; S2[i] = s2; T[i] += x;
		}
		add_smallrange(v2 * Backet, r, x);
	}
}

long long smallsum(int l, int r) {
	refresh(l / Backet);
	long long rem = 0;
	for (int i = l; i < r; i++) rem += A1[i];
	return rem % mod;
}

long long sum(int l, int r) {
	int v1 = l / Backet, v2 = r / Backet;
	if (v1 == v2) return smallsum(l, r);
	
	long long rem = 0;
	rem += smallsum(l, v1 * Backet + Backet);
	rem += smallsum(v2 * Backet, r);
	for (int i = v1 + 1; i < v2; i++) rem += S1[i];
	return rem % mod;
}

int main() {
	scanf("%lld%lld", &N, &Q);
	for (int i = 1; i <= N; i++) {
		long long a; scanf("%lld", &a);
		A1[i] = Fibonacci(a); A2[i] = Fibonacci(a - 1);
		S1[i / Backet] += A1[i]; S1[i / Backet] %= mod;
		S2[i / Backet] += A2[i]; S2[i / Backet] %= mod;
	}

	for (int i = 1; i <= Q; i++) {
		int ty; scanf("%d", &ty);
		if (ty == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x); r++;
			add(l, r, x);
		}
		if (ty == 2) {
			int l, r; scanf("%d%d", &l, &r); r++;
			long long v = sum(l, r);
			printf("%lld\n", v);
		}
	}
	return 0;
}