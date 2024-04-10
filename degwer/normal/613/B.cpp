#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll ans[100000];
int main()
{
	ll num, gen, c1, c2, mon;
	scanf("%I64d%I64d%I64d%I64d%I64d", &num, &gen, &c1, &c2, &mon);
	vector<pii>vec;
	for (ll i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		vec.push_back(make_pair(z,i));
	}
	sort(vec.begin(), vec.end());
	ll sum = 0;
	for (ll i = 0; i < num; i++)sum += gen - vec[i].first;
	if (sum <= mon)
	{
		printf("%I64d\n", num*c1+gen*c2);
		for (ll i = 0; i < num; i++)
		{
			if (i != 0)printf(" ");
			printf("%I64d", gen);
		}
		printf("\n");
		return 0;
	}
	ll pt = 0;
	ll nowc = 0, nowm = vec[0].first;
	ll maxi = -1, rr = -1, mini = -1, rpt = -1;
	for (ll i = 0; i < num; i++)
	{
		sum -= gen - vec[i].first;
		if (sum <= mon)
		{
			for (;;)
			{
				if (pt == i)break;
				if ((nowc+(vec[pt + 1].first - nowm)*(pt + 1) + sum <= mon))
				{
					nowc += (vec[pt + 1].first - nowm)*(pt + 1);
					nowm = vec[pt + 1].first;
					pt++;
				}
				else
				{
					break;
				}
			}
			if (maxi < c1*(num - 1 - i) + c2*(nowm + (mon - nowc - sum) / (pt + 1)))
			{
				maxi = c1*(num - 1 - i) + c2*(nowm + (mon - nowc - sum) / (pt + 1));
				rr = i;
				rpt = pt;
				mini = nowm + (mon - nowc - sum) / (pt + 1);
			}
		}
	}
	printf("%I64d\n", maxi);
	for (ll i = 0; i <= rpt; i++)ans[vec[i].second] = mini;
	for (ll i = rpt + 1; i <= rr; i++)ans[vec[i].second] = vec[i].first;
	for (ll i = rr + 1; i < num; i++)ans[vec[i].second] = gen;
	for (ll i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		printf("%I64d", ans[i]);
	}
	printf("\n");
}