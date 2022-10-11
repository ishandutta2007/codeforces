/*






le
toucan
has
arrived*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = (int)1e9 + 7;
const int MAXN = 5007;
vector<int> g[MAXN];
vector<pair<int, int> > shops[MAXN];
int dist[MAXN];
struct Shop
{
	int dist;
	int cost;
	int have;
	Shop(int _dist, int _cost, int _have)
	{
		dist = _dist;
		cost = _cost;
		have = _have;
	}
};
bool cmpDist(Shop x, Shop y)
{
	return x.dist < y.dist;
}
bool cmpCost(Shop x, Shop y)
{
	return x.cost < y.cost;
}
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int w;
	scanf("%d", &w);
	for (int i = 1; i <= w; i++)
	{
		int c, k, p;
		scanf("%d %d %d", &c, &k, &p);
		shops[c].push_back(make_pair(p, k));
	}
	int qqq;
	scanf("%d", &qqq);
	for (int qq = 1; qq <= qqq; qq++)
	{
		int v, r, cost;
		scanf("%d %d %d", &v, &r, &cost);
		for (int j = 1; j <= n; j++)
		{
			dist[j] = INF;
		}
		dist[v] = 0;
		queue<int> q;
		q.push(v);
		while (!q.empty())
		{
			int vv = q.front();
			q.pop();
			for (int i = 0; i < (int)g[vv].size(); i++)
			{
				int to = g[vv][i];
				if (dist[to] > dist[vv] + 1)
				{
					dist[to] = dist[vv] + 1;
					q.push(to);
				}
			}
		}
		vector<Shop> go;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] < INF)
			{
				for (int j = 0; j < (int)shops[i].size(); j++)
				{
					go.push_back(Shop(dist[i], shops[i][j].first, shops[i][j].second)); 
				}
			}
		}
		sort(go.begin(), go.end(), cmpCost);
		int bl = -1, br = n;
		while (br - bl > 1)
		{
			int bm = (bl + br) / 2;
			int canSpend = cost;
			int bought = 0;
			for (int j = 0; j < (int)go.size(); j++)
			{
				if (go[j].dist > bm) continue;
				int take = min(go[j].have, canSpend / go[j].cost);
				bought += take;
				canSpend -= take * go[j].cost;
			}
			if (bought >= r)
			{
				br = bm;
			}
			else
			{
				bl = bm;
			}
		}
		if (br == n)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", br);
		}
	}
	return 0;
}