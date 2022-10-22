#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int dp[1000005][8][8];
int cnt[1000005], n, m;
const int inf = 1e9;
void maxi(int &a, int b)
{
	a = max(a, b);
}
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; n >= i; ++i)
	{
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	for(int i = 0; m >= i; ++i)
		for(int j = 0; 6 >= j; ++j)
			for(int k = 0; 6 >= k; ++k)
				dp[i][j][k] = -inf;
	dp[0][0][0] = 0;
	for(int i = 1; m >= i; ++i)
		for(int j = 0; 6 >= j; ++j)
			for(int k = 0; 6 >= k; ++k)
				for(int ile = 0; 6 >= ile; ++ile)
				{
					if(ile > cnt[i] or dp[i - 1][j][k] == -inf)
						continue;
					int val = min({k, j, ile});
					val = val + (cnt[i] - ile) / 3;
					maxi(dp[i][k - min({k, j, ile})][ile - min({k, j, ile})], dp[i - 1][j][k] + val);
				}
	int ans = 0;
	for(int i = 0; 6 > i; ++i)
		for(int j = 0; 6 > j; ++j)
			maxi(ans, dp[m][i][j]);
	printf("%d", ans);
		
	return 0;
}