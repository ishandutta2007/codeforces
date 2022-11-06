#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
bool np[5000005]; 
int ans[5000005], mn[5000005], tot; 
int main()
{
	// freopen("822D.in", "r", stdin); 
	for (int i = 2; i < 5000005; i++)
	{
		if (np[i])
			continue; 
		for (int j = i + i; j < 5000005; j += i)
		{
			if (np[j])
				continue; 
			np[j] = true; 
			mn[j] = i; 
		}
	}
	for (int i = 2; i < 5000005; i++)
	{
		if (!np[i])
			ans[i] = (ll)i * (i - 1) / 2 % MOD; 
		else
			ans[i] = ((ll)ans[mn[i]] * i / mn[i] + ans[i / mn[i]]) % MOD; 
	}
	int t, l, r;
	scanf("%d%d%d", &t, &l, &r); 
	ll cur = 1, res = 0; 
	for (int i = l; i <= r; i++, cur = cur * t % MOD)
		res = (res + cur * ans[i] % MOD) % MOD; 
	printf("%lld\n", res);
	return 0; 
}