#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int main()
{
	int mx, my, num;
	scanf("%d%d%d", &mx, &my, &num);
	set<ll>sx, sy;
	sx.insert(0);
	sx.insert(mx);
	sy.insert(0);
	sy.insert(my);
	multiset<ll>ax, ay;
	ax.insert(mx);
	ay.insert(my);
	for (int i = 0; i < num; i++)
	{
		char za;
		int zb;
		scanf(" %c%d", &za, &zb);
		if (za == 'V')
		{
			set<ll>::iterator it = sx.lower_bound(zb);
			ll t = *it;
			it--;
			ll s = *it;
			sx.insert(zb);
			ax.erase(ax.find(t - s));
			ax.insert(t - zb);
			ax.insert(zb - s);
		}
		else
		{
			set<ll>::iterator it = sy.lower_bound(zb);
			ll t = *it;
			it--;
			ll s = *it;
			sy.insert(zb);
			ay.erase(ay.find(t - s));
			ay.insert(t - zb);
			ay.insert(zb - s);
		}
		set<ll>::iterator it = ax.end();
		it--;
		ll t = *it;
		it = ay.end();
		it--;
		ll s = *it;
		printf("%I64d\n", s*t);
	}
}