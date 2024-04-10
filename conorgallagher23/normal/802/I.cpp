#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 200005;

int n, len[N], par[N], ch[N][26], tot, lst, root;
int lnk[N], nxt[N], fst[N], sz[N], tote;
char str[N]; ll ans;

int newnode(int l) {
	len[tot] = l; memset(ch[tot], par[tot] = sz[tot] = 0, sizeof(ch[tot]));
	return tot++;
}
void extend(int c) {
	int p = lst, np = newnode(len[p] + 1);
	while (!ch[p][c]) ch[p][c] = np, p = par[p];
	if (p == root && ch[p][c] == np) par[np] = root;
	else {
		int q = ch[p][c];
		if (len[q] == len[p] + 1) par[np] = q;
		else {
			int nq = newnode(len[p] + 1);
			par[nq] = par[q], par[q] = par[np] = nq;
			memcpy(ch[nq], ch[q], sizeof(ch[nq]));
			while (ch[p][c] == q) ch[p][c] = nq, p = par[p];
		}
	}
	sz[lst = np] = 1;
}

void adde(int u, int v) {
	lnk[++tote] = v; nxt[tote] = fst[u]; fst[u] = tote;
}
void DFS(int u) {
	for (int i = fst[u]; i; i = nxt[i]) {
		int v = lnk[i]; DFS(v), sz[u] += sz[v];
	}
	ans += (ll)sz[u] * sz[u] * (len[u] - len[par[u]]);
}

int main() {
	int T = read();
	while (T--) {
		scanf("%s", str + 1); n = strlen(str + 1);
		tot = 0, lst = root = newnode(0);
		for (int i = 1; i <= n; i++) extend(str[i] - 'a');
		for (int i = 0; i < tot; i++) fst[i] = 0; tote = ans = 0;
		for (int i = 1; i < tot; i++) adde(par[i], i);
		DFS(0); printf("%lld\n", ans);
	} 
	return 0;
}