#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define MX 601000
using namespace std;

long long l[MX], r[MX], F[MX], G[MX], *f = F, *g = G, N, M, d, D;
long long a, b, last, now, s;
main() {
	long long i, j, k, e;
	for (scanf("%I64d%I64d%I64d", &N, &M, &D); M--; ) {
		scanf("%I64d%I64d%I64d", &a, &b, &now);
		s += b;
		d = 2 * D * (now - last) + 1;
		last = now;
		for (k = 1; k <= N; k += d) {
			e = min(N, k + d - 1);
			for (l[k] = f[k], i = k + 1; i <= e; i++) l[i] = min(l[i - 1], f[i]);
			for (r[e] = f[e], i = e - 1; i >= k; i--) r[i] = min(r[i + 1], f[i]);
		}
		for (i = 1; i <= N; i++) {
			j = max(i - d / 2, 1LL);
			k = min(i + d / 2, N);
			if (j == 1) {
				g[i] = l[k] + abs(a - i);
			} else if (k == N) {
				if (N / d != j / d) g[i] = min(r[j], l[N]) + abs(a - i);
				else g[i] = r[j] + abs(a - i);
			} else {
				g[i] = min(r[j], l[k]) + abs(a - i);
			}
		}
		swap(f, g);
	}
	printf("%I64d\n", s - *min_element(f + 1, f + N + 1));
}