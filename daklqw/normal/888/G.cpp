#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 200010;
const int MAXNODE = MAXN * 32;
typedef long long LL;
int nxt[MAXNODE][2], val[MAXNODE], tot;
int n, sums[MAXN];
void insert(int x, int add) {
	int now = 0;
	for (int i = 31; ~i; --i) {
		const int v = x >> i & 1;
		int & nt = nxt[now][v];
		if (!nt) nt = ++tot;
		now = nt;
		val[now] += add;
	}
}
int query(int x) {
	int res = 0, now = 0;
	for (int i = 31; ~i; --i) {
		int v = x >> i & 1;
		if (!val[nxt[now][v]]) v ^= 1;
		res |= v << i;
		now = nxt[now][v];
	}
	return res;
}
int li[MAXN], fa[MAXN], mn[MAXN], frm[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline bool cmp(int x, int y) { return find(x) < find(y); }
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", sums + i);
	std::sort(sums + 1, sums + 1 + n);
	n = std::unique(sums + 1, sums + 1 + n) - sums - 1;
	for (int i = 1; i <= n; ++i) insert(sums[i], 1);
	for (int i = 1; i <= n; ++i) fa[i] = i, li[i] = i;
	int cnt = 0;
	LL ans = 0;
	while (cnt < n - 1) {
		int cur = 1;
		for (int i = 1; ; ++i) {
			if (find(li[i]) != find(li[i - 1])) {
				for (int j = cur; j < i; ++j) {
					int t = std::lower_bound(sums + 1, sums + 1 + n, query(sums[li[j]])) - sums;
					if (!mn[find(li[j])] || (sums[li[j]] ^ sums[t]) < (sums[frm[find(li[j])]] ^ sums[mn[find(li[j])]])) {
						frm[find(li[j])] = li[j];
						mn[find(li[j])] = t;
					}
				}
				while (cur < i) insert(sums[li[cur++]], 1);
			}
			if (i == n + 1) break;
			insert(sums[li[i]], -1);
		}
		// for (int i = 1; i <= n; ++i) std::cout << sums[li[i]] << " FIND " << sums[mn[li[i]]] << " VAL " << (sums[li[i]] ^ sums[mn[li[i]]]) << std::endl;
		for (int i = 1; i <= n; ++i) {
			const int x = frm[find(li[i])], y = mn[find(li[i])];
			// if (!sums[x] || !sums[y]) continue;
			if (find(x) != find(y)) {
				++cnt;
				ans += sums[x] ^ sums[y];
				fa[find(x)] = find(y);
				// std::cout << "LINK " << sums[x] << " " << sums[y] << std::endl;
			}
		}
		for (int i = 1; i <= n; ++i) mn[i] = 0, frm[i] = 0;
		std::sort(li + 1, li + 1 + n, cmp);
		// std::cout << "OK " << std::endl;
	}
	printf("%lld\n", ans);
	return 0;
}