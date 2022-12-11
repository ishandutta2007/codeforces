#include <bits/stdc++.h>

const int MAXN = 2e5 + 10;
typedef long long LL;
const LL INFL = 0x3f3f3f3f'3f3f3f3fLL;

int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN], tot;
void adde(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	val[tot] = v;
}
int A[MAXN];
LL B[MAXN];

int n, m, Q;

LL bse[MAXN];
struct SS1 {
	LL tag[MAXN << 2], ma[MAXN << 2];
	void mkadd(int u, LL v) {
		ma[u] += v, tag[u] += v;
	}
	void pushdown(int u) {
		if (LL & t = tag[u]) {
			mkadd(u << 1, t);
			mkadd(u << 1 | 1, t);
			t = 0;
		}
	}
	void mdf(int u, int l, int r, int R, LL v) {
	//	if (u == 1)
	//		std::cerr << "ADD " << R << ' ' << v << std::endl;
		if (r <= R) return mkadd(u, v);
		int mid = l + r >> 1;
		pushdown(u);
		mdf(u << 1, l, mid, R, v);
		if (mid < R) mdf(u << 1 | 1, mid + 1, r, R, v);
		ma[u] = std::min(ma[u << 1], ma[u << 1 | 1]);
	}
} s1;
struct SS2 {
	LL ma[MAXN << 2];
	void mdf(int u, int l, int r, int tar) {
		while (true) {
			if (l == r) break;
			int mid = l + r >> 1;
			if (tar <= mid) u <<= 1, r = mid;
			else u = u << 1 | 1, l = mid + 1;
		}
		ma[u] = bse[l] + A[l];
		while (u >>= 1)
			ma[u] = std::min(ma[u << 1], ma[u << 1 | 1]);
	}
} s2;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> Q;
	for (int i = 1; i < n; ++i)
		std::cin >> A[i] >> B[i];
	for (int i = 1, b, e, v; i <= m; ++i)
		std::cin >> b >> e >> v, adde(b, e, v);
	for (int i = n; i; --i)
		s1.mdf(1, 1, n, i, B[i - 1] - B[i]);
	// std::cerr << "DBG: " << s1.ma[1] << std::endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j; j = nxt[j])
			s1.mdf(1, 1, n, to[j], val[j]);
		bse[i] = s1.ma[1];
		s2.mdf(1, 1, n, i);
	}
//	for (int i = 1; i <= n; ++i) std::cout << bse[i] << ' ';
//	std::cout << std::endl;
	std::cout << s2.ma[1] << '\n';
	while (Q --> 0) {
		int x, y;
		std::cin >> x >> y;
		A[x] = y; s2.mdf(1, 1, n, x);
		std::cout << s2.ma[1] << '\n';
	}
	return 0;
}