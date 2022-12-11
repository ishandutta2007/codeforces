#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, a[MaxN], b[MaxN];
std::vector<int> G[MaxN];
int64_t dp[MaxN];

struct Line
{
	int64_t k, b;
	Line(int64_t _k = 0, int64_t _b = std::numeric_limits<int64_t>::max()):
		k(_k), b(_b) {}
	int64_t operator() (int64_t x) const {return k * x + b;}
}s[MaxN];

int cnt, rt[MaxN], ls[MaxN], rs[MaxN];

#define Mid (L + (R - L) / 2)
void Insert(int &o, Line t, int L = -1e5, int R = 1e5)
{
	if(!o) o = ++cnt;
	if(t(Mid) < s[o](Mid)) std::swap(s[o], t);
	if(L == R) return;
	if(t(L) < s[o](L)) Insert(ls[o], t, L, Mid);
	if(t(R) < s[o](R)) Insert(rs[o], t, Mid + 1, R);
}

int Merge(int o1, int o2, int L = -1e5, int R = 1e5)
{
	if(!o1 || !o2) return o1 + o2;
	ls[o1] = Merge(ls[o1], ls[o2], L, Mid);
	rs[o1] = Merge(rs[o1], rs[o2], Mid + 1, R);
	Insert(o1, s[o2], L, R);
	return o1;
}

int64_t Query(int o, int x, int L = -1e5, int R = 1e5)
{
	int64_t res = s[o](x);
	if(L == R) return res;
	if(x <= Mid) res = std::min(res, Query(ls[o], x, L, Mid));
	else res = std::min(res, Query(rs[o], x, Mid + 1, R));
	return res;
}
#undef Mid

int main()
{
	std::cin >> n;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 1; i <= n; ++i) std::cin >> b[i];
	for(int i = 1, u, v; i < n; ++i)
	{
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	auto Dfs = [&](auto &&self, int u, int f) -> void
	{
		for(int v : G[u]) if(v != f) self(self, v, u), rt[u] = Merge(rt[u], rt[v]);
		if(f && G[u].size() == 1) dp[u] = 0;
		else dp[u] = Query(rt[u], a[u]);
		Insert(rt[u], Line(b[u], dp[u]));
	};
	
	Dfs(Dfs, 1, 0);
	for(int i = 1; i <= n; ++i) std::cout << dp[i] << " ";
	return 0;
}