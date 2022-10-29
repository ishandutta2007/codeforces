#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int qs[200000][2];
int rui[300000];
int main()
{
	int query, num, len, gen;
	scanf("%d%d%d%d", &query, &num, &len, &gen);
	for (int i = 0; i < query; i++)scanf("%d%d", &qs[i][0], &qs[i][1]);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	v.push_back(0);
	v.push_back(len);
	sort(v.begin(), v.end());
	vector<int>d;
	for (int i = 1; i < v.size(); i++)d.push_back(v[i] - v[i - 1]);
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); i++)rui[i + 1] = rui[i] + d[i];
	int mini = 2100000000;
	for (int i = 0; i < query; i++)
	{
		if (d[d.size() - 1]>qs[i][1])continue;
		int g = qs[i][1] / 2;
		int upp = upper_bound(d.begin(), d.end(), g) - d.begin() - 1;
		int ans = rui[upp + 1] + 3 * (rui[d.size()] - rui[upp + 1]) - qs[i][1] * (d.size() - upp - 1);
		if (ans <= gen)mini = min(mini, qs[i][0]);
	}
	if (mini == 2100000000)printf("-1\n");
	else printf("%d\n", mini);
}