#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll rui[200000];
map<ll, int>ma;
int main()
{
	int num;
	ll kai;
	scanf("%d%I64d", &num, &kai);
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		rui[i + 1] = rui[i] + z;
		ma[rui[i + 1]]++;
	}
	ll ans = 0;
	for (int i = 0; i < num; i++)
	{
		ll now = 1;
		for (;;)
		{
			if (abs(now) > 10000000000000000LL)break;
			ans += ma[rui[i] + now];
			now *= kai;
			if (now == 1)break;
		}
		ma[rui[i + 1]]--;
	}
	printf("%I64d\n", ans);
}