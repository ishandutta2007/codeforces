#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;

const int nax = 100005, mod = 998244353;
const ll  inf = 1e18;

int n, m;
vector <pair<int, int>> v[nax];
int a, b, c;
int h[nax];
int lca[nax][17];
ll sum[nax];
bool odw[nax];
vector <int> zle;


void dfs(int node, int par)
{
	odw[node] = 1;
	for(auto it: v[node])
	{
		int u = it.fi;
		if(odw[u] && u != par && h[node] > h[u])
		{
			zle.pb(node);
		}
		else if(odw[u] == 0)
		{
			sum[u] = sum[node] + it.se;
			h[u] = h[node] + 1;
			lca[u][0] = node;
			dfs(u, node);
		}
	}
}
int daj(int x, int y)
{
	if(h[y] > h[x])
		swap(x, y);
	for(int i = 16; 0 <= i; --i)
	{
		if(h[x] - (1 << i) >= h[y])
		{
			x = lca[x][i];
		}
	}
	if(x == y)
		return x;
	for(int i = 16; 0 <= i; --i)
	{
		if(lca[x][i] != lca[y][i])
		{
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	return lca[x][0];
}
ll dis(int x, int y)
{
	return sum[x] + sum[y] - 2 * sum[daj(x, y)];
}
priority_queue <pair<ll, int>> q;
ll dik[nax][25];
bool byl[nax];
void bfs(int node, int id)
{
	for(int i = 1; n >= i; ++i)
		dik[i][id] = inf, byl[i] = 0;
	dik[node][id] = 0;
	q.push({0, node});
	while(!q.empty())
	{
		pair <ll, int> x = q.top();
		q.pop();
		if(byl[x.se])
			continue;
		byl[x.se] = 1;
		for(auto it: v[x.se])
		{
			if(dik[it.fi][id] > dik[x.se][id] + it.se)
			{
				dik[it.fi][id] = dik[x.se][id] + it.se;
				q.push({-dik[it.fi][id], it.fi});
			}
		}
	}
}
		

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)
	{
		cin >> a >> b >> c;
		v[a].pb({b, c});
		v[b].pb({a, c});
	}
	dfs(1, 0);
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
		{
			lca[i][j] = lca[lca[i][j - 1]][j - 1];
		}
	int g = 0;
	for(auto it: zle)
		bfs(it, g++);
	int q;
	cin >> q;
	while(q--)
	{
		cin >> a >> b;
		ll maxi = dis(a, b);
		for(int i = 0; i < g; ++i)
			maxi = min(maxi, dik[a][i] + dik[b][i]);
		cout << maxi << endl;
	}
		
	
	
	return 0;
}