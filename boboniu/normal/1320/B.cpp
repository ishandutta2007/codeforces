#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 222222;
int n, m, k, p[maxN], dis[maxN];
vector<int> adj[maxN], adjR[maxN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dis[i] = n + 1;
	}
	int t = 0;
	queue<int> q;
	q.push(p[k - 1]);
	dis[p[k - 1]] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : adj[u])
		{
			if (dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	for (int u = 1; u <= n; u++)
		for (auto v : adj[u])
			if (dis[v] == dis[u] + 1)
				adjR[v].push_back(u);
	int minv = 0, maxv = 0;
	for (int i = 0; i < k - 1; i++)
	{
		if (dis[p[i + 1]] != dis[p[i]] - 1)
		{
			minv += 1;
			maxv += 1;
		}
		else
		{
			if (adjR[p[i]].size() > 1)
				maxv += 1;
		}
	}
	cout << minv << " " << maxv << "\n";
}