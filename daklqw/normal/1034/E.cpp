#include <bits/stdc++.h>

const int MAXN = 21;
typedef long long LL;
char S[1 << MAXN | 3], T[1 << MAXN | 3];
int ppc[1 << MAXN], n;
LL A[1 << MAXN], B[1 << MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> S >> T;
	const int U = 1 << n;
	for (int i = 1; i != U; ++i) ppc[i] = ppc[i & i - 1] + 2;
	for (int i = 0; i != U; ++i) A[i] = (LL) (S[i] & 15) << ppc[i];
	for (int i = 0; i != U; ++i) B[i] = (LL) (T[i] & 15) << ppc[i];
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != U; ++j) if (j >> i & 1)
			A[j] += A[j ^ (1 << i)], B[j] += B[j ^ (1 << i)];
	for (int i = 0; i != U; ++i) A[i] *= B[i];
	for (int i = 0; i != n; ++i)
		for (int j = 0; j != U; ++j) if (j >> i & 1)
			A[j] -= A[j ^ (1 << i)];
	for (int i = 0; i != U; ++i) std::cout << (A[i] >> ppc[i] & 3);
	return 0;
}