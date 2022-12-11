#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
typedef long double db;
void gma(LL & x, LL y) { x < y ? x = y : 0; }
int head[MAXN], nxt[MAXN], fa[MAXN];
int n, Q;
int _A[MAXN], _B[MAXN], in[MAXN], out[MAXN], idx;
int A[MAXN], B[MAXN];
void dfs(int u) {
	in[u] = ++idx;
	A[idx] = _A[u], B[idx] = _B[u];
	A[idx] += A[in[fa[u]]], B[idx] += B[in[fa[u]]];
	for (int i = head[u]; i; i = nxt[i]) dfs(i);
	out[u] = idx; B[in[u]] = std::abs(B[in[u]]);
}
int bel[MAXN];
const int BLO = 300;
const int CNT = MAXN / BLO + 3;
LL val(int x, int v) {
	return (LL) std::abs(A[x] + v) * B[x];
}
LL val(int x) {
	return (LL) std::abs(A[x]) * B[x];
}
int ks[MAXN], li[MAXN], st[MAXN]; LL bs[MAXN];
struct Block {
	int L, R;
	int minn, tag;
	std::vector<int> V, b;
	int cur;
	bool cross(int x, int y, int z) {
		int x1 = ks[y] - ks[x], x2 = ks[z] - ks[x];
		LL y1 = bs[y] - bs[x], y2 = bs[z] - bs[x];
		db cr = (db) x1 * y2 - (db) x2 * y1;
		return cr >= -1e-8;
	}
	void rebuild() {
		for (int i = L; i <= R; ++i) A[i] += tag;
		cur = tag = 0;
		minn = 2000000000;
		int bak = 0;
		for (auto t : b) if (A[t] < 0) {
			li[++bak] = t, ks[t] = -B[t], bs[t] = val(t);
			minn = std::min(minn, -A[t]);
		}
		std::reverse(li + 1, li + 1 + bak);
		for (auto t : b) if (A[t] >= 0)
			li[++bak] = t, ks[t] = B[t], bs[t] = val(t);
		int top = 0;
		for (int i = 1; i <= bak; ++i) {
			while (top > 1 && cross(st[top - 1], st[top], li[i])) --top;
			st[++top] = li[i];
		}
		V.clear();
		for (int i = 1; i <= top; ++i) V.push_back(st[i]);
	}
	void init() {
		for (int i = L; i <= R; ++i) b.push_back(i);
		std::sort(b.begin(), b.end(), [] (int a, int b) { return B[a] < B[b]; });
		rebuild();
	}
	void add(int v, int hl = -1, int hr = -1) {
		if (hl == -1 && hr == -1) {
			if ((tag += v) < minn) return ;
			rebuild();
		} else {
			if (hl == -1) hl = L;
			if (hr == -1) hr = R;
			for (int i = hl; i <= hr; ++i) A[i] += v;
			rebuild();
		}
	}
	LL qry(int hl = -1, int hr = -1) {
		if (hl == -1 && hr == -1) {
			const int S = V.size();
			while (cur + 1 < S && val(V[cur], tag) <= val(V[cur + 1], tag))
				++cur;
			return val(V[cur], tag);
		} else {
			LL res = 0;
			if (hl == -1) hl = L;
			if (hr == -1) hr = R;
			for (int i = hl; i <= hr; ++i)
				gma(res, val(i, tag));
			return res;
		}
	}
} blo[CNT];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 2; i <= n; ++i)
		std::cin >> fa[i], nxt[i] = head[fa[i]], head[fa[i]] = i;
	for (int i = 1; i <= n; ++i) std::cin >> _A[i];
	for (int i = 1; i <= n; ++i) std::cin >> _B[i];
	for (int i = 1; i <= n; ++i) {
		bel[i] = (i - 1) / BLO;
		if (!blo[bel[i]].L) blo[bel[i]].L = i;
		blo[bel[i]].R = i;
	}
	dfs(1);
	for (int i = 1; i <= bel[n]; ++i) blo[i].init();
	while (Q --> 0) {
		int opt, v, x;
		std::cin >> opt >> v;
		int l = in[v], r = out[v];
		if (opt == 1) {
			std::cin >> x;
			if (bel[l] != bel[r]) {
				blo[bel[l]].add(x, l);
				for (int i = bel[l] + 1; i < bel[r]; ++i)
					blo[i].add(x);
				blo[bel[r]].add(x, -1, r);
			} else blo[bel[l]].add(x, l, r);
		} else {
			LL ans = 0;
			if (bel[l] != bel[r]) {
				ans = blo[bel[l]].qry(l);
				for (int i = bel[l] + 1; i < bel[r]; ++i)
					gma(ans, blo[i].qry());
				gma(ans, blo[bel[r]].qry(-1, r));
			} else ans = blo[bel[l]].qry(l, r);
			std::cout << ans << '\n';
		}
	}
	return 0;
}