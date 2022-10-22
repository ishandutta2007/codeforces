#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define For(i, n) for(int i = 1; n >= i; ++i)
using namespace std;

const int nax = 200005, mod = 998244353;
int n;
vector <int> v[nax];
int a;
int dp[nax][3];

void dfs(int node)
{
	if(!ss(v[node]))
	{
		dp[node][2] = 1;
		return;
	}
	dp[node][0] = 1;
	for(auto it: v[node])
	{
		dfs(it);
		int x = dp[node][0];
		int y = dp[node][1];
		int z = dp[node][2];
		dp[node][0] = (ll) x * (dp[it][0] + dp[it][2]) % mod;
		dp[node][1] = (ll) x * (dp[it][1] + dp[it][2]) % mod;
		dp[node][1] = (dp[node][1] + (ll) y * (dp[it][0] + dp[it][2])) % mod;
		dp[node][2] = (ll) z * (dp[it][0] + dp[it][2]) % mod;
		dp[node][2] = (dp[node][2] + (ll) (y + z) * (dp[it][1] + dp[it][2])) % mod;
		//cout << it << " " << node << " " << dp[node][0] << " " << dp[node][1] << " " << dp[node][2] << endl;
	}
}
		

int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i = 2; n >= i; ++i)
	{
		cin >> a;
		v[a].pb(i);
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][2]) % mod;
	
	
				
    return 0;
}