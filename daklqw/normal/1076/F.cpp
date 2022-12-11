#include <bits/stdc++.h>

const int MAXN = 300010;
typedef long long LL;
int n, K;
int A[MAXN], B[MAXN];
int calc(int x, int y, int l, int m) {
	if (l > K || m > K) return K + 1;
	if (x <= y) return (LL) x * K - m < y ? K + 1 : 1;
	return std::min(std::max(x + l - (LL) y * K, 0ll), K + 1ll);
}
int r(int x, int y) { return x <= K ? y : K + 1; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= n; ++i) std::cin >> B[i];
	int f = 0, g = 0;
	for (int i = 1, nf, ng; i <= n; ++i) {
		nf = std::min(calc(A[i], B[i], f, 0), calc(A[i], B[i], 0, g));
		ng = std::min(calc(B[i], A[i], g, 0), calc(B[i], A[i], 0, f));
		f = nf, g = ng;
	}
	std::cout << (f <= K || g <= K ? "YES" : "NO") << std::endl;
	return 0;
}