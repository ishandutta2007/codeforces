#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define INF 1000000000000000000LL
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>vx, vy;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		vx.push_back(make_pair(za, zb));
		vy.push_back(make_pair(zb, za));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	ll mx = vx[vx.size() / 2].first, my = vy[vy.size() / 2].first;
	ll sx = 0, sy = 0;
	for (int i = 0; i < vx.size(); i++)sx += abs(vx[i].first - mx);
	for (int i = 0; i < vy.size(); i++)sy += abs(vy[i].first - my);
	if (num % 2 == 0)
	{
		int cnt = 0;
		for (int i = 0; i < num / 2; i++)if (make_pair(vx[i].second, vx[i].first) < vy[num / 2])cnt++;
		if (cnt == 0 || cnt == num / 2)
		{
			printf("%I64d\n", (sx + sy) * 2);
		}
		else
		{
			ll m1 = INF, m2 = INF, m3 = INF, m4 = INF;
			for (int i = 0; i < num / 2; i++)m1 = min(m1, mx - vx[i].first);
			for (int i = num / 2; i < num; i++)m2 = min(m2, vx[i].first - mx);
			for (int i = 0; i < num / 2; i++)m3 = min(m3, my - vy[i].first);
			for (int i = num / 2; i < num; i++)m4 = min(m4, vy[i].first - my);
			printf("%I64d\n", (sx + sy) * 2 - min(m1 + m2, m3 + m4) * 2);
		}
	}
	else
	{
		if (make_pair(vx[num / 2].second, vx[num / 2].first) != vy[num / 2])
		{
			printf("%I64d\n", (sx + sy) * 2);
		}
		else
		{
			int cnt = 0;
			for (int i = 0; i < num / 2; i++)if (make_pair(vx[i].second, vx[i].first) < vy[num / 2])cnt++;
			if (cnt == 0 || cnt == num / 2)
			{
				printf("%I64d\n", (sx + sy) * 2);
			}
			else
			{
				ll m1 = INF, m2 = INF, m3 = INF, m4 = INF;
				for (int i = 0; i < num / 2; i++)m1 = min(m1, mx - vx[i].first);
				for (int i = num / 2 + 1; i < num; i++)m2 = min(m2, vx[i].first - mx);
				for (int i = 0; i < num / 2; i++)m3 = min(m3, my - vy[i].first);
				for (int i = num / 2 + 1; i < num; i++)m4 = min(m4, vy[i].first - my);
				printf("%I64d\n", (sx + sy) * 2 - min(min(m1, m2), min(m3, m4)) * 2);
			}
		}
	}
}