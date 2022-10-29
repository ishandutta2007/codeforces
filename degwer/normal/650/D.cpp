#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
vector<pii>que[400002];
int ans1[400002], ans2[400002];
int d1[400002], d2[400002];
int cnt[400002];
int ret[400002];
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		que[za].push_back(make_pair(zb, i));
	}
	vector<int>lis;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < que[i].size(); j++)
		{
			int low = lower_bound(lis.begin(), lis.end(),que[i][j].first)-lis.begin();
			ans1[que[i][j].second] = low;
		}
		int low = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
		if (low == lis.size())lis.push_back(vec[i]);
		else lis[low] = vec[i];
		d1[i] = low;
	}
	vector<int>lds;
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 0; j < que[i].size(); j++)
		{
			int low = lower_bound(lds.begin(), lds.end(), -que[i][j].first) - lds.begin();
			ans2[que[i][j].second] = low;
		}
		int low = lower_bound(lds.begin(), lds.end(), -vec[i]) - lds.begin();
		if (low == lds.size())lds.push_back(-vec[i]);
		else lds[low] = -vec[i];
		d2[i] = low;
	}/*
	for (int i = 0; i < num; i++)printf("  %d %d\n", d1[i], d2[i]);
	for (int i = 0; i < query; i++)printf("%d %d\n", ans1[i], ans2[i]);*/
	int mx = lis.size();
	for (int i = 0; i < num; i++)
	{
		if (d1[i] + d2[i] == mx - 1)
		{
			cnt[d1[i]]++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < que[i].size(); j++)
		{
			if (d1[i] + d2[i] == mx - 1 && cnt[d1[i]] == 1)
			{
				ret[que[i][j].second] = max(mx - 1, ans1[que[i][j].second] + ans2[que[i][j].second] + 1);
			}
			else
			{
				ret[que[i][j].second] = max(mx, ans1[que[i][j].second] + ans2[que[i][j].second] + 1);
			}
		}
	}
	for (int i = 0; i < query; i++)printf("%d\n", ret[i]);
}