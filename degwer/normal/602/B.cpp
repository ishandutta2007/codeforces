#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>dat[110000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat[z - 1].push_back(i);
		dat[z].push_back(i);
	}
	int maxi = 0;
	for (int i = 0; i <= 100000; i++)
	{
		sort(dat[i].begin(), dat[i].end());
		int now = 0;
		int bef = -100;
		for (int j = 0; j < dat[i].size(); j++)
		{
			if (dat[i][j] != bef + 1)now = 1;
			else now++;
			bef = dat[i][j];
			maxi = max(maxi, now);
		}
	}
	printf("%d\n", maxi);
}