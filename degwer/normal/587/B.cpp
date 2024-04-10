#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 2000000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll dp[3000000];
ll comb0[1000001], comb1[1000001];
typedef pair<int, int>pii;
int main()
{
	invinit();
	ll num, gen, len;
	scanf("%I64d%I64d%I64d", &num, &len, &gen);
	vector<pii>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (i < len%num)vec.push_back(make_pair(z, 1));
		else vec.push_back(make_pair(z, 0));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < num + 1; i++)dp[i] = 1;
	for (int i = 0; i < gen; i++)
	{
		for (int j = 0; j < num; j++)
		{
			int upp = upper_bound(vec.begin(), vec.end(), make_pair(vec[j].first, 2)) - vec.begin() - 1;
			dp[(i + 1)*(num + 1) + j + 1] = (dp[(i + 1)*(num + 1) + j] + dp[i*(num + 1) + upp + 1]) % mod;
		}
	}
	comb0[0] = comb1[0] = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		comb0[i] = (len / num - i + 1) % mod*comb0[i - 1] % mod*inv[i] % mod;
		comb1[i] = (len / num + 1 - i + 1) % mod*comb1[i - 1] % mod*inv[i] % mod;
	}
	ll ans = 0;
	for (int i = 1; i <= gen; i++)
	{
		for (int j = 0; j < num; j++)
		{
			ll t = (mod + dp[i*(num + 1) + j + 1] - dp[i*(num + 1) + j]) % mod;
			//printf("%d %d %I64d\n", i, j, t);
			if (vec[j].second == 0)
			{
				ans += max(0LL, len / num - i + 1) % mod*t;
				ans %= mod;
			}
			else
			{
				ans += max(0LL, len / num + 1 - i + 1) % mod*t;
				ans %= mod;
			}
		}
	}
	printf("%I64d\n", ans);
}