#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std; 
typedef long long ll; 
set<ll> se; 
ll arr[55], dp[21][2520][50]; 
int tot, num[25], idx[2525]; 
ll gcd(ll x, ll y)
{
	if (!y)
		return x; 
	return gcd(y, x % y);
}
ll work(int cnt, int r, int lcm, bool f)
{
	if (cnt > 20)
		return !(r % arr[lcm]); 
	if (f && ~dp[cnt][r][lcm])
		return dp[cnt][r][lcm]; 
	// cout << cnt << " " << r << " " << lcm << " " << f << endl; 
	ll res = 0; 
	for (int i = 0; i <= (f ? 9 : num[cnt]); i++)
		res += work(cnt + 1, ((r << 3) + (r << 1) + i) % 2520, (i ? idx[arr[lcm] / gcd(arr[lcm], i) * i] : lcm)
			, f | (i < num[cnt])); 
	if (f)
		dp[cnt][r][lcm] = res; 
	return res; 
}
int main()
{
	// freopen("55D.in", "r", stdin); 
	for (int i = 0; i < 1 << 9; i++)
	{
		int x = 1; 
		for (int j = 0; j < 9; j++)
		{
			if (i & (1 << j))
				x = x / gcd(x, j + 1) * (j + 1); 
		}
		se.insert(x); 
	}
	for (set<ll>::iterator it = se.begin(); it != se.end(); it++)
	{
		arr[tot] = *it; 
		idx[*it] = tot++; 
	}
	memset(dp, -1, sizeof(dp)); 
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		ll l, r, ans = 0; 
		scanf("%lld%lld", &l, &r); 
		l--; 
		for (int i = 20; i >= 0; i--)
		{
			num[i] = r % 10; 
			r /= 10; 
		}
		ans += work(0, 0, 0, false); 
		for (int i = 20; i >= 0; i--)
		{
			num[i] = l % 10; 
			l /= 10; 
		}
		ans -= work(0, 0, 0, false); 
		printf("%lld\n", ans);
	}
	return 0;
}