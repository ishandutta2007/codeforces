#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[5000];
int ans[5000];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		v.push_back(z);
	}
	for (int i = 0; i < num; i++)
	{
		fill(d, d + 5000, 0);
		int maxi = 0, rr = -1;
		for (int j = i; j < num; j++)
		{
			d[v[j]]++;
			if (d[v[j]]>maxi)
			{
				maxi = d[v[j]];
				rr = v[j];
			}
			else if (d[v[j]] == maxi)
			{
				if (rr > v[j])rr = v[j];
			}
			ans[rr]++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}