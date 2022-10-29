#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[200000];
typedef pair<int, int>pii;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]);
	vector<pii>vec;
	vec.push_back(make_pair(1000000000, -1));
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		for (;;)
		{
			if (vec[vec.size() - 1].first <= zb)vec.pop_back();
			else break;
		}
		vec.push_back(make_pair(zb, za));
	}
	vec.push_back(make_pair(0, -1));
	sort(dat, dat + vec[1].first);
	vector<int>ans;
	for (int i = num - 1; i >= vec[1].first; i--)ans.push_back(dat[i]);
	int beg = 0, end = vec[1].first - 1;
	for (int i = 1; i < vec.size() - 1; i++)
	{
		if (vec[i].second == 1)
		{
			for (int j = 0; j < vec[i].first - vec[i + 1].first; j++)
			{
				ans.push_back(dat[end - j]);
			}
			end -= vec[i].first - vec[i + 1].first;
		}
		else
		{
			for (int j = 0; j < vec[i].first - vec[i + 1].first; j++)
			{
				ans.push_back(dat[beg + j]);
			}
			beg += vec[i].first - vec[i + 1].first;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}