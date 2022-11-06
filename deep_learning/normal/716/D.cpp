#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#ifdef ONLINE_JUDGE
#define inpll(x) scanf("%I64d", &x); 
#define putll(x) printf("%I64d\n", x);
#define putlls(x) printf("%I64d ", x);
#else
#define inpll(x) scanf("%lld", &x); 
#define putll(x) printf("%lld\n", x);
#define putlls(x) printf("%lld ", x);
#endif
using namespace std; 
typedef long long ll;
const ll INF = 1e18; 
vector<pair<int, int> > adj[1024], edge; 
vector<int> adj2[1024]; 
ll len[1024][1024];
int pre[1024]; 
ll dis[1024]; 
int n, m, l, s, t; 
void dij1()
{
	priority_queue<pair<ll, int> > que; 
	que.push(mp(0, s)); 
	memset(dis, 0x3F, sizeof(dis)); 
	dis[s] = 0; 
	while (!que.empty())
	{
		ll d = -que.top().first; 
		int u = que.top().second; 
		que.pop(); 
		if (dis[u] < d)
			continue; 
		for (int i = 0; i < adj[u].size(); i++)
		{
			if (d + adj[u][i].second < dis[adj[u][i].first])
			{
				dis[adj[u][i].first] = d + adj[u][i].second; 
				que.push(mp(-dis[adj[u][i].first], adj[u][i].first)); 
			}
		}
	}
}
bool dij2()
{
	priority_queue<pair<ll, int> > que; 
	que.push(mp(0, s)); 
	memset(dis, 0X3F, sizeof(dis)); 
	dis[s] = 0; 
	while (!que.empty())
	{
		ll d = -que.top().first; 
		int u = que.top().second; 
		que.pop(); 
		if (dis[u] < d)
			continue; 
		for (int i = 0; i < adj2[u].size(); i++)
		{
			if (d + llabs(len[u][adj2[u][i]]) < dis[adj2[u][i]])
			{
				dis[adj2[u][i]] = d + llabs(len[u][adj2[u][i]]); 
				pre[adj2[u][i]] = u; 
				que.push(mp(-dis[adj2[u][i]], adj2[u][i])); 
			}
		}
	}
	if (dis[t] > l)
		return false; 
	int u = t; 
	while (u != s)
	{
		if (len[pre[u]][u] < 0)
		{
			len[pre[u]][u]--; 
			len[u][pre[u]]--; 
		}
		u = pre[u]; 
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (len[i][j] == -1)
				len[i][j] = INF; 
		}
	}
	u = t; 
	while (u != s)
	{
		if (len[pre[u]][u] < 0)
		{
			len[pre[u]][u]++; 
			len[u][pre[u]]++; 
		}
		u = pre[u]; 
	}
	return true; 
}
bool work()
{
	priority_queue<pair<ll, int> > que; 
	que.push(mp(0, s)); 
	memset(dis, 0X3F, sizeof(dis)); 
	dis[s] = 0; 
	while (!que.empty())
	{
		ll d = -que.top().first; 
		int u = que.top().second; 
		que.pop(); 
		if (dis[u] < d)
			continue; 
		for (int i = 0; i < adj2[u].size(); i++)
		{
			if (d + llabs(len[u][adj2[u][i]]) < dis[adj2[u][i]])
			{
				dis[adj2[u][i]] = d + llabs(len[u][adj2[u][i]]); 
				pre[adj2[u][i]] = u; 
				que.push(mp(-dis[adj2[u][i]], adj2[u][i])); 
			}
		}
	}
	if (dis[t] == l)
		return true; 
	int u = t; 
	bool used = true; 
	while (u != s && used)
	{
		if (used && len[pre[u]][u] < 0)
		{
			ll tmp = llabs(len[pre[u]][u]); 
			len[pre[u]][u] = tmp + l - dis[t]; 
			len[u][pre[u]] = tmp + l - dis[t]; 
			used = false; 
		}
		u = pre[u]; 
	}
	return false; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("715D.in", "r", stdin); 
#endif
	scanf("%d%d%d%d%d", &n, &m, &l, &s, &t); 
	// cout << n << " " << m << " " << l << " " << s << " " << t << endl; 
	for (int i = 0; i < m; i++)
	{
		int u, v, w; 
		scanf("%d%d%d", &u, &v, &w); 
		if (w)
		{
			adj[u].pb(mp(v, w)); 
			adj[v].pb(mp(u, w)); 
			adj2[u].pb(v); 
			adj2[v].pb(u); 
			// cout << u << " " << v << endl; 
			len[u][v] = w; 
			len[v][u] = w; 
		}
		else
		{
			adj2[u].pb(v); 
			adj2[v].pb(u); 
			len[u][v] = -1; 
			len[v][u] = -1; 
		}
		edge.pb(mp(u, v)); 
	}
	dij1(); 
	if (dis[t] < l)
	{
		printf("NO\n");
		return 0; 
	}
	if (dis[t] == l)
	{
		printf("YES\n");
		for (int i = 0; i < m; i++)
		{
			printf("%d %d ", edge[i].first, edge[i].second);
			ll d = len[edge[i].first][edge[i].second]; 
			if (d == -1)
				d = INF; 
			putll(d); 
		}
		return 0; 
	}
	bool res = dij2(); 
	if (!res)
	{
		printf("NO\n");
		return 0; 
	}
	while (!work())
		work(); 
	printf("YES\n");
	for (int i = 0; i < m; i++)
	{
		printf("%d %d ", edge[i].first, edge[i].second);
		ll d = llabs(len[edge[i].first][edge[i].second]); 
		putll(d); 
	}
	return 0; 
}