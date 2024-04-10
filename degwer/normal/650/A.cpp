#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int, int>pii;
typedef long long ll;
int main()
{
	int num;
	scanf("%d", &num);
	map<int, int>mx, my;
	map<pii, int>ma;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		ma[make_pair(za, zb)]++;
		mx[za]++;
		my[zb]++;
	}
	ll ans = 0;
	map<int, int>::iterator itx = mx.begin();
	for (;;)
	{
		if (itx == mx.end())break;
		ll t = (*itx).second;
		ans += t*(t - 1) / 2;
		itx++;
	}
	map<int, int>::iterator ity = my.begin();
	for (;;)
	{
		if (ity == my.end())break;
		ll t = (*ity).second;
		ans += t*(t - 1) / 2;
		ity++;
	}
	map<pii, int>::iterator it = ma.begin();
	for (;;)
	{
		if (it == ma.end())break;
		ll t = (*it).second;
		ans -= t*(t - 1) / 2;
		it++;
	}
	printf("%I64d\n", ans);
}