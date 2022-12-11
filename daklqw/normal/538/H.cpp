#include <bits/stdc++.h>

const int MAXN = 100010;
std::queue<int> q;
void bye() { std::cout << "IMPOSSIBLE" << std::endl; exit(0); }
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int n, m, L, R;
int ls[MAXN], rs[MAXN], col[MAXN];
bool inq[MAXN];
void push(int x) { if (!inq[x]) inq[x] = true, q.push(x); }
void bfs() {
	while (!q.empty()) {
		int t = q.front(); q.pop(); inq[t] = false;
		for (int i = head[t]; i; i = nxt[i])
			if (!col[to[i]]) {
				col[to[i]] = col[t] == 1 ? 2 : 1;
				push(to[i]);
			}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> L >> R >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> ls[i] >> rs[i];
	for (int i = 1, t1, t2; i <= m; ++i)
		std::cin >> t1 >> t2, addedge(t1, t2);
	int lv = *std::max_element(ls + 1, ls + 1 + n);
	int rv = *std::min_element(rs + 1, rs + 1 + n);
	if (lv > R) bye();
	if (lv + rv < L) lv = L - rv;
	if (lv + rv > R) rv = R - lv;
	for (int i = 1; i <= n; ++i) {
		bool c1 = ls[i] <= lv && lv <= rs[i];
		bool c2 = ls[i] <= rv && rv <= rs[i];
		if (!c1 && !c2) bye();
		if (c1 && c2) continue;
		if (c1) col[i] = 1; else col[i] = 2;
		push(i);
	}
	bfs();
	for (int i = 1; i <= n; ++i) if (!col[i]) col[i] = 1, push(i), bfs();
	for (int i = 1; i <= n; ++i)
		for (int j = head[i]; j; j = nxt[j])
			if (col[i] == col[to[j]])
				bye();
	std::cout << "POSSIBLE\n" << lv << ' ' << rv << '\n';
	for (int i = 1; i <= n; ++i)
		std::cout << col[i];
	std::cout << std::endl;
	return 0;
}