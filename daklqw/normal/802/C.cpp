#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 100;
const int MAXP = MAXN;
const int MAXE = MAXP * 10;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
int head[MAXP], nxt[MAXE], to[MAXE], val[MAXE], cost[MAXE], tot = 1;
void adde(int b, int e, int v, int c) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v; cost[tot] = c;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = 0; cost[tot] = -c;
	// std::cout << "ADDE " << b << ' ' << e << ' ' << v << ' ' << c << std::endl;
}
int S, T, idx;
LL dis[MAXP]; bool inq[MAXP];
std::queue<int> q;
bool bellmanford() {
	memset(dis, 0x3f, idx + 1 << 3);
	inq[S] = true, q.push(S), dis[S] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop(); inq[t] = false;
		for (int i = head[t]; i; i = nxt[i])
			if (val[i] && dis[to[i]] > dis[t] + cost[i]) {
				dis[to[i]] = dis[t] + cost[i];
				if (!inq[to[i]]) {
					inq[to[i]] = true;
					q.push(to[i]);
				}
			}
	}
	return dis[T] != INFL;
}
int dinic(int u, int minv) {
	if (u == T || !minv) return minv;
	int res = 0, t;
	inq[u] = true;
	for (int & i = head[u]; i; i = nxt[i])
		if (val[i] && !inq[to[i]] && dis[to[i]] == dis[u] + cost[i] && 
			(t = dinic(to[i], std::min(minv, val[i])))) {
			val[i] -= t;
			val[i ^ 1] += t;
			res += t;
			minv -= t;
			if (!minv) break;
		}
	inq[u] = false;
	if (!res) dis[u] = INFL;
	return res;
}
LL flow() {
	LL res = 0;
	static int hq[MAXP];
	memcpy(hq, head, idx + 1 << 2);
	int dbg = 0;
	while (bellmanford()) {
		int fl = dinic(S, INF);
		dbg += fl;
		res += fl * dis[T];
		memcpy(head, hq, idx + 1 << 2);
	}
	std::cerr << "FLOW " << dbg << " COST " << res << std::endl;
	return res;
}
int A[MAXN], B[MAXN], n, K, lst[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= n; ++i) std::cin >> B[i];
	S = 0, T = idx = n + 1;
	for (int i = 1; i <= n; ++i)
		adde(i, i + 1, K, 0);
	for (int i = 1; i <= n; ++i) {
		adde(lst[A[i]], i, 1, B[A[i]]);
		lst[A[i]] = i + 1;
	}
	for (int i = 1; i <= n; ++i)
		if (lst[i])
			adde(lst[i], T, 1, 0);
	std::cout << flow() << std::endl;
	return 0;
}