#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef bitset<4096>bi;
bi dat[2048];
typedef pair<int, int>pii;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<pii>vec;
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		vec.push_back(make_pair(za, zb));
		dat[za][zb] = 1;
	}
	for (int i = 0; i < num; i++)dat[i][i + num] = true;
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			if (dat[j][i])
			{
				swap(dat[i], dat[j]);
				break;
			}
		}
		for (int j = i + 1; j < num; j++)
		{
			if (dat[j][i])dat[j] ^= dat[i];
		}
	}
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (dat[j][i])dat[j] ^= dat[i];
		}
	}
	/*for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%d", int(dat[i][j + num]));
		}
		printf("\n");
	}*/
	for (int i = 0; i < vec.size(); i++)
	{
		if (dat[vec[i].second][vec[i].first + num])printf("NO\n");
		else printf("YES\n");
	}
}