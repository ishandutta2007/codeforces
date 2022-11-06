#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#ifdef ONLINE_JUDGE
#define inp_ll(x) scanf("%I64d", &x)
#define put_ll(x) printf("%I64d\n", x)
#define put_ll_space(x) printf("%I64d ", x)
#else
#define inp_ll(x) scanf("%lld", &x)
#define put_ll(x) printf("%lld\n", x)
#define put_ll_space(x) printf("%lld ", x)
#endif
using namespace std;
typedef long long ll;  
int dp[5120][5120]; 
int pre[5120][5120]; 
pair<pair<int, int>, int> edge[5120]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("721C.in", "r", stdin); 
#endif
	int n, m, k; 
	scanf("%d%d%d", &n, &m, &k); 
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &edge[i].first.first, &edge[i].first.second, &edge[i].second); 
		edge[i].first.first--; 
		edge[i].first.second--; 
	}
	memset(dp, 0x3F, sizeof(dp)); 
	dp[0][1] = 0; 
	pre[0][1] = -1; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int u = edge[j].first.first, v = edge[j].first.second, w = edge[j].second; 
			if ((ll)dp[u][i] + w > k)
				continue; 
			if (dp[u][i] + w < dp[v][i + 1])
			{
				dp[v][i + 1] = dp[u][i] + w; 
				pre[v][i + 1] = u; 
			}
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j <= n; j++)
	// 		printf("%d%c", dp[i][j], " \n"[j == n]);
	// }
	int ans = 0; 
	for (int i = 0; i <= n; i++)
	{
		if (dp[n - 1][i] <= k)
			ans = max(ans, i); 
	}
	printf("%d\n", ans);
	vector<int> res; 
	for (int i = n - 1; i; i = pre[i][ans--])
		res.pb(i); 
	printf("1 ");
	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d%c", res[i] + 1, " \n"[!i]);
	return 0; 
}