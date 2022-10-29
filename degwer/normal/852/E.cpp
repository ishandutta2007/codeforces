#include<stdio.h>
typedef long long ll;
ll mod = 1000000007;
int d[2000000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		d[za]++, d[zb]++;
	}
	ll t = 1;
	for (int i = 0; i < num; i++)if (d[i] != 1)t = t * 2 % mod;
	ll r = 0;
	for (int i = 0; i < num; i++)
	{
		if (d[i] != 1)r += t;
		else r += t + t;
	}
	printf("%I64d\n", r%mod);
}