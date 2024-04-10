#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>dat[1000001];
vector<int>ans[1000001];
int main()
{
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = i; j <= 1000000; j += i)
		{
			dat[j].push_back(i);
		}
	}
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (z <= 1000000)ans[z].push_back(i + 1);
	}
	int maxi = 0, rr = 1;
	for (int i = 1; i <= gen; i++)
	{
		int s = 0;
		for (int j = 0; j < dat[i].size(); j++)
		{
			s += ans[dat[i][j]].size();
		}
		if (s > maxi)
		{
			maxi = s;
			rr = i;
		}
	}
	printf("%d %d\n", rr, maxi);
	vector<int>r;
	for (int i = 0; i < dat[rr].size(); i++)for (int j = 0; j < ans[dat[rr][i]].size(); j++)r.push_back(ans[dat[rr][i]][j]);
	sort(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", r[i]);
	}
	printf("\n");
}