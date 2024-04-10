#include <bits/stdc++.h>

const int MAXN = 3e5 + 10;
const int MAXS = 1e6 + 10;
typedef long long LL;

typedef std::vector<int> VI;
int n, mod, A[MAXN], pre[MAXN];

int ls[MAXN], rs[MAXN], sz[MAXN];
int son[MAXN];
void hld(int u) {
	sz[u] = 1;
	if (ls[u]) hld(ls[u]), sz[u] += sz[ls[u]];
	if (rs[u]) hld(rs[u]), sz[u] += sz[rs[u]];
	if (ls[u] && rs[u]) {
		son[u] = sz[ls[u]] > sz[rs[u]] ? ls[u] : rs[u];
	} else son[u] = ls[u] | rs[u];
}
int havL[MAXS], havR[MAXS];
LL ans;
inline int negative(int x) {
	x = -x;
	return x + (x >> 31 & mod);
}
inline int reduce(int x) {
	return x + (x >> 31 & mod);
}
const int LEFT = 0, RIGHT = 1;
void calcEff(int u, int dta, int typ) {
	if (typ == LEFT) {
		ans += havR[reduce(dta - pre[u - 1])];
	} else {
		ans += havL[reduce(dta + pre[u] - mod)];
	}
}
void calcSubtreeEff(int u, int dta, int typ) {
	calcEff(u, dta, typ);
	if (ls[u]) calcSubtreeEff(ls[u], dta, typ);
	if (rs[u]) calcSubtreeEff(rs[u], dta, typ);
}
void addEff(int u) {
	++havL[pre[u - 1]];
	++havR[negative(pre[u])];
}
void addSubtreeEff(int u) {
	addEff(u);
	if (ls[u]) addSubtreeEff(ls[u]);
	if (rs[u]) addSubtreeEff(rs[u]);
}
void removeSubtreeEff(int u) {
	havL[pre[u - 1]] = 0;
	havR[negative(pre[u])] = 0;
	if (ls[u]) removeSubtreeEff(ls[u]);
	if (rs[u]) removeSubtreeEff(rs[u]);
}
void dfs(int u, int top = true) {
	if (ls[u] && ls[u] != son[u]) dfs(ls[u], true);
	if (rs[u] && rs[u] != son[u]) dfs(rs[u], true);
	if (son[u]) dfs(son[u], false);
	const int tmp = negative(A[u] % mod);
	if (son[u] == rs[u]) {
		calcEff(u, tmp, LEFT);
		addEff(u);
		if (ls[u] && ls[u] != son[u]) {
			calcSubtreeEff(ls[u], tmp, LEFT);
			addSubtreeEff(ls[u]);
		}
	} else {
		if (ls[u] && ls[u] != son[u]) {
			calcSubtreeEff(ls[u], tmp, LEFT);
			addSubtreeEff(ls[u]);
		}
		calcEff(u, tmp, RIGHT);
		addEff(u);
		if (rs[u] && rs[u] != son[u]) {
			calcSubtreeEff(rs[u], tmp, RIGHT);
			addSubtreeEff(rs[u]);
		}
	}
	if (top)
		removeSubtreeEff(u);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> mod;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		pre[i] = (pre[i - 1] + A[i]) % mod;
	}
	static int st[MAXN], top;
	for (int i = 1; i <= n; ++i) {
		int lst = 0;
		while (top && A[st[top]] <= A[i])
			rs[st[top]] = lst, lst = st[top--];
		ls[i] = lst;
		st[++top] = i;
	}
	int lst = 0;
	while (top)
		rs[st[top]] = lst, lst = st[top--];
	hld(lst); dfs(lst);
	std::cout << ans << std::endl;
	return 0;
}