#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll da[2020], db[2020];
ll ta[2020], tb[2020];
int main()
{
	int na, nb;
	scanf("%d%d", &na, &nb);
	for (int i = 0; i < na; i++)scanf("%I64d", &da[i + 1]), da[i + 1] += da[i];
	for (int i = 0; i < nb; i++)scanf("%I64d", &db[i + 1]), db[i + 1] += db[i];
	ll gen;
	scanf("%I64d", &gen);
	fill(ta, ta + na + 1, 10000000000LL);
	fill(tb, tb + nb + 1, 10000000000LL);
	for (int i = 0; i < na; i++)for (int j = i - 1; j < na; j++)ta[j - i + 1] = min(ta[j - i + 1], da[j + 1] - da[i]);
	for (int i = 0; i < nb; i++)for (int j = i - 1; j < nb; j++)tb[j - i + 1] = min(tb[j - i + 1], db[j + 1] - db[i]);
	int maxi = 0;
	for (int i = 0; i <= na; i++)for (int j = 0; j <= nb; j++)if (gen >= ta[i] * tb[j])maxi = max(maxi, i*j);
	printf("%d\n", maxi);
}