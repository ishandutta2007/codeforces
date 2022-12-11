#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef std::vector<int> VI;
typedef std::pair<int, int> pi;
const int BLO = 310;

std::vector<pi> es[MAXN];
int xs[MAXN], ys[MAXN];
int ansl[MAXN];
std::vector<int> qs[MAXN], cs[MAXN];

int n, m, Q;
std::vector<int> out[MAXN];
int bel[MAXN];
int ta[MAXN];
int li[MAXN << 1], bak;
void bfs(int u, int idx) {
	static std::queue<int> q;
	q.push(u); bel[u] = idx;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		++ta[t]; li[++bak] = t;
		for (int i : out[t])
			if (!bel[i])
				bel[i] = idx, q.push(i);
	}
}
void addcol(int i) {
	for (auto j : es[i]) {
		out[j.first].push_back(j.second);
		out[j.second].push_back(j.first);
	}
}
void delcol(int i) {
	for (auto j : es[i]) {
		out[j.first].clear();
		out[j.second].clear();
		bel[j.first] = 0;
		bel[j.second] = 0;
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1, b, e, v; i <= m; ++i) {
		std::cin >> b >> e >> v;
		es[v].emplace_back(b, e);
		cs[b].push_back(v);
		cs[e].push_back(v);
	}
	std::cin >> Q;
	for (int i = 1; i <= Q; ++i) {
		std::cin >> xs[i] >> ys[i];
		qs[xs[i]].push_back(i);
	}
	for (int i = 1; i <= m; ++i)
		if (es[i].size() >= BLO) {
			int idx = 0;
			addcol(i);
			for (int j = 1; j <= n; ++j)
				if (!bel[j]) bfs(j, ++idx);
			for (int j = 1; j <= Q; ++j)
				ansl[j] += bel[xs[j]] == bel[ys[j]];
			delcol(i);
			memset(bel, 0, sizeof bel);
			bak = 0;
		}
	memset(ta, 0, sizeof ta);
	for (int i = 1; i <= n; ++i) {
		std::sort(cs[i].begin(), cs[i].end());
		cs[i].erase(std::unique(cs[i].begin(), cs[i].end()), cs[i].end());
		for (auto t : cs[i])
			if (es[t].size() < BLO) {
				addcol(t);
				bfs(i, 1);
				delcol(t);
			}
		for (auto t : qs[i]) ansl[t] += ta[ys[t]];
		for (int j = 1; j <= bak; ++j)
			ta[li[j]] = 0;
		bak = 0;
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}