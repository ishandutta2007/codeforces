#include <bits/stdc++.h>

const int MAXN = 100010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int n, Q;
std::vector<int> qrys[MAXN];
int ls[MAXN], ansl[MAXN], A[MAXN];
int suc[MAXN], pw2[MAXN];
int get(int l, int r) {
	return (suc[l] + (LL) (mod - suc[r + 1]) * pw2[r - l + 1]) % mod;
}
int fa[MAXN], siz[MAXN], sm[MAXN], smmod[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
const int inf = 1e9;
int pre[MAXN], str[MAXN], top;
void merge(int x, int y) {
	if (siz[x] >= 30 || (sm[x] + ((LL) sm[y] << siz[x])) >= inf)
		sm[y] = inf;
	else sm[y] = sm[x] + (sm[y] << siz[x]);
	smmod[y] = ((LL) smmod[y] * pw2[siz[x]] + smmod[x]) % mod;
	str[--top] = y;
	reduce(pre[top] = pre[top - 1] + smmod[y] - mod);
	siz[y] += siz[x]; fa[x] = y;
}
int main() {
	*pw2 = 1;
	for (int i = 1; i != MAXN; ++i)
		reduce(pw2[i] = pw2[i - 1] * 2 - mod);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= n; ++i) smmod[i] = remod(sm[i] = A[i]);
	for (int i = n; i; --i)
		suc[i] = remod(suc[i + 1] * 2ll + A[i]);
	for (int i = 1, r; i <= Q; ++i)
		std::cin >> ls[i] >> r, qrys[r].push_back(i);
	for (int i = 1; i <= n; ++i) {
		reduce(pre[top + 1] = smmod[i] + pre[top] - mod);
		str[++top] = i;
		while (sm[i] > 0 && siz[i] != i) merge(i - siz[i], i);
		for (auto t : qrys[i]) {
			int r = find(ls[t]);
			int at = std::lower_bound(str + 1, str + 1 + top, r) - str;
			int ans = (get(ls[t], r) + (pre[top] - pre[at] + mod) * 2ll) % mod;
			ansl[t] = ans;
		}
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}