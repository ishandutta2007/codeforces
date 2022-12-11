#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
int nxt[MAXN][26], R[MAXN], fail[MAXN], tot, lst;
int sz[MAXN];
void extend(int x) {
	static int now, v, p, t;
	R[now = ++tot] = R[p = lst] + 1; sz[lst = tot] = 1;
	for (; p && !nxt[p][x]; p = fail[p]) nxt[p][x] = now;
	if (!p) fail[now] = 1;
	else {
		t = nxt[p][x];
		if (R[t] == R[p] + 1) fail[now] = t;
		else {
			R[v = ++tot] = R[p] + 1;
			memcpy(nxt[v], nxt[t], 104);
			fail[v] = fail[t], fail[t] = fail[now] = v;
			for (; p && nxt[p][x] == t; p = fail[p]) nxt[p][x] = v;
		}
	}
}
char S[MAXN], T[MAXN];
int n, m;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	lst = tot = 1;
	std::cin >> S; n = strlen(S);
	for (int i = 0; i < n; ++i) extend(S[i] - 'a');
	static int buc[MAXN], rk[MAXN];
	for (int i = 1; i <= tot; ++i) ++buc[R[i]];
	for (int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
	for (int i = tot; i; --i) rk[buc[R[i]]--] = i;
	for (int i = tot; i > 1; --i) {
		const int u = rk[i];
		sz[fail[u]] += sz[u];
	}
	std::cin >> T + 1; m = strlen(T + 1);
	static int fa[MAXN], mi[MAXN];
	for (int i = 1; i <= m; ++i) {
		int now = fa[i - 1];
		while (now && (now + 1 == i || T[i] != T[now + 1])) now = fa[now];
		++now;
		fa[i] = now != i && T[i] == T[now] ? now : 0;
		mi[i] = mi[fa[i]] ? mi[fa[i]] : i;
	}
	int now = 1;
	LL ans = (LL) n * m;
	static int cur[MAXN], isp[MAXN];
	isp[0] = true;
	for (int i = 1; i <= m; ++i) {
		isp[i] = isp[i - 1] && T[i] == S[i - 1];
		cur[i] = now = nxt[now][T[i] - 'a'];
		int p = i - fa[i];
		if (p != i) ans -= sz[cur[p]] - isp[p];
	}
	std::cout << ans << std::endl;
	return 0;
}