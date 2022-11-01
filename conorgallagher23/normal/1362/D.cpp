#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 500005;

int lnk[N << 1], nxt[N << 1], fst[N], tot;
int n, m, nw[N], ans[N];
map<int, int> vis[N];

void addedge(int u, int v) {
	lnk[++tot] = v; nxt[tot] = fst[u]; fst[u] = tot;
}

struct node {
	int mk, u;
} a[N];
bool cmp(node a, node b) {
	return a.mk < b.mk;
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		addedge(u, v); addedge(v, u);
	}
	for (int i = 1; i <= n; i++) {
		a[i].mk = read(); a[i].u = i;
		nw[i] = 1;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int u = a[i].u;
		while (vis[u][nw[u]]) nw[u]++;
		if (nw[u] != a[i].mk) { printf("-1\n"); return 0; }
		ans[u] = nw[u], vis[u][nw[u]] = 1;
		// printf("%d %d\n", u, nw[u]);
		for (int j = fst[u]; j; j = nxt[j])
			vis[lnk[j]][nw[u]] = 1;
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i].u, " \n" [i == n]);
	return 0;
}