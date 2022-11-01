#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 200005;

int type[N << 1], lnk[N << 1], nxt[N << 1], fst[N], tote;
int n, m, deg[N]; pr ans[N]; bool vis[N];

void adde(int d, int u, int v) {
	type[++tote] = d; lnk[tote] = v; nxt[tote] = fst[u]; fst[u] = tote;
}

int main() {
	int T = read();
	while (T--) {
		n = read(); m = read(); tote = 0;
		for (int i = 1; i <= n; i++) deg[i] = fst[i] = 0, vis[i] = false;
		for (int i = 1; i <= m; i++) {
			int d = read(), u = read(), v = read();
			if (!d) adde(d, u, v), adde(d, v, u);
			else adde(d, u, v), deg[v]++;
		}
		int tp = 0; queue<int> que; while (!que.empty()) que.pop();
		for (int i = 1; i <= n; i++) if (!deg[i]) que.push(i);
		while (!que.empty()) {
			int u = que.front(); que.pop(); vis[u] = true;
			for (int i = fst[u]; i; i = nxt[i]) {
				int v = lnk[i], d = type[i];
				if (vis[v]) continue;
				if (d) {
					deg[v]--; if (!deg[v]) que.push(v);
				}
				ans[++tp] = pr(u, v); 
			}
		}
		if (tp != m) puts("NO");
		else {
			puts("YES");
			for (int i = 1; i <= tp; i++) printf("%d %d\n", ans[i].first, ans[i].second);
		} 
	} 
	return 0;
}