#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<pii>vec;
	for (int i = 0; i < num; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		vec.push_back(make_pair(za + zc, zb + zd));
	}
	vector<pii>vx, vy;
	for (int i = 0; i < num; i++)
	{
		vx.push_back(make_pair(vec[i].first, i));
		vy.push_back(make_pair(vec[i].second, i));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	ll mini = 4000000000000000000LL;
	for (int i = 0; i <= gen; i++)
	{
		for (int j = 0; j <= gen; j++)
		{
			for (int k = 0; k <= gen; k++)
			{
				for (int l = 0; l <= gen; l++)
				{
					ll xl = vx[i].first, xu = vx[num - 1 - j].first;
					ll yl = vy[k].first, yu = vy[num - 1 - l].first;
					set<ll>se;
					for (int m = 0; m < i; m++)if (vx[m].first < xl)se.insert(vx[m].second);
					for (int m = 0; m < j; m++)if (vx[num - 1 - m].first>xu)se.insert(vx[num - 1 - m].second);
					for (int m = 0; m < k; m++)if (vy[m].first < yl)se.insert(vy[m].second);
					for (int m = 0; m < l; m++)if (vy[num - 1 - m].first>yu)se.insert(vy[num - 1 - m].second);
					if (se.size() <= gen)
					{
						ll tx = max(1LL, (xu - xl) / 2);
						ll ty = max(1LL, (yu - yl) / 2);
						mini = min(mini, tx*ty);
					}
				}
			}
		}
	}
	printf("%I64d\n", mini);
}