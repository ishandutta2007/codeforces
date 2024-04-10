#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define SIZE 300
int pat[100000];
ll dat[100000];
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
int flag[100000];
ll mini[100000], maxi[100000];
ll deg[100000];
ll now[100000];
ll pl[100000];
#define INF 1000000000000000000LL
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		dat[i] = z;
	}
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		pat[i] = z;
		deg[i]++;
		deg[z]++;
	}
	for (int p = 0; p < query; p += SIZE)
	{
		vector<pi3>vec;
		for (int i = 0; i < min(SIZE, query - p); i++)
		{
			int z;
			scanf("%d", &z);
			if (z == 1)
			{
				int za, zb;
				scanf("%d%d", &za, &zb);
				za--;
				zb--;
				vec.push_back(make_pair(1, make_pair(za, zb)));
			}
			else if (z == 2)
			{
				int za;
				scanf("%d", &za);
				za--;
				vec.push_back(make_pair(2, make_pair(za, 0)));
			}
			else vec.push_back(make_pair(3, make_pair(0, 0)));
		}
		fill(flag, flag + num, 0);
		vector<int>look1;
		vector<int>look2;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].first == 1)
			{
				int s = vec[i].second.first, t1 = vec[i].second.second, t2 = pat[vec[i].second.first];
				flag[s] = max(flag[s], 1);
				flag[pat[t1]] = max(flag[pat[t1]], 1);
				flag[pat[t2]] = max(flag[pat[t2]], 1);
				flag[t1] = max(flag[t1], 2);
				flag[t2] = max(flag[t2], 2);

			}
		}
		for (int i = 0; i < num; i++)
		{
			if (flag[i] != 0)look1.push_back(i);
			if (flag[i] == 2)look2.push_back(i);
		}
		ll max1 = -INF, min1 = INF;
		fill(maxi, maxi + num, -INF);
		fill(mini, mini + num, INF);
		fill(now, now + num, 0);
		fill(pl, pl + num, 0);
		for (int i = 0; i < num; i++)
		{
			now[i] += dat[i] - (dat[i] / (deg[i] + 1))*deg[i];
			now[pat[i]] += dat[i] / (deg[i] + 1);
			now[i] += dat[pat[i]] / (deg[pat[i]] + 1);
		}
		for (int i = 0; i < num; i++)
		{
			pl[i] = now[i] - dat[pat[i]] / (deg[pat[i]] + 1);
			if (flag[i]==0)
			{
				if (flag[pat[i]]==2)
				{
					maxi[pat[i]] = max(maxi[pat[i]], now[i] - dat[pat[i]] / (deg[pat[i]] + 1));
					mini[pat[i]] = min(mini[pat[i]], now[i] - dat[pat[i]] / (deg[pat[i]] + 1));
				}
				else
				{
					max1 = max(max1, now[i]);
					min1 = min(min1, now[i]);
				}
			}
		}
		//for (int i = 0; i < num; i++)printf("%I64d %I64d %d\n", dat[i], now[i], flag[i]);
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].first == 1)
			{
				int s = vec[i].second.first, t1 = pat[vec[i].second.first], t2 = vec[i].second.second;
				now[t1] -= dat[t1] - (dat[t1] / (deg[t1] + 1))*deg[t1];
				now[t2] -= dat[t2] - (dat[t2] / (deg[t2] + 1))*deg[t2];
				now[t1] -= dat[s] / (deg[s] + 1);
				for (int j = 0; j < look1.size(); j++)
				{
					if (pat[look1[j]] == t1 || pat[t1] == look1[j])
					{
						now[look1[j]] -= dat[t1] / (deg[t1] + 1);
					}
					if (pat[look1[j]] == t2 || pat[t2] == look1[j])
					{
						now[look1[j]] -= dat[t2] / (deg[t2] + 1);
					}
				}
				//for (int j = 0; j < num; j++)printf("%I64d ", now[j]); printf("\n");
				deg[t1]--;
				deg[t2]++;
				now[t1] += dat[t1] - (dat[t1] / (deg[t1] + 1))*deg[t1];
				now[t2] += dat[t2] - (dat[t2] / (deg[t2] + 1))*deg[t2];
				now[t2] += dat[s] / (deg[s] + 1);
				pat[s] = t2;
				for (int j = 0; j < look1.size(); j++)
				{
					if (pat[look1[j]] == t1 || pat[t1] == look1[j])
					{
						now[look1[j]] += dat[t1] / (deg[t1] + 1);
					}
					if (pat[look1[j]] == t2 || pat[t2] == look1[j])
					{
						now[look1[j]] += dat[t2] / (deg[t2] + 1);
					}
				}
				//for (int j = 0; j < num; j++)printf("%I64d ", now[j]); printf("\n");
			}
			else if (vec[i].first == 2)
			{
				int t = vec[i].second.first;
				if (flag[pat[t]] == 2 && flag[t] == 0)printf("%I64d\n", pl[t] + dat[pat[t]] / (deg[pat[t]] + 1));
				else printf("%I64d\n", now[t]);
			}
			else
			{
				ll mx = max1, mn = min1;
				for (int i = 0; i < look1.size(); i++)
				{
					mx = max(mx, now[look1[i]]);
					mn = min(mn, now[look1[i]]);
				}
				for (int i = 0; i < look2.size(); i++)
				{
					mx = max(mx, maxi[look2[i]] + dat[look2[i]] / (deg[look2[i]] + 1));
					mn = min(mn, mini[look2[i]] + dat[look2[i]] / (deg[look2[i]] + 1));
				}
				printf("%I64d %I64d\n", mn, mx);
			}
		}
	}
}