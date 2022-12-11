#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

const int MAXN = 400010;
typedef long long LL;
int tot, n, w;
template<int base, int mod> struct Hasher {
	inline int mul(const int x, const int y) { return static_cast<LL> (x) * y % mod; }
	inline int up(const int x) { return x >= mod ? x - mod : x; }
	inline int down(const int x) { return x < 0 ? x + mod : x; }
	int pows[MAXN], pre[MAXN];
	void build(int * buf, int len) {
		pows[0] = 1;
		for (int i = 1; i <= len; ++i) {
			pre[i] = up(mul(pre[i - 1], base) + down(buf[i]));
			pows[i] = mul(pows[i - 1], base);
		}
	}
	int getHash(int l, int r) {
		return up(pre[r] + mod - mul(pre[l - 1], pows[r - l + 1]));
	}
} ;
Hasher<17, 998244353> A, B;
Hasher<23, 1000000007> C, D;
int a[MAXN], b[MAXN];
int main() {
	scanf("%d%d", &n, &w);
	for (int i = 0; i != n; ++i) scanf("%d", &a[i]);
	for (int i = n - 1; i; --i) a[i] -= a[i - 1];
	A.build(a, n - 1); C.build(a, n - 1);
	for (int i = 0; i != w; ++i) scanf("%d", &b[i]);
	for (int i = w - 1; i; --i) b[i] -= b[i - 1];
	B.build(b, w - 1); D.build(b, w - 1);
	int ans = 0;
	const int Bh = B.getHash(1, w - 1), Dh = D.getHash(1, w - 1);
	for (int i = 1; i + w - 2 <= n - 1; ++i) 
		ans += 	A.getHash(i, i + w - 2) == Bh && 
				C.getHash(i, i + w - 2) == Dh;
	printf("%d\n", ans);
	return 0;
}