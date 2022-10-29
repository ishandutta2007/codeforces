#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod;
ll po(ll a, int b)
{
	if (b == 0)return 1LL;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b % 2 == 1)z = z*a%mod;
	return z;
}
vector<int>get(int a)
{
	vector<int>r;
	for (int i = 1;; i++)
	{
		if (i*i > a)break;
		if (a%i == 0)
		{
			r.push_back(i);
			if (i*i != a)r.push_back(a / i);
		}
	}
	return r;
}
int gcd(int a, int b)
{
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
ll dat[3000];
ll ko[3000][2];
int main()
{
	int num, kou;
	scanf("%d%d%I64d", &num, &kou, &mod);
	vector<int>v = get(mod - 1);
	sort(v.begin(), v.end());
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	int g = mod - 1;
	for (int i = 0; i < kou; i++)
	{
		int z;
		scanf("%d", &z);
		g = gcd(g, z);
	}
	int maxi = 0;
	for (int i = 0; i < num; i++)
	{
		int mn = 2000000000;
		for (int j = 0; j < v.size(); j++)
		{
			if (po(po(vec[i], g), v[j]) == 1)
			{
				mn = j;
				break;
			}
		}
		dat[mn] = 1;
	}
	ll ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (dat[i])
		{
			for (int j = 0; j < v.size(); j++)
			{
				int low = lower_bound(v.begin(), v.end(), gcd(v[i], v[j])) - v.begin();
				int t = ko[j][0];
				ko[low][0] += ko[j][1];
				ko[low][1] += t;
				ko[low][0] %= mod;
				ko[low][1] %= mod;
			}
			ko[i][0]++;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		ans += (ko[i][0] - ko[i][1])*v[i];
		ans %= mod;
	}
	printf("%I64d\n", (ans + mod) % mod);
}