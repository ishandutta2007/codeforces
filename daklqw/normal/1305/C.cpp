#include <bits/stdc++.h>

int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
const int MAXN = 200010;
int A[MAXN], n, hav[1010], pre[1010];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> mod;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	std::sort(A + 1, A + 1 + n);
	for (int i = 1; i <= n; ++i) ++hav[A[i] % mod];
	for (int i = 0; i < mod; ++i)
		if (hav[i] > 1)
			return std::cout << 0 << std::endl, 0;
	std::cerr << "A" << std::endl;
	memset(hav, 0, sizeof hav);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0, now = A[i] % mod; j < mod; ++j, reduce(now -= 1))
			reduce(hav[now] += pre[j]);
		++pre[A[i] % mod];
	}
	int ans = 1;
	for (int j = 0; j < mod; ++j)
		ans = pow(j, hav[j], ans);
	std::cout << ans << std::endl;
	return 0;
}