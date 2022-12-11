#include <bits/stdc++.h>

typedef unsigned ll;
const int MAXN = 150;
ll res[MAXN], A[MAXN];
int n, m, Q;
void conv(ll * A, ll * B, ll * tar) {
	static ll tmp[MAXN];
	memset(tmp, 0, m + 1 << 2);
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j + i <= m; ++j)
			tmp[i + j] += A[i] * B[j];
	memcpy(tar, tmp, m + 1 << 2);
}
int main() {
	std::cin >> n >> m >> Q;
	m = std::min(n - 1, m);
	res[0] = A[0] = A[1] = 1;
	for (; n; n >>= 1, conv(A, A, A)) if (n & 1) conv(A, res, res);
	ll ans = 0;
	for (int i = 1; i <= Q; ++i) {
		ll now = 0, pw = i;
		for (int j = 0; j <= m; ++j) {
			now += pw * res[j];
			pw *= i;
		}
		ans ^= now;
	}
	std::cout << ans << std::endl;
	return 0;
}