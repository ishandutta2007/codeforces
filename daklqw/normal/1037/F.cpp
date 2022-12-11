#include <bits/stdc++.h>

const int MAXN = 1000010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int A[MAXN], n, K;
int ST[20][MAXN];
int gma(int l, int r) {
	const int L = std::__lg(r - l + 1);
	return std::max(ST[L][l], ST[L][r - (1 << L) + 1]);
}
struct info {
	int v, L;
} ;
std::vector<info> st[MAXN / 2];
int siz[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K; --K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], ST[0][i] = A[i];
	for (int i = 1; i != 20; ++i)
		for (int j = 1; j + (1 << i) - 1 <= n; ++j)
			ST[i][j] = std::max(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	int ans = 0;
	for (int i = n - K, j = 0; i; --i, ++j) {
		const int now = j % K;
		auto & V = st[now];
		int v = gma(i, i + K), L = 1;
		while (!V.empty()) {
			info t = V.back();
			if (t.v <= v) {
				L += t.L;
				reduce(siz[now] -= mul(t.L, t.v));
				V.pop_back();
			} else break;
		}
		siz[now] = (siz[now] + (LL) L * v) % mod;
		V.push_back((info) {v, L});
		reduce(ans += siz[now] - mod);
	}
	std::cout << ans << std::endl;
	return 0;
}