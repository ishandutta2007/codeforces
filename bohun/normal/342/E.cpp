#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n, q;
const int nax = 1e5+9, inf = 1e9;
vector <int> v[nax];
int a, b;
int h[nax], lca[nax][17];
int dp[nax], c[nax], p[nax], mini[nax];
int nn;
void dfs(int u, int p)
{
	for(auto w: v[u])
	{
		if(w!=p)
		{
			h[w] = h[u] + 1;
			lca[w][0] = u;
			dfs(w, u);
		}
	}
}
int daj(int x, int y)
{
	if(h[x] < h[y])
		swap(x, y);
	for(int i = 16; i >= 0; --i)
		if(h[x] - (1 << i) >= h[y])
			x = lca[x][i];
	if(x == y)
		return x;
	for(int i = 16; i >= 0 ; --i)
		if(lca[x][i] != lca[y][i])
			x = lca[x][i], y = lca[y][i];	
	return lca[x][0];
}
int dis(int x, int y)
{
	return h[x] + h[y] - 2 * h[daj(x, y)];
}
void go(int u, int prev)
{
	nn++;
	dp[u] = 1;
	for(auto w: v[u])
		if(w != prev and c[w] == 0)
			{
				go(w, u);
				dp[u] += dp[w];
			}
}
int cc(int u, int prev)
{
	for(auto w: v[u])
	{
		if(w != prev and !c[w] and dp[w] > nn / 2)
			return cc(w, u);
	}
	return u;
}		
void dec(int u, int prev)
{
	nn = 0;
	go(u, 0);
	int cen = cc(u, -1);
	c[cen] = 1;
	p[cen] = prev;
	for(auto w: v[cen])
	{
		if(!c[w])
			dec(w,cen);
	}
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 0; n - 1 > i; i++)
		{
			cin >> a >> b; 
			v[a].push_back(b);
			v[b].push_back(a);
		}
	dfs(1, -1);
	for(int j = 1; 16 >= j; ++j)
		for(int i = 1; n >= i; ++i)
			lca[i][j] = lca[lca[i][j-1]][j-1];
	dec(1, 0);
	fill(mini + 1, mini + n + 1, inf);
	int e = 1;
	while(e)
	{
		mini[e] = min(mini[e], dis(1, e));
		e = p[e];
	}
	for(int i = 1; q >= i; ++i)
	{
		cin >> a >> b;
		if(a == 1)
		{
			int w = b;
			while(w)
			{
				mini[w] = min(mini[w], dis(w, b));
				w = p[w];
			}
		}
		else
		{
			int ans = inf;
			int w = b;
			while(w)
			{
				ans = min(ans, mini[w] + dis(w, b));
				w = p[w];
			}
			cout << ans << endl;
		}
	}
	return 0;	
}