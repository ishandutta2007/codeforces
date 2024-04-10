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

const int nax = 405, mod = 1e9 + 7;
const int inf = 1e9;
int n, k;
int a, b;
vector <pair <int, int>> v[nax];
int dp[nax][nax];
vector <int> opt[nax][nax], tem2[nax];
int tem[nax];
int siz[nax];
int num[nax];

void dfs(int node, int par)
{
	siz[node] = 1;
	dp[node][1] = 0;
	for(auto it: v[node])
	{
		if(it.fi == par)
		{
			num[node] = it.se;
			continue;
		}
			
		dfs(it.fi, node);
		
		for(int i = 0; min(k, siz[node] + siz[it.fi]) >= i; ++i)
		{
			tem2[i].clear();
			tem[i] = inf;
		}
		
		for(int i = 0; min(k, siz[node]) >= i; ++i)
		{
			for(int j = 0; i + j <= k && j <= siz[it.fi]; ++j)
			{
				int sum = dp[node][i] + dp[it.fi][j] + (j == 0);
				if(sum < tem[i + j])
				{
					tem[i + j] = sum;
					tem2[i+ j].clear();
					for(auto g: opt[node][i])
						tem2[i + j].pb(g);
					for(auto g: opt[it.fi][j])
						tem2[i + j].pb(g);
					if(j == 0)
						tem2[i + j].pb(it.se);
				}
			}
		}
		for(int i = 0; min(k, siz[node] + siz[it.fi]) >= i; ++i)
		{
			dp[node][i] = tem[i];
			opt[node][i] = tem2[i];
		}
		siz[node] += siz[it.fi];
	}
	
	dp[node][0] = 0;
}
					
				
		
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; n - 1 > i; ++i)
	{
		cin >> a >> b;
		v[a].pb({b, i});
		v[b].pb({a, i});
	}
	for(int i = 1; n >= i; ++i)
		for(int j = 0; k >= j; ++j)
			dp[i][j] = inf;
	dfs(1, 0);
	int best = 1e9;
	int id = -1;
	for(int i = 1; n >= i; ++i)
	{
		int sum = dp[i][k] + (i != 1);
		if(i != 1)
			opt[i][k].pb(num[i]);
		if(sum < best)
		{
			best = sum;
			id = i;
		}
	}
	cout << best << endl;
	for(auto it: opt[id][k])
		cout << it + 1 << " ";
	
	
	return 0;
}