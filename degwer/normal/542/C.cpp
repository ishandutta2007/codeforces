#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	if (a == 0)return b;
	if (b == 0)return a;
	for (;;)
	{
		if (a > b)swap(a, b);
		b %= a;
		if (b == 0)return a;
	}
}
int dat[200];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	int maxi = 1;
	ll l = 1;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z - 1);
	}
	for (int i = 0; i < num; i++)
	{
		fill(dat, dat + num, -1);
		int now = i;
		for (int t = 0;; t++)
		{
			if (dat[now] != -1)
			{
				maxi = max(maxi, dat[now]);
				ll g = gcd(l, t - dat[now]);
				l = (l / g)*(t - dat[now]);
				break;
			}
			dat[now] = t;
			now = v[now];
		}
	}
	printf("%I64d\n", ((maxi + l - 1) / l)*l);
}