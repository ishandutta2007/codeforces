#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, k;
int a, b, c;
vector <pair<int, int > > v[100005];
const int mod = 1e9 + 7;
int siz[100005], dp[100005];
ll ans = 0;
int pot(int a, int b)
{
	ll h = 1;
	while(b)
	{
		if(b & 1)
			h = (ll) h * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return h;
}
void dfs(int node, int par, int kraw)
{
	dp[node] = 1;
	siz[node] = 1;
	for(auto it: v[node])
	{
		if(it.fi != par)
		{
			dfs(it.fi, node, it.se);
			siz[node] += siz[it.fi];
			if(it.se == 0)
				dp[node] += dp[it.fi];
		}
	}
	if(kraw)
	{
		ans -= pot(dp[node], k);
		if(ans < 0)
			ans += mod;
	}
}
int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; n - 1 > i; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[a].pb({b, c});
		v[b].pb({a, c});
	}
	ans = pot(n, k);
	dfs(1, -1, 1);
	cout << ans;
	
	return 0;
}