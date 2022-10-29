#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll nc2[1000001];
int main()
{
	for (ll i = 0; i <= 1000000; i++)nc2[i] = i*(i - 1) / 2;
	ll x00, x01, x10, x11;
	scanf("%I64d%I64d%I64d%I64d", &x00, &x01, &x10, &x11);
	if (x00 + x01 + x10 + x11 == 0)
	{
		printf("0\n");
		return 0;
	}
	ll l0 = lower_bound(nc2, nc2 + 1000000, x00) - nc2, l1 = lower_bound(nc2, nc2 + 1000000, x11) - nc2;
	if (l0 == 0)
	{
		if (l1 == 0)
		{
			if (x01 + x10 == 1)l0 = l1 = 1;
		}
		else
		{
			if (x01 + x10 != 0)l0 = 1;
		}
	}
	else if (l1 == 0)
	{
		if (x01 + x10 != 0)l1 = 1;
	}
	if (nc2[l0] != x00 || nc2[l1] != x11 || x01 + x10 != l0*l1)
	{
		printf("Impossible\n");
		return 0;
	}
	ll mok = x10;
	ll now = l0;
	for (int i = 0; i < l0 + l1; i++)
	{
		if (mok >= now)
		{
			printf("1");
			mok -= now;
		}
		else
		{
			printf("0");
			now--;
		}
	}
	printf("\n");
}