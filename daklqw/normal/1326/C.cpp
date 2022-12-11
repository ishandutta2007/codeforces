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
const int MAXN = 200010;
int n, K, A[MAXN], at[MAXN];
bool mark[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	LL a1 = 0;
	mark[0] = mark[n + 1] = true;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], at[A[i]] = i;
	for (int i = n, j = K; j; --j, --i)
		mark[at[i]] = true, a1 += i;
	int lst = 0, ans = 1;
	for (int i = 1; i <= n + 1; ++i) {
		if (mark[i]) {
			int L = i - lst - 1;
			if (lst == 0 || i == n + 1) ;
			else ans = mul(ans, L + 1);
			lst = i;
		}
	}
	std::cout << a1 << ' ' << ans << '\n';
	return 0;
}