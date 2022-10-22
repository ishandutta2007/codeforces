#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;
int n, m;
int a, b;
const int nax = 300005;
vector <int> v[nax];
int dp[nax], low[nax], h[nax];
int ans = 0;
bool odw[nax];
void dfs(int node, int par)
{
	int p = 0, pp = 0;
	low[node] = h[node];
	odw[node] = 1;
	for(auto it: v[node])
	{
		if(it == par)
			continue;
		if(odw[it])
		{
			low[node] = min(low[node], h[it]);
		}
		else
		{
			h[it] = h[node] + 1;
			dfs(it, node);
			int val = dp[it] + (low[it] == h[it]);
			if(val > p)
				swap(val, p);
			if(val > pp)
				swap(val, pp);
			low[node] = min(low[node], low[it]);
		}
	}
	ans = max(ans, p + pp);
	dp[node] = p;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; m >= i; ++i)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, -1);
	cout << ans << endl;
	
	
	return 0;
}