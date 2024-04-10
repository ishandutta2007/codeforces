#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll d[1010];
int main()
{
	int num;
	ll gen;
	scanf("%d%I64d", &num, &gen);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	int r = 0;
	for (int i = 1; i <= num; i++)
	{
		sort(d, d + i);
		ll s = 0;
		for (int j = 0; j < i / 2; j++)s += d[i - 1 - j * 2];
		if (i % 2 == 1)s += d[0];
		if (s <= gen)r = i;
	}
	printf("%d\n", r);
}