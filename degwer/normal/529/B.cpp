#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
int main()
{
	int num;
	scanf("%d", &num);
	vector<pii>v;
	int s = 0;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		v.push_back(make_pair(za, zb));
		s += za;
	}
	int mini = 2000000000;
	for (int i = 0; i <= 1000; i++)
	{
		vector<int>z;
		bool f = true;
		int cnt = 0;
		int sum = s;
		for (int j = 0; j < num; j++)
		{
			if (i < v[j].second)
			{
				if (i < v[j].first)f = false;
				else
				{
					cnt++;
					sum += v[j].second - v[j].first;
				}
			}
			else if (v[j].second < v[j].first&&v[j].first <= i)
			{
				z.push_back(v[j].first - v[j].second);
			}
		}
		sort(z.begin(), z.end());
		reverse(z.begin(), z.end());
		if ((!f) || num / 2 < cnt)continue;
		for (int j = 0; j < min(int(z.size()), num / 2 - cnt); j++)sum -= z[j];
		mini = min(mini, sum*i);
	}
	printf("%d\n", mini);
}