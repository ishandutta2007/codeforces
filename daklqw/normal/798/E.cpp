#include <bits/stdc++.h>

const int MAXN = 500010;
const int MAXP = MAXN * 17;
const int MAXE = MAXP * 2;
int head[MAXP], nxt[MAXE], to[MAXE], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}
int dfn[MAXP], low[MAXP], bel[MAXN], t0t, cnt;
int st[MAXP], top, n;
bool ins[MAXP];
void tarjan(int u) {
	ins[st[++top] = u] = true;
	dfn[u] = low[u] = ++t0t;
	for (int i = head[u]; i; i = nxt[i])
		if (!dfn[to[i]]) {
			tarjan(to[i]);
			low[u] = std::min(low[u], low[to[i]]);
		} else if (ins[to[i]]) low[u] = std::min(low[u], dfn[to[i]]);
	if (low[u] == dfn[u]) {
		int v; ++cnt;
		do {
			ins[v = st[top--]] = false;
			if (v <= n) bel[v] = cnt;
		} while (v != u);
	}
}
int A[MAXN];
bool vis[MAXN];
int tr[MAXN], idx;
int rk[MAXN], ansl[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	idx = n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		if (A[i] != -1) vis[A[i]] = true;
	}
	for (int i = 1; i <= n; ++i) tr[i] = ++idx;
	for (int i = 1; i <= n; ++i) if (!vis[i])
		for (int x = i; x <= n; x += x & -x)
			adde(i, tr[x]);
	for (int i = n; i; --i) {
		for (int x = A[i] == -1 ? n : A[i] - 1; x; x &= x - 1)
			adde(tr[x], i);
		if (A[i] != -1) {
			adde(i, A[i]);
			for (int x = A[i]; x <= n; x += x & -x)
				adde(tr[x], ++idx), adde(A[i], tr[x] = idx);
		}
	}
	for (int i = 1; i <= idx; ++i) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; ++i) rk[i] = i;
	std::sort(rk + 1, rk + 1 + n, [] (int a, int b) {
		return bel[a] > bel[b];
	});
	for (int i = 1; i <= n; ++i) ansl[rk[i]] = i;
	for (int i = 1; i <= n; ++i) std::cout << ansl[i] << ' ';
	std::cout << '\n';
	return 0;
}