#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll len, lb, ub;
	scanf("%I64d%I64d%I64d", &len, &lb, &ub);
	ll siz = 0;
	ll t = len;
	for (;;)
	{
		if (t == 0)break;
		t /= 2;
		siz++;
	}
	ll ans = 0;
	for (ll x = lb; x <= ub; x++)
	{
		ll n = 0;
		for (ll i = 0;; i++)
		{
			if (x&(1LL << i))
			{
				n = i;
				break;
			}
		}
		ans += ((len&(1LL << (siz - 1 - n))) != 0);
	}
	printf("%I64d\n", ans);
}