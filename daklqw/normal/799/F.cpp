#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
int n, m;
std::unordered_map<LL, LL> M;
std::unordered_map<LL, int> C;
std::mt19937_64 rd(time(0) + (size_t) new char);
LL pre[MAXN], add[MAXN], pre2[MAXN];
int hav[MAXN];
LL calc(int l) {
	return (LL) l * (l + 1) * (l + 2) / 6;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		int l, r; std::cin >> l >> r; LL v = rd();
		add[l] ^= v;
		pre[l] ^= v, pre[r + 1] ^= v;
		++hav[l], --hav[r + 1];
	}
	for (int i = 1; i <= n; ++i) pre[i] ^= pre[i - 1];
	for (int i = 1; i <= n; ++i) pre2[i] = pre2[i - 1] ^ pre[i];
	LL Ans = n, tag = 0;
	M.rehash(500000), C.rehash(500000);
	for (int i = 1; i <= n; ++i) {
		tag ^= add[i];
		LL now = tag ^ pre[i] ^ pre2[i - 1];
		LL qry = tag ^ pre2[i];
		Ans += (LL) i * C[qry] - M[qry];
		M[now] += i - 1; ++C[now];
	}
	for (int i = 1; i <= n; ++i) hav[i] += hav[i - 1];
	for (int i = 1; i <= n; ) {
		if (hav[i]) { ++i; continue; }
		int j = i;
		while (i <= n && !hav[i]) ++i;
		Ans -= calc(i - j);
	}
	std::cout << Ans << std::endl;
	return 0;
}