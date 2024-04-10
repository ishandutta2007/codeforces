#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110000;

vector<int> f;
long long g[MAXN], c[MAXN], d[MAXN], e[MAXN], r[MAXN];

void add(int u, int sgn, long long &cur, long long p) {
	for (auto q : f) {
		while (u % q == 0) {
			if (sgn > 0) g[q] *= q;
			else g[q] /= q;
			u /= q;
		}
	}
	if (sgn > 0) cur = cur * u % p;
	else cur = cur * r[u] % p;
}

long long solve(int n, int m, long long p) {
	if (m < 0) return 0;
	{
		long long cur = 1;
		for (auto q : f) g[q] = 1;
		for (int i = 0; i <= n/2; i++) {
			c[i] = cur;
			for (auto q : f) c[i] = c[i] * g[q] % p;
			c[n-i] = c[i];
			add(n-i, 1, cur, p), add(i+1, -1, cur, p);
		}
	}
	{
		long long cur = 1;
		for (auto q : f) g[q] = 1;
		for (int i = 0; i <= n; i++) {
			d[i] = cur;
			for (auto q : f) d[i] = d[i] * g[q] % p;
			add(i+1, 1, cur, p), add(i/2+1, -1, cur, p);
		}
	}
	{
		long long cur = 1;
		for (auto q : f) g[q] = 1;
		for (int i = 0; i <= m; i++) e[i] = 0;
		for (int i = m+1; i <= n; i++) {
			e[i] = cur;
			for (auto q : f) e[i] = e[i] * g[q] % p;
			add(i+1, 1, cur, p);
			if (i+m&1) add((i+1+m)/2+1, -1, cur, p);
			else add((i-m)/2, -1, cur, p);
		}
	}
	long long ret = 0;
	for (int i = 0; i <= n; i++) ret = (ret + c[i] * ((d[i] - e[i] + p) % p)) % p;
	return ret;
}

long long extEuclid(long long a, long long b, long long &x, long long &y) {
	if (!b) { x = 1, y = 0; return a; }
	long long d = extEuclid(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

int main() {
	int n, L, R; long long p; scanf("%d%lld%d%d", &n, &p, &L, &R);
	for (int q = p, i = 2; i <= n+1; i++) if (q % i == 0) {
		while (q % i == 0) q /= i;
		f.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		long long x; extEuclid(i, p, r[i], x), r[i] = (r[i] % p + p) % p;
	}
	printf("%lld\n", (solve(n, R, p) - solve(n, L-1, p) + p) % p);
	return 0;
}