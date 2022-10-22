#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n;
const int nax = 505;
int e[nax][nax];
ll dp[nax][nax][2];
const int mod = 1e9 + 7;
void add(ll &a, ll b)
{
	a += b;
	if(a >= mod)
		a %= mod;
}
int main()
{
	cin >> n;
	for(int i = 1; n >= i; ++i)
		for(int j = 1; n >= j ;++j)
			cin >> e[i][j];
	for(int s = 0; n > s; ++s)
		for(int i = 1; n >= i && i + s <= n; ++i)
			{
				int right = i + s;
				if(right == i)
				{
					dp[i][right][0] = 1;
					continue;
				}
				if(right == i + 1)
				{
					dp[i][right][0] = dp[i][right][1] = e[i][right];
					continue;
				}
				if(e[i][right])
				{
					for(int j = i; right > j; ++j)
						add(dp[i][right][1],dp[i][j][0] * dp[j+1][right][0]);
				}
				for(int j = i + 1; right > j; ++j)
				{
					add(dp[i][right][0],dp[i][j][1] * dp[j][right][0]);
				}
				add(dp[i][right][0],dp[i][right][1]);		
			}
	cout << dp[1][n][0];
}