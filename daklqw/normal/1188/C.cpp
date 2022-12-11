#include <bits/stdc++.h>

const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
const int MAXN = 1010;
int A[MAXN], hav[100010];
int n, K, pre[MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	std::sort(A + 1, A + 1 + n);
	pre[0][0] = 1;
	for (int i = 1; i * (K - 1) <= 100000; ++i) {
		int cur = 0;
		for (int j = 1; j <= n; ++j) {
			while (cur + 1 < j && A[j] - A[cur + 1] >= i) ++cur;
			pre[j][0] = 1;
			for (int k = 1; k <= K; ++k)
				reduce(pre[j][k] = pre[j - 1][k] + pre[cur][k - 1] - mod);
		}
		hav[i] = pre[n][K];
	}
	int Ans = 0;
	for (int i = 1; i <= 100000; ++i) {
		reduce(hav[i] -= hav[i + 1]);
		reduce(Ans += mul(hav[i], i) - mod);
	}
	std::cout << Ans << std::endl;
	return 0;
}