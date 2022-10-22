#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<long long> arr(MAXN);
vector<int> par(MAXN);

int find(int u)
{
	if (par[u] == u)
		return u;
	return par[u] = find(par[u]);
}

bool merge(int u, int v)
{
	u = find(u), v = find(v);
	if (u == v)
		return false;
	par[u] = v;
	return true;
}

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);
	int r = 0;
	arr[0] = LLONG_MAX;
	for (int x = 1; x <= n; x++)
	{
		scanf("%lli", &arr[x]);
		if (arr[x] < arr[r])
			r = x;
	}
	vector<pair<long long, pair<int, int>>> edge;
	for (int x = 0; x < m; x++)
	{
		long long w;
		int a, b;
		scanf("%i%i%lli", &a, &b, &w);
		edge.push_back({w, {a, b}});
	}
	for (int x = 1; x <= n; x++)
	{
		if (x != r)
			edge.push_back({arr[r] + arr[x], {x, r}});
		par[x] = x;
	}
	sort(edge.begin(), edge.end());
	long long ans = 0;
	for (auto &x : edge)
	{
		long long w = x.first;
		int a = x.second.first, b = x.second.second;
		if (merge(a, b))
			ans += w;
	}
	printf("%lli\n", ans);
}