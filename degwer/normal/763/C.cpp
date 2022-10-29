#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll mod;
ll po(ll a, ll b)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b & 1)z = z*a%mod;
	return z;
}
ll inv(ll a)
{
	return po(a, mod - 2);
}
int main()
{
	ll num;
	scanf("%I64d%I64d", &mod, &num);
	vector<ll>vec;
	ll sum = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
		sum += z;
		sum %= mod;
	}
	if (vec.size() == 1)
	{
		printf("%I64d 1\n", vec[0]);
		return 0;
	}
	else if (mod == num)
	{
		printf("1 1\n");
		return 0;
	}
	unordered_map<ll, int>ma;
	for (int i = 0; i < num; i++)ma[vec[i]] = 1;
	bool fff = false;
	if (num + num > mod)
	{
		fff = true;
		vec.clear();
		sum = 0;
		for (int i = 0; i < mod; i++)
		{
			ma[i] = 1 - ma[i];
			if (ma[i])vec.push_back(i), sum += i;
			sum %= mod;
		}
	}
	if (vec.size() == 1)
	{
		printf("%I64d 1\n", (vec[0] + 1) % mod);
		return 0;
	}
	for (int i = 0; i < vec.size(); i++)
	{
		ll a = vec[i];
		ll b = (sum*inv(vec.size()) % mod + mod - a)*inv(vec.size() - 1) * 2 % mod;
		if (b == 0)continue;
		int p;
		for (p = 0; p < 100; p++)
		{
			ll r = a + b*(((ll)rand() * 32768 + rand()) % vec.size());
			r %= mod;
			if (!ma[r])break;
		}
		if (p == 100)
		{
			if (!fff)
			{
				printf("%I64d %I64d\n", a, b);
				return 0;
			}
			else
			{
				printf("%I64d %I64d\n", (a + b*vec.size()) % mod, b);
				return 0;
			}
		}
	}
	printf("-1\n");
}