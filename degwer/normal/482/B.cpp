#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int imos[40][200000];
int rui[40][200000];
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	vector<pi3>v;
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		for (int j = 0; j < 30; j++)
		{
			if (zc&(1 << j))imos[j][za]++, imos[j][zb + 1]--;
		}
		v.push_back(make_pair(make_pair(za, zb), zc));
	}
	for (int i = 0; i < 30; i++)for (int j = 0; j < num; j++)imos[i][j + 1] += imos[i][j];
	for (int i = 0; i < 30; i++)for (int j = 0; j < num; j++)rui[i][j + 1] = rui[i][j] + (imos[i][j] != 0);
	bool f = true;
	for (int i = 0; i < query; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if ((v[i].second&(1 << j)) == 0)
			{
				if (rui[j][v[i].first.second + 1] - rui[j][v[i].first.first] == v[i].first.second - v[i].first.first + 1)f = false;
			}
		}
	}
	if (!f)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < num; i++)
	{
		int r = 0;
		for (int j = 0; j < 30; j++)if (imos[j][i])r += (1 << j);
		printf("%d ", r);
	}
	printf("\n");
}