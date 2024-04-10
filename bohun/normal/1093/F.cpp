#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, k, len;
int t[100005];
int pref[100005][101];
int dp[100005][101];
int sum[100005];
const int mod = 998244353;
int fun(int poz, int val)
{
	int lewo = max(1, poz - len + 1);
	return pref[poz][val] - pref[lewo - 1][val] + pref[poz][0] - pref[lewo - 1][0];
}
void add(int &a, int b)
{
	a = ((ll) a + b) % mod;
}
int main()
{
	scanf("%d %d %d", &n, &k, &len);
	for(int i = 1; n >= i; ++i)
		{
			scanf("%d", &t[i]);
			if(t[i] == -1)
				t[i] = 0;
		}
	for(int i = 1; n >= i; ++i)
	{
		for(int j = 0; k >= j; ++j)
			pref[i][j] += pref[i - 1][j];
		pref[i][t[i]]++;
	}
	sum[0] = 1;
	for(int i = 1; n >= i; ++i)
	{
		if(t[i] != 0)
		{
			add(dp[i][t[i]], sum[i - 1]);
			if(fun(i, t[i]) == len)
				add(dp[i][t[i]], -(sum[i - len] - dp[i - len][t[i]]) + mod);
		}
		else
		{
			for(int j = 1; k >= j; ++j)
			{
				add(dp[i][j], sum[i - 1]);
				if(fun(i, j) == len)
					add(dp[i][j], -(sum[i - len] - dp[i - len][j]) + mod);
			}
		}
		for(int j = 1; k >= j; ++j)
			add(sum[i], dp[i][j]);
	}
	int ans = 0;
	for(int j = 1; k >= j; ++j)
		add(ans, dp[n][j]);
	printf("%d", ans);
	
	
	return 0;
}