#include <bits/stdc++.h>

typedef long long LL;
const int MAXN = 1e5 + 10;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
int deg[MAXN];
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
	++deg[b], ++deg[e];
}
bool cant[MAXN];
struct fr { int a, b; } anst[MAXN];
bool operator < (fr x, fr y) {
	return (LL) x.a * y.b > (LL) x.b * y.a;
}
typedef std::pair<fr, int> pi;
std::priority_queue<pi> q;
int cnt[MAXN];
int n, m, K;
int del[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> K;
	for (int i = 1, t; i <= K; ++i)
		std::cin >> t, cant[t] = true;
	for (int i = 1, b, e; i <= m; ++i)
		std::cin >> b >> e, adde(b, e);
	for (int i = 1; i <= n; ++i) if (!cant[i])
		for (int j = head[i]; j; j = nxt[j])
			++cnt[to[j]];
	fr ans = (fr) {1, 1};
	for (int i = 1; i <= n; ++i) if (!cant[i]) {
		fr now = (fr) {cnt[i], deg[i]};
		q.emplace(now, i);
		if (ans < now) ans = now;
	}
	int bak = 0, ansat = 1;
	while (!q.empty()) {
		fr s; int u;
		std::tie(s, u) = q.top(); q.pop();
		if (cant[u]) continue;
		del[++bak] = u; anst[bak] = s;
		if (s < ans) ans = s, ansat = bak;
		for (int i = head[u]; i; i = nxt[i])
			if (!cant[to[i]])
				q.emplace((fr) {--cnt[to[i]], deg[to[i]]}, to[i]);
		cant[u] = true;
	}
	for (int i = bak; i >= ansat; --i)
		cant[del[i]] = false;
	std::vector<int> ansl;
	for (int i = 1; i <= n; ++i) if (!cant[i]) ansl.push_back(i);
	std::cout << ansl.size() << '\n';
	for (auto t : ansl) std::cout << t << ' ';
	return 0;
}