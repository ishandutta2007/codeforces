#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[200];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]);
	int maxi = -1000000000;
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			vector<int>va, vb;
			for (int k = 0; k < num; k++)
			{
				if (i <= k&&k <= j)va.push_back(dat[k]);
				else vb.push_back(dat[k]);
			}
			sort(va.begin(), va.end());
			sort(vb.begin(), vb.end());
			reverse(vb.begin(), vb.end());
			int sw = min(gen, int(min(va.size(), vb.size())));
			int sum = 0;
			for (int k = 0; k < sw; k++)if (va[k] < vb[k])swap(va[k], vb[k]);
			for (int k = 0; k < va.size(); k++)sum += va[k];
			maxi = max(maxi, sum);
		}
	}
	printf("%d\n", maxi);
}