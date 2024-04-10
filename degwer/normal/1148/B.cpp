#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[202020], b[202020];
int main()
{
	int na, nb, gen;
	ll ta, tb;
	scanf("%d%d%I64d%I64d%d", &na, &nb, &ta, &tb, &gen);
	for (int i = 0; i < na; i++)scanf("%I64d", &a[i]);
	for (int i = 0; i < nb; i++)scanf("%I64d", &b[i]);
	ll maxi = 0;
	if (gen >= na || gen >= nb)goto l01;
	for (int i = 0; i <= gen; i++)
	{
		ll low = lower_bound(b, b + nb, a[i] + ta) - b;
		if (low + gen - i >= nb)goto l01;
		maxi = max(maxi, b[low + gen - i] + tb);
	}
	printf("%I64d\n", maxi);
	if (false)
	{
	l01:;
		printf("-1\n");
	}
}