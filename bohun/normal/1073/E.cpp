#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
ll l, r, k;
const int mod = 998244353;
int dp[20][(1 << 10) + 9][2];
int sum[20][(1 << 10) + 9][2];
int pot[20];
void ad(int &a, int b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int add(ll X)
{
	if(X == 0)
		return 0;
	vector < int > dig;
	while(X)
	{
		dig.pb(X % 10);
		X /= 10;
	}
	reverse(dig.begin(), dig.end());
	int n = ss(dig);
	for(int i = 0; n >= i; ++i)
			for(int m = 0; (1 << 10) > m; ++m)
			{
				dp[i][m][0] = sum[i][m][0] = dp[i][m][1] = sum[i][m][1] = 0;
			}
	dp[0][0][1] = 1;
	for(int i = 1; n >= i; ++i)
	{
		int c = dig[i - 1];
		int p = pot[n - i];
		for(int m = 0; (1 << 10) > m; ++m)
			{
					for(int cyf = 0; 10 > cyf; cyf++)
						{
							int nowa = (m | (1 << cyf));
							ad(dp[i][nowa][0], dp[i - 1][m][0]);
							ad(sum[i][nowa][0], (sum[i - 1][m][0] + (ll)p * cyf % mod * dp[i - 1][m][0] % mod) % mod);
						}
					for(int cyf = ((i != 1) ? 0 : 1); c >= cyf; cyf++)
							{
								if(cyf != c)
								{
									int nowa = (m | (1 << cyf));
									ad(dp[i][nowa][0], dp[i - 1][m][1]);
									ad(sum[i][nowa][0], (sum[i - 1][m][1] + (ll)p * cyf % mod * dp[i - 1][m][1] % mod) % mod);
								}
								else
								{
									int nowa = (m | (1 << cyf));
									ad(dp[i][nowa][1], dp[i - 1][m][1]);
									ad(sum[i][nowa][1], (sum[i - 1][m][1] + (ll)p * cyf % mod * dp[i - 1][m][1] % mod) % mod);
								}
							}
			}
	}
	ll ans = 0;
	for(int m = 0; (1 << 10) > m; ++m)
		if(__builtin_popcount(m) <= k)
			ans += sum[n][m][0] + sum[n][m][1];
	return ans % mod;
}
				
int solve(ll x)
{
	ll ans = 0;
	ll g = 9;
	while(x > g)
	{
		ans += add(g);
		if(ans >= mod)
			ans -= mod;
		if(x / 10 <= g)	
			break;
		g *= 10;
		g += 9;
	}
	ans += add(x);
	return ans % mod;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> l >> r >> k;
	pot[0] = 1;
	for(int i = 1; 20 >= i; ++i)
		pot[i] = (ll) pot[i - 1] * 10 % mod;
	cout << (solve(r) - solve(l - 1) + mod) % mod << endl;	
	
	return 0;
}