#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;

void adde(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}

int rt1, rt2;
LL ans = 0;
int sz[MAXN];
int n;
void dfs(int u, int f = 0) {
	sz[u] = 1;
	int ma = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != f) {
			dfs(to[i], u);
			ans += (LL) 2 * val[i] * std::min(sz[to[i]], n - sz[to[i]]);
			sz[u] += sz[to[i]];
			ma = std::max(ma, sz[to[i]]);
		}
	ma = std::max(ma, n - sz[u]);
	if (ma <= n / 2) {
		if (rt1) rt2 = u; else rt1 = u;
	}
}
typedef std::set<int> S;
typedef std::pair<int, int> pi;
typedef std::set<pi> HS;
S ss[MAXN];
HS all, zero, liq;
int bel[MAXN];
void dfs2(int u, int b, int f) {
	bel[u] = b;
	ss[b].insert(u);
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != f)
			dfs2(to[i], b, u);
}
int cnt[MAXN];
int cur;
void push(int x) {
	if (cnt[x] <= cur) {
		// std::cout << "ZERO INS " << x << std::endl;
		zero.emplace(*ss[x].begin(), x);
	} else
		all.emplace(*ss[x].begin(), x);

}
void upd(int x) {
	if (!ss[x].empty()) {
		push(x);
		liq.emplace(cnt[x], x);
	}
}
void movcur() {
	++cur;
	while (!liq.empty()) {
		auto it = liq.begin();
		if (it->first <= cur) {
			// std::cout << "MOVCUR UPD " << it->first << std::endl;
			push(it->second);
			liq.erase(it);
		} else break;
	}
}
bool judge(pi x) {
	int a = x.second;
	return !ss[a].empty() && *ss[a].begin() == x.first;
}
pi find(HS & s, int B, bool nmt) {
	auto it = s.begin();
	while (true) {
		if (it == s.end()) return std::make_pair(-1, -1);
		if (!judge(*it)) {
			s.erase(it++);
			continue;
		}
		if (!nmt && it->second == B) {
			++it;
			continue;
		}
		auto res = *it;
		s.erase(it);
		return res;
	}
}
int ansl[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e, v; i < n; ++i)
		std::cin >> b >> e >> v, adde(b, e, v);
	dfs(1);
	std::cout << ans << std::endl;
	int toc = 0;
	if (rt1 && rt2) {
		dfs2(rt1, 1, rt2);
		dfs2(rt2, 2, rt1);
		toc = 2;
	} else {
		ss[1].insert(rt1);
		bel[rt1] = toc = 1;
		for (int i = head[rt1]; i; i = nxt[i])
			dfs2(to[i], ++toc, rt1);
	}
	for (int i = 1; i <= toc; ++i)
		cnt[i] = n - ss[i].size() * 2;
	if (!rt2) ++cnt[1];
	for (int i = 1; i <= toc; ++i) upd(i);
	for (int i = 1; i <= n; ++i) {
		bool nmt = !rt2 && i == rt1;
		pi it;
		while (true) {
			it = find(zero, bel[i], nmt);
			if (it.first == -1) break;
			if (cnt[it.second] <= cur) break;
		}
		if (it.first == -1) it = find(all, bel[i], nmt);
		assert(it.first != -1);
		int v, tp;
		tp = it.second, v = it.first;
		ansl[i] = v;
		ss[tp].erase(v);
		movcur();
		++cnt[tp], ++cnt[bel[i]];
		upd(tp), upd(bel[i]);
	//	for (int j = 1; j <= toc; ++j)
	//		std::cout << cnt[j] - cur << ' ';
	//	std::cout << std::endl;
	//	std::cout << "DBG" << std::endl;
	}
	for (int i = 1; i <= n; ++i) std::cout << ansl[i] << ' ';
	return 0;
}