#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, k;
int dp[2005], dp2[2005];
const int mod = 1e9 + 7;
int main()
{	
	scanf("%d %d", &n, &k);
	for(int i = 1; n >= i; ++i)
		dp[i] = 1;
	for(int i = 2; k >= i; ++i)
		{
			for(int j = 1; n >= j; ++j)
				dp2[j] = 0;
			for(int j = 1; n >= j; ++j)
				for(int g = j; n >= g; g+= j)
					dp2[g] = (dp[j] + dp2[g]) % mod;
			for(int j = 1; n >= j; ++j)
				dp[j] = dp2[j];
		}
	ll ans = 0;
	for(int i = 1; n >= i; ++i)
		ans += dp[i];
	cout << ans % mod;
	
}