#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m, k;
int  val[20];
ll cost[20][20];
ll dp[(1 << 20) + 2][20];
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; n > i; ++i)
		scanf("%d", &val[i]);
	for(int i = 1; k >= i; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		cost[a][b] += c;
	}
	for(int i = 0; n > i; ++i)
		dp[(1 << i)][i] = val[i];
	for(int i = 3; (1 << n) > i; ++i)
	{
		if(__builtin_popcount(i) >= 2)
		{
			for(int j = 0; n > j; ++j)
				if((1 << j) & i)
				{
					for(int g = 0; n > g; ++g)
						if(g != j and ((1 << g) & i))
							dp[i][j] = max(dp[i][j], dp[(i ^ (1 << j))][g] + val[j] + cost[g][j]);
				}
		}
	}
	ll ans = 0;
	for(int i = 1; (1 << n) > i; ++i)
	{
		if(__builtin_popcount(i) == m)
			for(int j = 0; n > j; ++j)
				ans = max(ans, dp[i][j]);
	}
	cout << ans;
	return 0;
}