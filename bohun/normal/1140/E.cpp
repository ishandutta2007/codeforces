#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int dp[200005][2];
const int mod = 998244353;
int n, k, t[200005], d[200005];
int m = 0;
void add(ll &a, ll b)
{
	a += b;
	if(a >= mod)
		a -= mod;
}
int daj(int lewo, int prawo)
{
	int len = prawo - lewo + 1;
	if(d[lewo] != -1 && d[prawo] != -1)
	{
		if(d[lewo] == d[prawo])
			return dp[len - 2][0];
		return dp[len - 2][1];
	}
	if(d[lewo] == -1 && d[prawo] == -1)
	{
		if(len == 3)
			return 3;
		ll ans = 0;
		add(ans, (ll) k * dp[len - 4][0] % mod);
		add(ans, (ll) k * (k - 1) % mod * dp[len - 4][1] % mod);
		return ans;
	}
		return( (ll) dp[len - 3][0] + (ll) (k - 1) * dp[len - 3][1]) % mod;
}
int solve()
{
	--m;
	int j = 1;
	for(int i = 1; m >= i; ++i)
		if(d[i] != -1 && d[i] == d[i + 1])
			return 0;
	int ans = 1;
	for(int i = 1; m >= i;)
	{
		j = i;
		if(d[j] != -1)
			{
				++i;
				continue;
			}
		while(j + 1 <= m && d[j + 1] == -1)
			++j;
		ans = (ll) ans * daj(i - 1, j + 1) % mod;
		i = j + 1;
	}
	return ans;
}
		
int main()
{
	scanf("%d %d", &n ,&k);
	dp[0][0] = 0;
	dp[0][1] = 1;
	for(int i = 1; 200000 >= i; ++i)
	{
		dp[i][0] = (ll) (k - 1) * dp[i - 1][1] % mod;
		dp[i][1] = ((ll) dp[i - 1][0] + (ll) (k - 2) * dp[i - 1][1]) % mod;
	}
	t[0] = -1;
	t[n + 1] = -1;
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	if(k == 1)
	{
		cout << 0;
		return 0;
	}
	ll ans = 0;
	d[0] = -1;
	for(int i = 1; n >= i; i += 2)
		d[++m] = t[i];
	d[++m] = -1;
	ans = solve();
	m = 0;
	for(int i = 2; n >= i; i += 2)
		d[++m] = t[i];
	d[++m] = -1;
	ans = (ll) ans * solve() % mod;
	printf("%lld", ans);
	return 0;
}