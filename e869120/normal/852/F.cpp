#include <cstdio>
int N, M, a, Q, g, pw[1100009], fact[1100009], inv[1100009], finv[1100009], ans[1100009];
int comb(int n, int k) {
	return 1LL * fact[n] * finv[k] % g * finv[n - k] % g;
}
int main() {
	scanf("%d %d %d %d", &N, &M, &a, &Q);
	int mul = 1; pw[0] = 1;
	while (g == 0 || pw[g] != 1) pw[g + 1] = 1LL * pw[g] * a % Q, g++;
	fact[0] = 1;
	for (int i = 1; i < g; i++) fact[i] = 1LL * fact[i - 1] * i % g;
	inv[1] = 1;
	for (int i = 2; i < g; i++) inv[i] = 1LL * inv[g % i] * (g - g / i) % g;
	finv[0] = 1;
	for (int i = 1; i < g; i++) finv[i] = 1LL * finv[i - 1] * inv[i] % g;
	for (int i = N - 1; i >= 0; i--) {
		ans[i] = ans[i + 1];
		if (N - i - 1 <= M) {
			ans[i] += comb(M, N - i - 1);
			if (ans[i] >= g) ans[i] -= g;
		}
	}
	for (int i = 0; i < N; i++) printf("%d ", pw[ans[i]]);
	return 0;
}