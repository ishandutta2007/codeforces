#include <bits/stdc++.h>

const int MAXN = 200010;
void bye() { std::cout << -1 << std::endl; exit(0); }
int n, m, K;
int L[MAXN], R[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}
int que[MAXN], ind[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K;
	for (int i = 1, t; i <= n; ++i) {
		std::cin >> t;
		if (t) L[i] = R[i] = t;
		else L[i] = 1, R[i] = K;
	}
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, adde(b, e), ++ind[e];
	int he = 1, ta = 0;
	for (int i = 1; i <= n; ++i) if (ind[i] == 0)
		que[++ta] = i;
	while (he <= ta) {
		int t = que[he++];
		for (int i = head[t]; i; i = nxt[i])
			if (!--ind[to[i]])
				que[++ta] = to[i];
	}
	if (ta != n) bye();
	for (int T = 1; T <= n; ++T) {
		int u = que[T];
		for (int i = head[u]; i; i = nxt[i])
			R[to[i]] = std::min(R[to[i]], R[u] - 1);
	}
	for (int T = n; T; --T) {
		int u = que[T];
		for (int i = head[u]; i; i = nxt[i])
			L[u] = std::max(L[u], L[to[i]] + 1);
	}
	for (int i = 1; i <= n; ++i) if (L[i] > R[i]) bye();
	typedef std::pair<int, int> pi;
	std::priority_queue<pi> q;
	static bool vis[MAXN];
	static std::vector<int> mat[MAXN];
	for (int i = 1; i <= n; ++i) mat[R[i]].push_back(i);
	for (int i = K; i; --i) {
		for (auto t : mat[i]) q.emplace(L[t], t);
		bool hav = false;
		while (!q.empty()) {
			int t = q.top().second;
			if (vis[t]) { q.pop(); continue; }
			if (L[t] != i && hav) break;
			hav = true; vis[t] = true;
			q.pop();
			L[t] = i;
			for (int j = head[t]; j; j = nxt[j]) {
				mat[R[to[j]] = std::min(R[to[j]], i - 1)].push_back(to[j]);
				if (R[to[j]] < L[to[j]]) bye();
			}
		}
		if (!hav) bye();
	}
	for (int i = 1; i <= n; ++i) std::cout << L[i] << ' ';
	return 0;
}