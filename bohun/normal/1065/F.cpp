#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n, k;
const int nax = 1e6 + 2;
vector <int> v[nax];
int h[nax];
pair <int, int> dp[nax];
void go(int u, int par)
{
	if(ss(v[u]) == 0 and u != 1)
		{
			dp[u] = {1, h[u] - k};
			return ;
		}
	dp[u] = {0, nax + 5};
	for(auto it: v[u])
	{
		h[it] = h[u] + 1;
		go(it, u);
		if(dp[it].se <= h[u])
		{
			dp[u].fi += dp[it].fi;
			dp[u].se = min(dp[u].se, dp[it].se);
		}
	}
}
int ans = 0;
void dfs(int u, int par, int cur)
{
	ans = max(ans, cur + (ss(v[u]) == 0 and u != 1));
	for(auto it: v[u])
		{
			int sum = dp[u].fi;
			if(dp[it].se <= h[u])
				sum -= dp[it].fi;
			dfs(it, u, cur + sum);
		}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	for(int i = 2; n >= i; ++i)
		{
			int a;
			cin >> a;
			v[a].pb(i);
		}
	go(1, -1);
	dfs(1, -1, 0); 
	cout << ans;
	return 0;
}