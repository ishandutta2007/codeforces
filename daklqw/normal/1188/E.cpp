#include <bits/stdc++.h>

const int MAXN = 100010;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
const int MAXS = 2000010;
int fac[MAXS], inv[MAXS];
int C(int a, int b) { return a < b ? 0 : (LL) fac[a] * inv[b] % mod * inv[a - b] % mod; }
int A[MAXN], n, used[MAXN];
std::vector<int> clr[MAXS];
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXS; ++i) inv[i] = mul(inv[i - 1], inv[i]);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> A[i], clr[A[i]].push_back(i);
	int must = 0, uc = 0, Ans = 1;
	for (int i = 1; ; ++i) {
		for (auto t : clr[i - 1]) {
			++must, clr[i - 1 + n].push_back(t);
			if (!used[t]) used[t] = true, ++uc;
		}
		if (must > i || uc == n) break;
		reduce(Ans += C(i - must + n - 1, n - 1) - mod);
		reduce(Ans -= C(i - must + uc - 1, n - 1));
	}
	std::cout << Ans << std::endl;
	return 0;
}