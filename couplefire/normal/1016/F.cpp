#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > > g;
vector<long long> d;
vector<long long> d1;
vector<long long> dn;

int n, q;

bool read()
{
	scanf("%d %d", &n, &q);
	g.resize(n);
	d.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		--x;
		--y;
		g[x].push_back(make_pair(y, w));
		g[y].push_back(make_pair(x, w));
	}
	return true;
}

void dfs(int x, int p = -1, long long dist = 0)
{
	d[x] = dist;
	for (auto e : g[x])
		if (p != e.first)
			dfs(e.first, x, e.second + dist);
}

void solve()
{
	dfs(0);
	d1 = d;
	dfs(n - 1);
	dn = d;
	set<pair<long long, int> > dists_n;
	vector<pair<long long, int> > order;
	for(int i = 0; i < n; i++)
	    order.push_back(make_pair(d1[i] - dn[i], i));
	sort(order.begin(), order.end());
	for(int i = 0; i < n; i++)
	    dists_n.insert(make_pair(dn[i], i));
	vector<int> pos(n);
	for(int i = 0; i < n; i++)
		pos[order[i].second] = i;
	long long T = (long long)(1e18);
	for(int i = 0; i < n; i++)
	{
		int v = order[i].second;
		dists_n.erase(make_pair(dn[v], v));
		for (auto e : g[v])
			if (pos[e.first] > pos[v])
				dists_n.erase(make_pair(dn[e.first], e.first));
		if (!dists_n.empty())
			T = min(T, d1[n - 1] - d1[v] - dists_n.rbegin()->first);
		for (auto e : g[v])
			if (pos[e.first] > pos[v])
				dists_n.insert(make_pair(dn[e.first], e.first));
	}
	for(int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%lld\n", d1[n - 1] - max(0ll, T - x));
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	if (read())
	{
		solve();
	}
}