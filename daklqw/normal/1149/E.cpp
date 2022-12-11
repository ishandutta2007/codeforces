#include <bits/stdc++.h>

const int MAXN = 200010;
int head[MAXN], nxt[MAXN], to[MAXN], ind[MAXN], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; ++ind[e];
}
int A[MAXN], mx[MAXN];
std::set<int> S;
int n, m;
std::queue<int> q; int bfn[MAXN], idx;
int B[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, adde(b, e);
	for (int i = 1; i <= n; ++i) if (!ind[i]) q.push(i);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		bfn[++idx] = t;
		for (int i = head[t]; i; i = nxt[i])
			if (!--ind[to[i]]) q.push(to[i]);
	}
	for (int T = idx; T; --T) {
		const int u = bfn[T];
		for (int i = head[u]; i; i = nxt[i]) S.insert(mx[to[i]]);
		while (S.count(mx[u])) ++mx[u];
		S.clear(); B[mx[u]] ^= A[u];
	}
	int cur = n;
	while (cur >= 0 && !B[cur]) --cur;
	if (cur < 0) return std::cout << "LOSE" << std::endl, 0;
	for (int u = 1; u <= n; ++u) if (mx[u] == cur) {
		if ((A[u] ^ B[cur]) > A[u]) continue;
		A[u] ^= B[cur], B[cur] = 0;
		for (int i = head[u]; i; i = nxt[i])
			A[to[i]] ^= B[mx[to[i]]], B[mx[to[i]]] = 0;
		break;
	}
	std::cout << "WIN" << std::endl;
	for (int i = 1; i <= n; ++i)
		std::cout << A[i] << ' ';
	return 0;
}