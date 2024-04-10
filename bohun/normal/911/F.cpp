#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n;
int a, b;
vector < int > v[200005];
int lca[200005][20];
int h[200005][2];
queue < int > q;
int X, Y;
ll ans = 0;
int ile[200005];
vector < pair < pair < int ,int > , int > > odp;
int daj(int x, int y)
{
	if(h[x][0] < h[y][0])
		swap(x, y);
	for(int i = 17; i >= 0; --i)
		if(h[x][0] - (1 << i) >= h[y][0])
			x = lca[x][i];
	if(x == y)
		return x;
	for(int i = 17; i >= 0; --i)
		if(lca[x][i] != lca[y][i])
			{
				x = lca[x][i];
				y = lca[y][i];
			}
	return lca[x][0];
}
int dis(int x, int y)
{
	return h[x][0] + h[y][0] - 2 * h[daj(x, y)][0];
}
void dfs(int node, int par, int id)
{
	for(auto it: v[node])
		if(it != par)
			{
				h[it][id] = h[node][id] + 1;
				if(id == 0)
					lca[it][0] = node;
				dfs(it, node, id);
			}
}
bool good(int x)
{
	return dis(X,Y) == dis(x, X) + dis(x, Y);
}
void go(int r)
{
	if(dis(X, r) > dis(Y, r))
		{
			ans += dis(X, r);
			odp.pb({{r, X}, r});
		}
	else
		{
			ans += dis(Y, r);
			odp.pb({{r, Y}, r});
		}
}
int main()
{	
	scanf("%d", &n);
	for(int i = 0; n - 1 > i; ++i)
		{
			scanf("%d %d", &a, &b);
			v[a].pb(b);
			v[b].pb(a);
		}
	dfs(1, -1, 0);
	int naj = 0;
	for(int i = 1; n >= i; ++i)
	{
		if(h[i][0] > naj)
			{
				naj = h[i][0];
				X = i;
			}
	}
	dfs(X, -1, 1);
	naj = 0;
	for(int i = 1; n >= i; ++i)
		if(naj < h[i][1])
			{
				naj = h[i][1];
				Y = i;
			}
	for(int i = 1; 17 >= i; ++i)
		for(int j = 1; n >= j; ++j)
			lca[j][i] = lca[lca[j][i - 1]][i - 1];
	
	for(int i = 1; n >= i; ++i)
		ile[i] = ss(v[i]);
	for(int i = 1; n >= i; ++i)
	{
		if(i != X and i != Y and ile[i] == 1)
			{
				q.push(i);
			}
	}
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		go(node);
		for(auto it: v[node])
			{
				ile[it]--;
				if(ile[it] == 1)
					q.push(it);
			}
	}
	vector < int > ver, k;
	int up = daj(X, Y);
	int node = X;
	while(node != up)
		{
			ver.pb(node);
			node = lca[node][0];
		}
	if(up != X and up != Y)
	ver.pb(up);
	node = Y;
	while(node != up)
		{
			k.pb(node);
			node = lca[node][0];
		}
	reverse(k.begin(), k.end());
	for(auto it: k)
		if(it != Y)
			ver.pb(it);
	for(auto it: ver)
	{
		ans += dis(Y, it);
		odp.pb({{it, Y}, it});
	}
	printf("%lld\n", ans);
	for(auto it: odp)
		printf("%d %d %d \n", it.fi.fi, it.fi.se, it.se);
}