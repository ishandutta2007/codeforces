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
const int nax = 5005;
const long long inf = 1e18;
int n, ile;
vector <int> v[nax];
int t[nax][2];
ll dp[nax][nax][2];
ll tem[nax][2];
int siz[nax];
void mini(ll &a, ll b)
{
	a = min(a, b);
}
void dfs(int node)
{
	siz[node] = 1;
	dp[node][0][0] = 0;
	dp[node][1][0] = t[node][0];
	dp[node][1][1] = t[node][0] - t[node][1];
	
	for(auto it: v[node])
	{
		dfs(it);
		
		for(int i = 0; min(siz[node], n) >= i; ++i)
			for(int j = 0; siz[it] >= j && i + j <= n; ++j)
				tem[i + j][0] = tem[i + j][1] = inf;
		for(int i = 0; min(siz[node], n) >= i; ++i)
			for(int j = 0; siz[it] >= j && i + j <= n; ++j)
			{
				mini(tem[i + j][0], dp[node][i][0] + dp[it][j][0]);
				mini(tem[i + j][1], dp[node][i][1] + min(dp[it][j][0], dp[it][j][1]));
			}
		for(int i = 0; min(n, siz[node] + siz[it]) >= i; ++i)
			dp[node][i][0] = tem[i][0], dp[node][i][1] = tem[i][1];
		siz[node] += siz[it];
	}
}
				
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> ile;
	for(int i = 1; n >= i; ++i)
		for(int j = 0; n >= j; ++j)
			dp[i][j][0] = dp[i][j][1] = 1e18;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i][0] >> t[i][1];
		if(i > 1)
		{
			int a;
			cin >> a;
			v[a].pb(i);
		}
	}
	dfs(1);
	for(int i = n; i >= 0; --i)
	{
		if(dp[1][i][0] <= ile || dp[1][i][1] <= ile)
		{
			cout << i;
			return 0;
		}
	}
	
	
	return 0;
}