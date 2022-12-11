#include <bits/stdc++.h>
const int MaxN = 100123;

using LL = long long;
using Edge = std::tuple<LL, int, int>;

int n, m, U, V;
std::map<std::pair<int, int>, LL> mp;
std::set<Edge> S, T, E[MaxN], min3[MaxN];
std::multiset<LL> sum;
LL W, s3[MaxN];

void maintain(int u)
{
	if(sum.find(s3[u]) != sum.end()) sum.erase(sum.find(s3[u]));
	for(auto e : min3[u]) T.erase(e);
	if(E[u].size() < 3u) min3[u] = E[u], s3[u] = LLONG_MAX;
	else
	{
		s3[u] = 0;
		min3[u].clear();
		auto it = E[u].begin();
		for(int i = 0; i < 3; ++i) s3[u] += std::get<0>(*it), min3[u].insert(*it++);
	}
	sum.insert(s3[u]);
	for(auto e : min3[u])
	{
		int v = std::get<1>(e) + std::get<2>(e) - u;
		if(min3[v].count(e)) T.insert(e);
	}
}

void link(LL w, int u, int v)
{
	E[u].emplace(w, u, v);
	E[v].emplace(w, u, v);
	S.emplace(w, u, v);
	mp.insert({{u, v}, w});
	
	std::tie(W, U, V) = *S.begin();
	maintain(u);
	maintain(v);
}

void cut(int u, int v)
{
	LL w = mp[{u, v}];
	mp.erase({u, v});
	
	E[u].erase(Edge{w, u, v});
	E[v].erase(Edge{w, u, v});
	S.erase(Edge{w, u, v});
	
	std::tie(W, U, V) = *S.begin();
	maintain(u);
	maintain(v);
}

LL query1()
{
	for(auto e : min3[U]) T.erase(e);
	for(auto e : min3[V]) T.erase(e);
	
	LL ans = (T.empty() ? LLONG_MAX : W + std::get<0>(*T.begin()));
	
	for(auto e : min3[U]) T.insert(e);
	for(auto e : min3[V]) T.insert(e);
	
	return ans;
}

int check(std::vector<int> p)
{
	auto c = p.size();
	std::sort(p.begin(), p.end());
	p.erase(std::unique(p.begin(), p.end()), p.end());
	return (p.size() == c ? 1 : 0);
}

LL query2()
{
	LL ans = LLONG_MAX;
	for(auto e1 : min3[U])
	for(auto e2 : min3[V])
	{
		int u1, v1, u2, v2;
		LL w1, w2;
		std::tie(w1, u1, v1) = e1;
		std::tie(w2, u2, v2) = e2;
		if(check({u1, v1, u2, v2})) ans = std::min(ans, w1 + w2);
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) maintain(i);
	for(int i = 1, u, v, w; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		if(u > v) std::swap(u, v);
		link(w, u, v);
	}
	
	#ifdef Dubug
	printf("%lld %lld %lld\n", *sum.begin(), query1(), query2());
	#endif
	
	printf("%lld\n", std::min({*sum.begin(), query1(), query2()}));
	
	int q; scanf("%d", &q);
	while(q--)
	{
		int op, u, v, w;
		scanf("%d%d%d", &op, &u, &v);
		if(u > v) std::swap(u, v);
		
		if(op == 1) scanf("%d", &w), link(w, u, v);
		else cut(u, v);
		
		printf("%lld\n", std::min({*sum.begin(), query1(), query2()}));
	}
	return 0;
}